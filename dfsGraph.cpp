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

int main()
{
    input();
    char de_ele;
    memset(visited, false, 256);
    push('A');
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