#include<iostream>
#include<memory.h>
#include "graphrep.cpp"
using namespace std;

char queue[1000];
bool visited[256];
int front=-1, rear=-1;

void enqueue(char ch)
{
    if(front == -1)
        ++front;
    queue[++rear] = ch;
}

char dequeue()
{
    return queue[front++];
}

head *itr1;
link *itr2;

int main()
{
    input();
    char src;
    char de_ele;
    cout<<"Enter the source vertex from which the BFS need to be done: ";
    cin>>src;
    cout<<"BFS: ";
    memset(visited, false, 256);
    enqueue(src);
    while(front<=rear || front==0)
    {
        de_ele = dequeue();
        if(visited[de_ele])
            continue;
        cout<<de_ele<<"->";
        visited[de_ele] = true;
        for(itr1=start; itr1!=NULL && itr1->ch!=de_ele; itr1=itr1->head_next);
        
        for(itr2=itr1->links; itr2!=NULL; itr2=itr2->next)
            enqueue(itr2->ch);
    }
    return 0;
}
