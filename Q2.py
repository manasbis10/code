
import torch
import numpy as np
from torch.utils.data import Dataset, DataLoader, TensorDataset
import torch.nn as nn
import torch.optim as optim
import string
from conllu import parse_incr
from sklearn.metrics import f1_score, recall_score, confusion_matrix
import torch
import numpy as np
from torch.utils.data import DataLoader, TensorDataset

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
en_atis_test_processed = process_file('en_atis-ud-dev.conllu')



words_train = [[word[1] for word in sentence] for sentence in en_atis_train_processed]

words_test = [[word[1] for word in sentence] for sentence in en_atis_test_processed]



# Step 1: Find the length of the longest sentence
max_sentence_length = max(len(sentence) for sentence in words_train)

# Step 2: Pad all sentences to the length of the longest sentence
words_train_padded = [sentence + ['<pad>'] * (max_sentence_length - len(sentence)) for sentence in words_train]
words_test_padded = [sentence + ['<pad>'] * (max_sentence_length - len(sentence)) for sentence in words_test]

# Example output for verification


# Create word-to-index mapping
unique_words = set(word for sentence in words_train for word in sentence)

unique_words.add('<pad>')
unique_words.add('<unk>')  # Add padding token
word_to_index = {word: idx for idx, word in enumerate(unique_words)}


# Encode words_train_padded using the mapping
words_train_encoded = [[word_to_index[word] for word in sentence] for sentence in words_train_padded]

# Example output




unknown_word_index = len(unique_words)  # Index for unknown words

# Assuming words_test_padded is your test data after padding
# Encode the test data, using the reserved index for unknown words
words_test_encoded = [[word_to_index.get(word, unknown_word_index) for word in sentence] for sentence in words_test_padded]


label_to_number = {}
label_to_number["pad"] = 13
label_to_number["SYM"] = 14
number_to_label = {}
number_to_label[13] = "pad"
number_to_label[14] = "SYM"
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
labels_test_encoded = [[label_to_number[word[2]] for word in sentence] for sentence in en_atis_test_processed]



# Step 2: Pad each list to the maximum length
labels_train_encoded_padded = [tags + [13] * (max_sentence_length - len(tags)) for tags in labels_train_encoded]
labels_test_encoded_padded = [tags + [13] * (max_sentence_length - len(tags)) for tags in labels_test_encoded]




import torch
import torch.nn as nn
import torch.optim as optim

# Assuming unique_words contains all unique words including '<pad>'
vocab_size = len(unique_words) +1

embedding_dim = 100  # Size of the embedding vector

# Initialize embeddings
embedding_matrix = nn.Embedding(num_embeddings=vocab_size, embedding_dim=embedding_dim)

# Convert words_train_encoded to tensor
words_train_encoded_tensor = torch.LongTensor(words_train_encoded)
class POSLSTM(nn.Module):
    def __init__(self, vocab_size, embedding_dim, hidden_dim, output_dim):
        super(POSLSTM, self).__init__()
        self.embedding = nn.Embedding(vocab_size, embedding_dim)
        self.lstm = nn.LSTM(embedding_dim, hidden_dim, batch_first=True)
        self.fc = nn.Linear(hidden_dim, output_dim)

    def forward(self, sentence):
        # Embedding layer
        embedded = self.embedding(sentence)
        # LSTM layer
        lstm_out, _ = self.lstm(embedded)
        # Fully connected layer
        tag_space = self.fc(lstm_out)
        tag_scores = torch.log_softmax(tag_space, dim=-1)
        return tag_scores

