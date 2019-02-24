#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->right = temp->left = NULL;
    return temp;
}

void verticalOrderPrinting(Node *root, int level)
{
    map<int, vector<int>> m;
    
}

int main()
{
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 
    root->right->right->right = newNode(9); 

    int level = 0;
    verticalOrderPrinting(root, level);

    return 0;
}