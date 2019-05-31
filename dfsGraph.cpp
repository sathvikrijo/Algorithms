#include<iostream>
#include<memory.h>
#include "graphrep.cpp"
using namespace std;

char stack[1000];
bool visited[256];
int top=-1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

head *itr1;
link *itr2;

int main()
{
    input();
    char src;
    char de_ele;
    cout<<"Enter the source vertex from which the DFS need to be done: ";
    cin>>src;
    cout<<"DFS: ";
    memset(visited, false, 256);
    push(src);
    while(top!=-1)
    {
        de_ele = pop();
        if(visited[de_ele])
            continue;
        cout<<de_ele<<"->";
        visited[de_ele] = true;
        for(itr1=start; itr1!=NULL && itr1->ch!=de_ele; itr1=itr1->head_next);
        
        for(itr2=itr1->links; itr2!=NULL; itr2=itr2->next)
            push(itr2->ch);
    }
    return 0;
}