if __name__ == '__main__':
    hidden_dim = 256
    output_dim = len(label_to_number)  # Number of unique POS tags

    model = POSLSTM(vocab_size, embedding_dim, hidden_dim, output_dim)
    loss_function = nn.NLLLoss()
    optimizer = optim.Adam(model.parameters(), lr=0.001)
    epochs = 10
    for epoch in range(epochs):
        total_loss = 0.0  # Initialize total loss for each epoch
        for i, (sentence, tags) in enumerate(zip(words_train_encoded_tensor, labels_train_encoded_padded)):
            model.zero_grad()

            sentence_in = torch.tensor(sentence, dtype=torch.long)
            targets = torch.tensor(tags, dtype=torch.long)

            # Run forward pass
            tag_scores = model(sentence_in)

            # Compute the loss, gradients, and update the parameters
            loss = loss_function(tag_scores.view(-1, output_dim), targets.view(-1))  # Flatten output for NLLLoss
            loss.backward()
            optimizer.step()
            total_loss += loss.item()

        # Print average loss for the epoch
        print(f"Epoch {epoch+1}/{epochs}, Loss: {total_loss/(i+1):.4f}")
    
    torch.save(model.state_dict(), 'pos_tagging_model1.pt')

    def calculate_metrics(model, data_loader):
        model.eval()  # Set the model to evaluation mode
        all_predictions = []
        all_labels = []

        with torch.no_grad():  # No need to track gradients for accuracy calculation
            for sentences, labels in data_loader:
                outputs = model(sentences)
                _, predicted = torch.max(outputs, dim=2)  # Get the index of the max log-probability
                
                # Store predictions and labels
                all_predictions.extend(predicted.view(-1).cpu().numpy())
                all_labels.extend(labels.view(-1).cpu().numpy())

        # Calculate metrics
        accuracy = np.mean(np.array(all_predictions) == np.array(all_labels))
        f1_macro = f1_score(all_labels, all_predictions, average='macro')
        f1_micro = f1_score(all_labels, all_predictions, average='micro')
        recall = recall_score(all_labels, all_predictions, average='weighted')
        cm = confusion_matrix(all_labels, all_predictions)

        return accuracy, f1_macro, f1_micro, recall, cm

    # Assuming model, words_test_encoded, and labels_test_encoded_padded are defined
    # Convert your encoded words and labels into tensors
    words_test_encoded_tensor = torch.LongTensor(words_test_encoded)
    labels_test_encoded_tensor = torch.LongTensor(labels_test_encoded_padded)

    # Create DataLoader
    test_dataset = TensorDataset(words_test_encoded_tensor, labels_test_encoded_tensor)
    test_loader = DataLoader(test_dataset, batch_size=64, shuffle=False)

    # Calculate metrics
    accuracy, f1_macro, f1_micro, recall, cm = calculate_metrics(model, test_loader)
    print(f"Accuracy: {accuracy * 100:.2f}%")
    print(f"F1 Score (Macro): {f1_macro:.4f}")
    print(f"F1 Score (Micro): {f1_micro:.4f}")
    print(f"Recall (Weighted): {recall:.4f}")
    print("Confusion Matrix:")
    print(cm)

# def predict_pos_tags_lstm(sentence, model, word_to_index, number_to_label, max_sentence_length, embedding_dim=100):
#     # Tokenize and lowercase the input sentence
#     words = sentence.lower().split()

#     # Ensure the sentence length matches max_sentence_length by padding with '<pad>'
#     words_padded = words + ['<pad>'] * (max_sentence_length - len(words))

#     # Convert padded words to their indices. Use a special index for unknown words and '<pad>'.
#     unk_index = len(word_to_index)  # Assuming the last index is reserved for unknown words
#     pad_index = word_to_index.get('<pad>', unk_index)  # Get index for '<pad>', or use unk_index if '<pad>' not defined
#     sentence_indices = [word_to_index.get(word, unk_index) for word in words_padded]

#     # Convert to tensor and add a batch dimension
#     sentence_tensor = torch.LongTensor(sentence_indices).unsqueeze(0)

#     # Predict
#     model.eval()  # Set the model to evaluation mode
#     with torch.no_grad():
#         outputs = model(sentence_tensor)
#         _, predicted_indices = torch.max(outputs, dim=2)

#     # Convert numeric predictions back to POS tags, ignoring predictions for padding
#     predicted_tags = [number_to_label[idx.item()] for idx in predicted_indices[0] if idx.item() != pad_index]

#     return predicted_tags

# input_sentence = "An apple a day keeps the doctor away"
# predicted_tags = predict_pos_tags_lstm(input_sentence, model, word_to_index, number_to_label, max_sentence_length,embedding_dim=100)
# a = predicted_tags[:len(input_sentence.split())]
# print(f"Sentence: {input_sentence}")
# print(f"Predicted POS Tags: {a}")
