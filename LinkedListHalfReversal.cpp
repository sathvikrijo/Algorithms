#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* newNode(int ele)
{
    Node* temp = new Node();
    temp->data = ele;
    temp->next =  NULL;
    return temp;
}

Node* LinkedList(int *array, int N, Node* head)
{
    int index=0;
    Node *temp, *itrTemp; 
    while(index<N)
    {
        temp = newNode(array[index]);
        if(head == NULL)
        {
            head = temp;
            itrTemp = head;
        }
        else
        {
            itrTemp->next = temp;
            itrTemp = temp;
        }
        index++;
    }
    return head;
}

void printList(Node* head)
{
    Node* temp;
    for(temp=head; temp!=NULL; temp=temp->next)
        cout<<temp->data<<" ";
    cout<<endl;
}

Node* halfReversal(Node* head, int N)
{
    int position = 1, limit;
    Node *tempst, *prev=NULL, *next, *halfStart;
    if(N%2==0)
        limit = (N/2)+1;
    else
        limit = (N+1)/2;
    for(tempst=head; position<limit; prev=tempst, tempst=tempst->next, position++);
    halfStart = prev;
    halfStart->next = NULL;
    prev = NULL;
    while(tempst != NULL)
    {
        next = tempst->next;
        tempst->next = prev;
        prev = tempst;
        tempst = next;
    }
    halfStart->next = prev;
    return head;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, size = 11;
    Node* head = NULL;
    head = LinkedList(arr, size, head);
    cout<<"Before reversing: ";
    printList(head);
    cout<<"After reversing: ";
    head = halfReversal(head, size);
    printList(head);
    return 0;
}