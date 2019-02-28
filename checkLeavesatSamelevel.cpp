#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* temp = new Node();
    temp->data = data;
    temp->right = temp->left = NULL;
    return temp;
}

bool checkLeavesAtSameLevel(Node* root, int level, int *Olevel)
{
    if(root == NULL)
        return true;
    if(root->left==NULL && root->right==NULL)
    {
        if(*Olevel == 0)
        {
            *Olevel = level;
            return true;
        }
        if(level != *Olevel)
            return false;
    }

    return checkLeavesAtSameLevel(root->left, level+1, Olevel) && checkLeavesAtSameLevel(root->right, level+1, Olevel);
}

int main()
{
    struct Node *root = newNode(12); 
    root->left = newNode(5); 
    root->left->left = newNode(3); 
    root->left->right = newNode(9); 
    root->left->left->left = newNode(1); 
    root->left->right->left = newNode(1); 

    int Olevel = 0, level=0;
    bool identifier = checkLeavesAtSameLevel(root, level, &Olevel);

    identifier ? cout<<"Roots are at same level" : cout<<"Roots are at different level";

    return 0;
}