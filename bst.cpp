#include<bits/stdc++.h>
using namespace std;
class Node{
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node * root, int data)
{
    if(root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if(root->data < data)
    {
        root->right = insert(root->right, data);
    }
    else{
        root->left = insert(root->left, data);
    }

    return root;

}

Node* minVal(Node* root)
{
    Node* temp = root;

    while(temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root)
{
    Node* temp = root;

    while(temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}

Node* deleteNode(Node *root, int data)
{
    if(root == NULL) return NULL;

    if(root->data == data)
    {
        //0 child
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        //1 child
        if(root->left != NULL && root->right == NULL)
        {
            Node * l = root->left;
            delete root;
            return l;
        }
         if(root->left == NULL && root->right != NULL)
        {
            Node * r = root->right;
            delete root;
            return r;
        }
        //2 child
         if(root->left != NULL && root->right != NULL)
        {
            Node* maxi = maxVal(root->left);
            root->data = maxi->data;
            root->left = deleteVal(root->left, maxi->data);
            return root;
        }
    }
    else if(root->data > data)
    {
        root->left = deleteNode(root->left, data);
    }
    else
    {
        root->right = deleteNode(root->right, data);
    }
    return root;
}

int main()
{

}

