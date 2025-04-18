

import string
from conllu import parse_incr

# Function to remove punctuations
def remove_punctuations(sentence):
    return sentence.translate(str.maketrans('', '', string.punctuation))

# Function to process the dataset file
def process_file(input_file):
    processed_data = []
    with open(input_file, 'r', encoding='utf-8') as infile:
        for tokenlist in parse_incr(infile):
            sentence_data = []
            for token in tokenlist:
                # Get word index, lowercase word, and POS tag
                word_index = token['id']
                word = token['form'].lower()
                pos_tag = token['upos']

                # Remove punctuations from the word
                word = remove_punctuations(word)

                # Append the processed data to the sentence list
                sentence_data.append((word_index, word, pos_tag))
            processed_data.append(sentence_data)
    return processed_data

# Process the training set
en_atis_train_processed = process_file('en_atis-ud-train.conllu')

# Process the development set
en_atis_dev_processed = process_file('en_atis-ud-dev.conllu')

# Process the test set
en_atis_test_processed = process_file('en_atis-ud-test.conllu')



words_train = [[word[1] for word in sentence] for sentence in en_atis_train_processed]

words_test = [[word[1] for word in sentence] for sentence in en_atis_test_processed]

label_to_number = {}
number_to_label = {}
label_to_number["SYM"] = 13
number_to_label[13] = "SYM"
numeric_label = 0
for sentence in en_atis_train_processed:
    for word in sentence:
        label = word[2]
        if label not in label_to_number:
            label_to_number[label] = numeric_label
            number_to_label[numeric_label] = label
            numeric_label += 1

# Encode labels using numeric labels
labels_train_encoded = [[label_to_number[word[2]] for word in sentence] for sentence in en_atis_train_processed]



# label_to_number1 = {}
# number_to_label1 = {}
# numeric_label1 = 0
# for sentence in en_atis_test_processed:
#     for word in sentence:
#         label = word[2]
#         if label not in label_to_number1:
#             label_to_number1[label] = numeric_label1
#             number_to_label1[numeric_label1] = label
#             numeric_label1 += 1

# Encode labels using numeric labels
labels_test_encoded = [[label_to_number[word[2]] for word in sentence] for sentence in en_atis_test_processed]



s = 2
p = 2
# Add <s> tags to the front and </s> tags to the end of each list
words_train_modified = [['<s>'] * s + [word[1] for word in sentence] + ['</s>'] * p for sentence in en_atis_train_processed]

# Example: Accessing the modified training data


# Add <s> tags to the front and </s> tags to the end of each list
words_test_modified = [['<s>'] * s + [word[1] for word in sentence] + ['</s>'] * p for sentence in en_atis_test_processed]

# Example: Accessing the modified training data


from gensim.models import Word2Vec

# Train Word2Vec model
model = Word2Vec(sentences=words_train_modified, vector_size=100, window=5, min_count=1, workers=4)

# Example: Get word embeddings
word_embedding = model.wv['cost']  # Get the embedding of '<s>' token


import numpy as np

# Set window size
window_size = s + p + 1

# Initialize X_train and Y_train
X_train = []
Y_train = []

# Traverse words_train_modified with the window size
for i, sentence in enumerate(words_train_modified):
    for j in range(len(sentence) - window_size + 1):
        # Extract the context words within the window
        context_words = sentence[j:j+window_size]

        # Obtain word embeddings for context words
        context_embeddings = [model.wv[word] for word in context_words]

        # Append context embeddings to X_train
        X_train.append(context_embeddings)



# Convert lists to numpy arrays
X_train = np.array(X_train)

for index in range(len(en_atis_train_processed)):
    # print(sentence)
    for i in range(len(en_atis_train_processed[index])):

        # Extracting the tag label of the word at the (s+1)th position of the window
        tag_label = label_to_number[en_atis_train_processed[index][i][2]]

        Y_train.append(tag_label)
Y_train = np.array(Y_train)

# Example: Print shapes of X_train and Y_train
#print(X_train)


import numpy as np

# Set window size
window_size = s + p + 1

# Initialize X_train and Y_train
X_test = []
Y_test = []

# Traverse words_train_modified with the window size
embedding_dim = 100  # Assuming each word embedding is of size 100

