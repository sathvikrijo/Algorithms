#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right, *left;
};

Node* newNode(int value)
{
    Node *temp = new Node();
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

bool childrenSumProperty(Node *root)
{
    int rightData = 0, leftData = 0;
    if(root==NULL)
        return true;
    if(root->left==NULL && root->right==NULL)
        return true;
    else
    {
        if(root->left != NULL)
            leftData = root->left->data;
        if(root->right != NULL)
            rightData = root->right->data;
        if((root->data == leftData + rightData) && (childrenSumProperty(root->left) && childrenSumProperty(root->right)))
            return true;
        return false;
    }
    return false;    
}

int main()
{
    Node *root  = newNode(10); 
    root->left         = newNode(8); 
    root->right        = newNode(2); 
    root->left->left   = newNode(3); 
    root->left->right  = newNode(5); 
    root->right->left = newNode(2); 

    childrenSumProperty(root) ? cout<<"The tree follows children sum property" : cout<<"The tree doesn't follows children sum property";

    return 0;
}