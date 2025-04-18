import numpy as np
import pandas as pd
from PIL import Image
from os.path import join
from torchvision.transforms import Compose, Resize, ToTensor, Normalize
import torch
import torchvision.models as models
import torch.nn as nn
import torch.optim as optim
from torch.optim.lr_scheduler import StepLR
from efficientnet_pytorch import EfficientNet
from tqdm import tqdm

class AgeDataset(torch.utils.data.Dataset):
    def __init__(self, data_path, annot_path, train=True):
        super(AgeDataset, self).__init__()

        self.annot_path = annot_path
        self.data_path = data_path
        self.train = train

        self.ann = pd.read_csv(annot_path)
        self.files = self.ann['file_id']
        if train:
            self.ages = self.ann['age']
        self.transform = self._transform(224)

    @staticmethod    
    def _convert_image_to_rgb(image):
        return image.convert("RGB")

    def _transform(self, n_px):
        mean = [0.485, 0.456, 0.406]
        std = [0.229, 0.224, 0.225]
        return Compose([
            Resize(n_px),
            self._convert_image_to_rgb,
            ToTensor(),
            Normalize(mean, std),
        ])

    def read_img(self, file_name):
        im_path = join(self.data_path, file_name)   
        img = Image.open(im_path)
        img = self.transform(img)
        return img

    def __getitem__(self, index):
        file_name = self.files[index]
        img = self.read_img(file_name)
        if self.train:
            age = self.ages[index]
            return img, age
        else:
            return img

    def __len__(self):
        return len(self.files)

class AgePredictionModel(nn.Module):
    def __init__(self):
        super(AgePredictionModel, self).__init__()
        self.base_model = EfficientNet.from_pretrained('efficientnet-b0')
        self.base_model._fc = nn.Linear(self.base_model._fc.in_features, 1)

    def forward(self, x):
        x = self.base_model(x)
        return x.view(x.size(0))

train_path = '/kaggle/input/smai-24-age-prediction/content/faces_dataset/train'
train_ann = '/kaggle/input/smai-24-age-prediction/content/faces_dataset/train.csv'
train_dataset = AgeDataset(train_path, train_ann, train=True)

test_path = '/kaggle/input/smai-24-age-prediction/content/faces_dataset/test'
test_ann = '/kaggle/input/smai-24-age-prediction/content/faces_dataset/submission.csv'
test_dataset = AgeDataset(test_path, test_ann, train=False)

train_loader = torch.utils.data.DataLoader(train_dataset, batch_size=64, shuffle=True)
test_loader = torch.utils.data.DataLoader(test_dataset, batch_size=64, shuffle=False)

device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')

# EfficientNet
model1 = AgePredictionModel().to(device)
optimizer1 = optim.Adam(model1.parameters(), lr=0.001, weight_decay=0.0001)
criterion1 = nn.L1Loss()
scheduler1 = StepLR(optimizer1, step_size=5, gamma=0.05)

# ResNet34
model2 = models.resnet34(pretrained=True)
for param in model2.parameters():
    param.requires_grad = True
num_ftrs = model2.fc.in_features
model2.fc = nn.Linear(num_ftrs, 1)
model2 = model2.to(device)
optimizer2 = optim.SGD(model2.parameters(), lr=0.001, momentum=0.9, weight_decay=0.0005)
criterion2 = nn.L1Loss()

def train_model1(model, train_loader, criterion, optimizer, scheduler, device, num_epochs=15):
    for epoch in range(num_epochs):
        model.train()
        running_loss = 0.0
        for inputs, targets in tqdm(train_loader):
            inputs, targets = inputs.to(device), targets.to(device)
            optimizer.zero_grad()
            outputs = model(inputs)
            loss = criterion(outputs.squeeze(), targets.float())
            loss.backward()
            optimizer.step()
            running_loss += loss.item() * inputs.size(0)
        epoch_loss = running_loss / len(train_loader.dataset)
        print(f"Epoch {epoch+1}/{num_epochs}, Training Loss: {epoch_loss:.4f}")
        scheduler.step()

def train_model2(model, train_loader, criterion, optimizer, device, num_epochs=15):
    for epoch in range(num_epochs):
        model.train()
        running_loss = 0.0
        for inputs, targets in tqdm(train_loader):
            inputs, targets = inputs.to(device), targets.to(device)
            optimizer.zero_grad()
            outputs = model(inputs)
            loss = criterion(outputs.squeeze(), targets.float())
            loss.backward()
            optimizer.step()
            running_loss += loss.item() * inputs.size(0)
        epoch_loss = running_loss / len(train_loader.dataset)
        print(f"Epoch {epoch+1}/{num_epochs}, Training Loss: {epoch_loss:.4f}")

train_model1(model1, train_loader, criterion1, optimizer1, scheduler1, device)
train_model2(model2, train_loader, criterion2, optimizer2, device)

def predict(loader, model):
    model.eval()
    predictions = []
    for img in tqdm(loader):
        img = img.to(device)
        with torch.no_grad():
            pred = model(img)
        predictions.extend(pred.flatten().cpu().numpy().tolist())
    return predictions

preds_model1 = predict(test_loader, model1)
preds_model2 = predict(test_loader, model2)

average_preds = [(pred1 + pred2) / 2 for pred1, pred2 in zip(preds_model1, preds_model2)]


submit = pd.read_csv('/kaggle/input/smai-24-age-prediction/content/faces_dataset/submission.csv')
submit['age'] = average_preds
submit.to_csv('baseline.csv', index=False)