# Initialize X_test as an empty list


for i, sentence in enumerate(words_test_modified):
    for j in range(len(sentence) - window_size + 1):
        # Extract the context words within the window
        context_words = sentence[j:j+window_size]

        # Obtain word embeddings for context words
        context_embeddings = []
        for word in context_words:
            if word in model.wv:  # Check if the word is in the Word2Vec model's vocabulary
                context_embeddings.append(model.wv[word])
            else:
                # Use a zero vector if the word is not found
                context_embeddings.append(np.zeros(embedding_dim))

        # Flatten the list of embeddings into a single vector
        #flattened_embeddings = np.concatenate(context_embeddings).flatten()

        # Append the flattened embeddings vector to X_test
        X_test.append(context_embeddings)

# Convert X_test to a NumPy array
X_test = np.array(X_test)


for index in range(len(en_atis_test_processed)):
    # print(sentence)
    for i in range(len(en_atis_test_processed[index])):

        # Extracting the tag label of the word at the (s+1)th position of the window
        tag_label = label_to_number[en_atis_test_processed[index][i][2]]

        Y_test.append(tag_label)
Y_test = np.array(Y_test)

# Example: Print shapes of X_train and Y_train
#print(X_train)


import torch
import numpy as np
from torch.utils.data import Dataset, DataLoader, TensorDataset
import torch.nn as nn
import torch.optim as optim

# Assuming X_train and Y_train have been prepared
# Flatten X_train to ensure each input vector is of consistent size
X_train_flattened = np.reshape(X_train, (X_train.shape[0], -1))

Y_train = np.array(Y_train)  # Ensure Y_train is a numpy array

# Convert numpy arrays to PyTorch tensors
X_train_tensor = torch.FloatTensor(X_train_flattened)
Y_train_tensor = torch.LongTensor(Y_train)

# Define the Dataset
class POSDataset(Dataset):
    def __init__(self, X, y):
        self.X = X
        self.y = y

    def __len__(self):
        return len(self.y)

    def __getitem__(self, idx):
        return self.X[idx], self.y[idx]

# Create DataLoader
dataset = TensorDataset(X_train_tensor, Y_train_tensor)
data_loader = DataLoader(dataset, batch_size=64, shuffle=True)

# Neural Network Model
class POSFFNN(nn.Module):
    def __init__(self, input_dim, hidden_dim1, hidden_dim2, output_dim):
        super(POSFFNN, self).__init__()
        # First hidden layer
        self.fc1 = nn.Linear(input_dim, hidden_dim1)
        # Second hidden layer
        self.fc2 = nn.Linear(hidden_dim1, hidden_dim2)
        # Output layer
        self.fc3 = nn.Linear(hidden_dim2, output_dim)

    def forward(self, x):
        # Activation function between the input layer and the first hidden layer
        x = torch.relu(self.fc1(x))
        # Activation function between the first hidden layer and the second hidden layer
        x = torch.relu(self.fc2(x))
        # No activation function is applied to the output layer here
        x = self.fc3(x)
        return x



