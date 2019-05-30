#include<iostream>
#include<stdlib.h>
#include<conio.h>
#define NOV 9
#define NOE 14

using namespace std;

struct edge
{
 char ch1;
 char ch2;
 int wt;
};

struct link
{
    char ch;
    link *next;
};

struct head
{
    link *right;
    head *down;
};

head set[NOE];
link *tempLink, *newLink;
head *start, *newHead, *tempHead, *head1, *head2;

edge *select;
edge datum[NOE]={{'B','G',1},{'C','D',2},{'A','C',3},{'B','E',3},{'F','G',4},
{'A','D',5},{'E','I',5}, {'H','I',6},{'D','G',6}, {'C','F',9},
{'A','B',9},{'G','I',10},{'F','H',12},{'G','E',15}};

void initHead()
{
    for(int index=0; index<NOV; index++)
    {
        newHead = new head();
        newLink = new link();
        if(start == NULL)
            start = newHead, tempHead = start;
        else
        {
            tempHead->down = newHead;
            tempHead = tempHead->down;
        }        
        newLink->ch = 'A' + index;
        newLink->next = NULL;
        newHead->right = newLink;
    }
}

head* findHead(char ch)
{
    for(tempHead = start; tempHead; tempHead=tempHead->down)
    {
        for(tempLink = tempHead->right; tempLink!=NULL && tempLink->ch!=ch; tempLink=tempLink->next);
        if(tempLink!=NULL)
        {
            return tempHead;
        }
    }
    return tempHead;
}
int main()
{
    initHead();
    for(int index=0; index<NOE; index++)
    {
        for(tempHead = start; tempHead; tempHead=tempHead->down)
        {
            for(tempLink = tempHead->right; tempLink; tempLink=tempLink->next)
            {
                cout<<tempLink->ch<<"->";
            }
            cout<<endl;
        }
        char ch1 = datum[index].ch1;
        char ch2 = datum[index].ch2;
        head1 = findHead(ch1);
        head2 = findHead(ch2);
        cout<<ch1<<" "<<ch2<<endl;
        if(head1 != head2)
        {
            for(tempLink=head1->right; tempLink->next!=NULL; tempLink=tempLink->next);
            tempLink->next = head2->right;
            for(tempHead=start; tempHead->down!=head2; tempHead=tempHead->down);
            tempHead->down = head2->down;
            free(head2);
        }
        else
        {
            cout<<"\nCyclic occurs, skipped";
        }
        getch();
        system("CLS");
    }

    return 0;
}

