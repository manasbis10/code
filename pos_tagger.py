import sys
from gensim.models import Word2Vec


import torch
import torch
import torch.nn as nn
import torch.optim as optim
import numpy as np
import numpy as np

def main():
    if len(sys.argv)<2:
        print("invalid number of arguments")
        sys.exit(1)
    choice=sys.argv[1]

    if choice=="-f":
        from Q1 import X_train_flattened, label_to_number, number_to_label, words_train_modified
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
        num_unique_tags = 14    
        # Assuming you know the input_dim and output_dim
        input_dim = X_train_flattened.shape[1]# The input dimension you used during training
        output_dim = num_unique_tags  # The number of unique POS tags

        hidden_dim1 = 128
        hidden_dim2 = 70

        model1 = POSFFNN(input_dim, hidden_dim1, hidden_dim2, output_dim)

        model1.load_state_dict(torch.load('pos_tagging_model.pt'))
        model1.eval()  # Set the model to evaluation mode


        model = Word2Vec(sentences=words_train_modified, vector_size=100, window=5, min_count=1, workers=4)
        def predict_pos_tags(sentence, model, word_embeddings, label_to_number, number_to_label, p=2, s=3, embedding_dim=100):
            # Insert s number of '<s>' at the beginning and p number of '</s>' at the end of the sentence
            modified_sentence = ' '.join(['<s>'] * s + [sentence] + ['</s>'] * p).lower()
            

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
            

            # Predict
            model.eval()  # Set the model to evaluation mode
            with torch.no_grad():
                outputs = model(X_tensor)
                _, predicted_indices = torch.max(outputs, 1)

            # Convert numeric predictions back to POS tags
            predicted_tags = [number_to_label[idx.item()] for idx in predicted_indices]

            return predicted_tags

        input_sentence = input("Write a sentence : ")
        predicted_tags = predict_pos_tags(input_sentence, model1, model.wv, label_to_number, number_to_label, p=2, s=2, embedding_dim=100)

        print(f"Sentence: {input_sentence}")
        print(f"Predicted POS Tags: {predicted_tags}")

    elif choice== "-r":
        from Q2 import vocab_size, embedding_dim, word_to_index, max_sentence_length, label_to_number, number_to_label
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

        hidden_dim = 256
        output_dim = len(label_to_number)  # Number of unique POS tags

        model = POSLSTM(vocab_size, embedding_dim, hidden_dim, output_dim)
        model.load_state_dict(torch.load('pos_tagging_model1.pt'))
        model.eval()

        def predict_pos_tags_lstm(sentence, model, word_to_index, number_to_label, max_sentence_length, embedding_dim=100):
            # Tokenize and lowercase the input sentence
            words = sentence.lower().split()

            # Ensure the sentence length matches max_sentence_length by padding with '<pad>'
            words_padded = words + ['<pad>'] * (max_sentence_length - len(words))

            # Convert padded words to their indices. Use a special index for unknown words and '<pad>'.
            unk_index = len(word_to_index)  # Assuming the last index is reserved for unknown words
            pad_index = word_to_index.get('<pad>', unk_index)  # Get index for '<pad>', or use unk_index if '<pad>' not defined
            sentence_indices = [word_to_index.get(word, unk_index) for word in words_padded]

            # Convert to tensor and add a batch dimension
            sentence_tensor = torch.LongTensor(sentence_indices).unsqueeze(0)

            # Predict
            model.eval()  # Set the model to evaluation mode
            with torch.no_grad():
                outputs = model(sentence_tensor)
                _, predicted_indices = torch.max(outputs, dim=2)

            # Convert numeric predictions back to POS tags, ignoring predictions for padding
            predicted_tags = [number_to_label[idx.item()] for idx in predicted_indices[0] if idx.item() != pad_index]

            return predicted_tags

        input_sentence = input("Write a sentence : ")
        predicted_tags = predict_pos_tags_lstm(input_sentence, model, word_to_index, number_to_label, max_sentence_length,embedding_dim=100)
        a = predicted_tags[:len(input_sentence.split())]
        print(f"Sentence: {input_sentence}")
        print(f"Predicted POS Tags: {a}")

            

if __name__=="__main__":
    main()