if __name__ == '__main__':
    # Model, Loss Function, and Optimizer Initialization
    input_dim = X_train_flattened.shape[1]  # Adjust this accordingly
    hidden_dim = 70  # Example hidden layer size, can be adjusted
    output_dim = 14  # Adjust this accordingly

    model1 = POSFFNN(input_dim, 128, hidden_dim, output_dim)
    criterion = nn.CrossEntropyLoss()
    optimizer = optim.Adam(model1.parameters())

    # Training Loop
    epochs = 20
    for epoch in range(epochs):
        model1.train()  # Ensure the model is in training mode
        total_loss = 0
        for inputs, labels in data_loader:
            optimizer.zero_grad()
            outputs = model1(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()
            total_loss += loss.item()
        print(f'Epoch {epoch+1}, Loss: {total_loss / len(data_loader)}')

    torch.save(model1.state_dict(), 'pos_tagging_model.pt')
    print("Model saved to pos_tagging_model.pt")
    X_test_flattened = np.reshape(X_test, (X_test.shape[0], -1))

    Y_test = np.array(Y_test)


    X_test_tensor = torch.FloatTensor(X_test_flattened)  # Assuming X_test is ready
    Y_test_tensor = torch.LongTensor(Y_test)  # Assuming Y_test is ready

    # Create test dataset and DataLoader
    test_dataset = TensorDataset(X_test_tensor, Y_test_tensor)
    test_data_loader = DataLoader(test_dataset, batch_size=64, shuffle=False)

    from sklearn.metrics import f1_score, recall_score, confusion_matrix
    import torch
    import numpy as np

    from sklearn.metrics import f1_score, recall_score, confusion_matrix
    import torch
    import numpy as np

    def evaluate_model(model, data_loader):
        model.eval()  # Set the model to evaluation mode
        all_predicted = []
        all_labels = []
        
        with torch.no_grad():  # No need to track gradients during evaluation
            for inputs, labels in data_loader:
                outputs = model(inputs)
                _, predicted = torch.max(outputs, 1)
                all_predicted.extend(predicted.cpu().numpy())
                all_labels.extend(labels.cpu().numpy())
        
        # Convert all collected predictions and true labels into numpy arrays
        all_predicted = np.array(all_predicted)
        all_labels = np.array(all_labels)
        
        # Calculate metrics
        accuracy = np.mean(all_predicted == all_labels)
        
        f1_macro = f1_score(all_labels, all_predicted, average='macro')
        f1_micro = f1_score(all_labels, all_predicted, average='micro')
        recall = recall_score(all_labels, all_predicted, average='weighted')
        cm = confusion_matrix(all_labels, all_predicted)
        
        return accuracy, f1_macro, f1_micro, recall, cm

    # Usage example (assuming 'model' and 'data_loader' are already defined and ready)
    accuracy, f1_macro, f1_micro, recall, cm = evaluate_model(model1, test_data_loader)
    print(f"Accuracy: {accuracy:.4f}")

    print(f"F1 Score (Macro): {f1_macro:.4f}")
    print(f"F1 Score (Micro): {f1_micro:.4f}")
    print(f"Recall: {recall:.4f}")
    print("Confusion Matrix:")
    print(cm)




# def predict_pos_tags(sentence, model, word_embeddings, label_to_number, number_to_label, p=2, s=3, embedding_dim=100):
#     # Insert s number of '<s>' at the beginning and p number of '</s>' at the end of the sentence
#     modified_sentence = ' '.join(['<s>'] * s + [sentence] + ['</s>'] * p).lower()
#     print(modified_sentence)

#     # Tokenize the modified sentence
#     words = modified_sentence.split()  # Simple tokenization based on spaces and lowercase

#     # Convert words to embeddings
#     sentence_embeddings = []
#     for word in words:
#         if word in word_embeddings:  # Check if the word is in the Word2Vec model's vocabulary
#             sentence_embeddings.append(word_embeddings[word])
#         else:
#             # Use a zero vector if the word is not found or is a token <s> or </s>
#             sentence_embeddings.append(np.zeros(embedding_dim))


#     # Prepare the context windows
#     X = []
#     for i in range(p, len(words) - s):  # Adjust indices to skip added tokens
#         # Context window (p preceding, current word, s succeeding)
#         context_embeddings = sentence_embeddings[i-p:i+1+s]

#         # Flatten context embeddings to create a single input vector
#         flattened_embeddings = np.concatenate(context_embeddings).flatten()
#         X.append(flattened_embeddings)

#     # Convert to tensor
#     X_tensor = torch.FloatTensor(np.array(X))
#     print(len(sentence_embeddings))

#     # Predict
#     model.eval()  # Set the model to evaluation mode
#     with torch.no_grad():
#         outputs = model(X_tensor)
#         _, predicted_indices = torch.max(outputs, 1)

#     # Convert numeric predictions back to POS tags
#     predicted_tags = [number_to_label[idx.item()] for idx in predicted_indices]

#     return predicted_tags

# input_sentence = "Today I went for a walk"
# predicted_tags = predict_pos_tags(input_sentence, model1, model.wv, label_to_number, number_to_label, p=2, s=3, embedding_dim=100)

# print(f"Sentence: {input_sentence}")
# print(f"Predicted POS Tags: {predicted_tags}")