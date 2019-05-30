#include<iostream>
#include<stdio.h>
using namespace std;

int nov=0;

struct link
{
    char ch;
    int weight;
    link* next;
};

struct head
{
    char ch;
    head* head_next;
    link* links;
};

head *start, *temp, *newHead, *itr1;
link *newLink, *itr2, *tempLink;

int input()
{
    int weight;
    char ch1, ch2;
    start == NULL;
    cout<<"Press $ to end\n";
    while(1)
    {
        cin>>ch1;
        if(ch1 == '$')
            break;
        cin>>ch2>>weight;
        nov++;
        if(start == NULL)
        {
            newHead = new head();
            newHead->ch = ch1;
            start = newHead;

            newLink = new link();
            newLink->ch = ch2;
            newLink->weight = weight;
            newLink->next = NULL;
            newHead->links = newLink;

            newHead = new head();
            newHead->ch = ch2;
            newHead->head_next = start;
            start = newHead;

            newLink = new link();
            newLink->ch = ch1;
            newLink->weight = weight;
            newLink->next = NULL;
            newHead->links = newLink;
        }
        else
        {
            for(temp=start; temp!=NULL && temp->ch!=ch1; temp=temp->head_next);
            
            if(temp == NULL)
            {
                newHead = new head();
                newHead->ch = ch1;
                newHead->head_next = start;
                start = newHead;

                newLink = new link();
                newLink->ch = ch2;
                newLink->weight = weight;
                newHead->links = newLink;
            }
            else
            {
                newLink = new link();
                newLink->ch = ch2;
                newLink->weight = weight;
                for(tempLink = temp->links; tempLink->next!=NULL; tempLink=tempLink->next);
                tempLink->next = newLink;
                newLink->next = NULL;
            }

            for(temp=start; temp!=NULL && temp->ch!=ch2; temp=temp->head_next);
            
            if(temp == NULL)
            {
                newHead = new head();
                newHead->ch = ch2;
                newHead->head_next = start;
                start = newHead;

                newLink = new link();
                newLink->ch = ch1;
                newLink->weight = weight;
                newHead->links = newLink;
            }
            else
            {
                newLink = new link();
                newLink->ch = ch1;
                newLink->weight = weight;
                for(tempLink = temp->links; tempLink->next!=NULL; tempLink=tempLink->next);
                tempLink->next = newLink;
                newLink->next = NULL;
            }
        }
    }
    for(itr1=start; itr1!=NULL; itr1=itr1->head_next)
    {
        cout<<itr1->ch<<"\t";
        for(itr2=itr1->links; itr2!=NULL; itr2=itr2->next)
            cout<<"<"<<itr2->ch<<","<<itr2->weight<<"> ";
        cout<<endl;
    }
    return 0;
}