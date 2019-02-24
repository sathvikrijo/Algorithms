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

void constructVerticalOrder(Node* root, int level, map<int, vector<int>> &vm)
{
    if(root == NULL)
        return;
    if(root)
        vm[level].push_back(root->data);
    constructVerticalOrder(root->left, level-1, vm);
    constructVerticalOrder(root->right, level+1, vm);
}

void verticalOrderPrinting(Node *root, int level)
{
    map<int, vector<int>> m;
    constructVerticalOrder(root, level, m);

    for(auto it = m.begin(); it!=m.end(); it++)
    {
        for(auto vit=0; vit<it->second.size(); vit++)
        {
            cout<<it->second[vit]<<" ";
        }
        cout<<endl;
    }
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