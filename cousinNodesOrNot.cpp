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
    temp->left = temp->right = NULL;
    return temp;
}

bool isSibling(Node *root, Node *node1, Node *node2)
{
    if(root == NULL)
        return false;
    if((root->left == node1 && root->right == node2) || (root->left == node2 && root->right == node1))
        return true;
    return isSibling(root->left, node1, node2) && isSibling(root->right, node1, node2);
    
}

bool sameLevel(Node *root, Node *node1, Node *node2, int *OLevel, int level)
{
    if(root == NULL)
        return true;
    if(root == node1 || root == node2)
    {
        if(*OLevel == 0)
        {
            *OLevel = level;
            return true;
        }
        else
        {
            if(*OLevel == level)
                return true;
            else
                return false;
        }
    }
    return sameLevel(root->left, node1, node2, OLevel, level+1) && sameLevel(root->right, node1, node2, OLevel, level+1);
}

int main()
{
    struct Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->right->right = newNode(15); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    root->right->left->right = newNode(8); 

    Node *node1 = root->left->left; 
    Node *node2 = root->right->right; 

    int OLevel = 0, level = 0;

    sameLevel(root, node1, node2, &OLevel, level) && !isSibling(root, node1, node2) ? cout<<"Yes, they are cousins" : cout<<"No, they are not cousins";

    return 0;
}