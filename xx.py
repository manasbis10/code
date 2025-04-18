from Q1 import label_to_number
from Q1 import number_to_label
num_unique_tags = 14
from Q1 import model
import torch
import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np
import numpy as np


class POSFFNN(nn.Module):
    def __init__(self, input_dim, hidden_dim1, hidden_dim2, output_dim):
        super(POSFFNN, self).__init__()
        self.fc1 = nn.Linear(input_dim, hidden_dim1)
        self.fc2 = nn.Linear(hidden_dim1, hidden_dim2)
        self.fc3 = nn.Linear(hidden_dim2, output_dim)

    def forward(self, x):
        x = torch.relu(self.fc1(x))
        x = torch.relu(self.fc2(x))
        x = self.fc3(x)
        return x
    
# Assuming you know the input_dim and output_dim
input_dim = 100# The input dimension you used during training
output_dim = num_unique_tags  # The number of unique POS tags

hidden_dim1 = 256
hidden_dim2 = 128

model1 = POSFFNN(input_dim, hidden_dim1, hidden_dim2, output_dim)

model1.load_state_dict(torch.load('pos_tagging_model.pt'))
model1.eval()  # Set the model to evaluation mode



def predict_pos_tags(sentence, model, word_embeddings, label_to_number, number_to_label, p=2, s=3, embedding_dim=100):
    # Insert s number of '<s>' at the beginning and p number of '</s>' at the end of the sentence
    modified_sentence = ' '.join(['<s>'] * s + [sentence] + ['</s>'] * p).lower()
    print(modified_sentence)

    # Tokenize the modified sentence
    words = modified_sentence.split()  # Simple tokenization based on spaces and lowercase

    # Convert words to embeddings
    sentence_embeddings = []
    for word in words:
        if word in word_embeddings:  # Check if the word is in the Word2Vec model's vocabulary
            sentence_embeddings.append(word_embeddings[word])
        else:
            # Use a zero vector if the word is not found or is a token <s> or </s>
            sentence_embeddings.append(np.zeros(embedding_dim))


    # Prepare the context windows
    X = []
    for i in range(p, len(words) - s):  # Adjust indices to skip added tokens
        # Context window (p preceding, current word, s succeeding)
        context_embeddings = sentence_embeddings[i-p:i+1+s]

        # Flatten context embeddings to create a single input vector
        flattened_embeddings = np.concatenate(context_embeddings).flatten()
        X.append(flattened_embeddings)

    # Convert to tensor
    X_tensor = torch.FloatTensor(np.array(X))
    print(len(sentence_embeddings))

    # Predict
    model.eval()  # Set the model to evaluation mode
    with torch.no_grad():
        outputs = model(X_tensor)
        _, predicted_indices = torch.max(outputs, 1)

    # Convert numeric predictions back to POS tags
    predicted_tags = [number_to_label[idx.item()] for idx in predicted_indices]

    return predicted_tags

input_sentence = "Today I went for a walk"
predicted_tags = predict_pos_tags(input_sentence, model1, model.wv, label_to_number, number_to_label, p=0, s=0, embedding_dim=100)

print(f"Sentence: {input_sentence}")
print(f"Predicted POS Tags: {predicted_tags}")

