#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

struct NodeDetails
{
    Node* ptr;
    int min, max;
};

NodeDetails getNode(int data)
{
    NodeDetails t;
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    
    t.ptr = temp;
    return t;
}

int main()
{
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10}; 
    int n = sizeof(arr)/sizeof(arr[0]);
    queue<NodeDetails> q;

    int i = 0;
    NodeDetails nD = getNode(arr[i++]);
    nD.min = INT_MIN;
    nD.max = INT_MAX;
    q.push(nD);

    while(i!=n && !q.empty())
    {
        NodeDetails temp;
        temp = q.front();
        q.pop();

        if(arr[i]<temp.ptr->data && arr[i]>temp.min)
        {
            nD = getNode(arr[i++]);
            nD.min = temp.min;
            nD.max = temp.ptr->data;
            q.push(nD);
        }

        if(arr[i]>temp.ptr->data && arr[i]<temp.max)
        {
            nD = getNode(arr[i++]);
            nD.min = temp.ptr->data;
            nD.max = temp.max;
            q.push(nD);
        }
    }

    if(i==n)
    {
        cout<<"YES, it is level order traversal of a BST "<<i;
    }
    else
    {
        cout<<"NO, it is not a level order traversal of a BST "<<i;
    }
        
    return 0;
}