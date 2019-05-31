#include<iostream>
#include<memory.h>
#include<limits.h>
#include "graphrep.cpp"
using namespace std;

bool *visited;
char *parent;
int *cost;

char findMinCostVertex()
{
    char mini_ch;
    int min = INT_MAX;
    for(int index=0; index<nov; index++)
    {
        if(cost[index]<min && visited[index] == false)
        {
            min = cost[index];
            mini_ch = index + 'A';
        }
    }
    return mini_ch;
}

bool isAllVisited()
{
    for(int index=0; index<nov; index++)
        if(visited[index] == false)
            return false;
    return true;
}

void printSPT()
{
    for(int index=0; index<nov; index++)
        cout<<(char)(index+'A')<<"\t"<<cost[index]<<"\t"<<parent[index]<<endl;
}

void forUnderstanding()
{
    for(int index=0; index<nov; index++)
        cout<<char('A'+index)<<" ";
    cout<<endl;
    for(int index=0; index<nov; index++)
        cout<<visited[index]<<" ";  
    cout<<"\t<-Visited";
    cout<<endl;
    for(int index=0; index<nov; index++)
    {   
        if(cost[index] == INT_MAX)
        {
            cout<<"* "; 
            continue;
        }
        cout<<cost[index]<<" "; 
    }
    cout<<"\t<-Cost";
    cout<<endl;
    for(int index=0; index<nov; index++)
        cout<<parent[index]<<" "; 
    cout<<"\t<-Parent";
    cout<<endl<<endl;
}

int main()
{
    input();
    visited = (bool*)malloc(nov * sizeof(bool));
    parent = (char*)malloc(nov * sizeof(char));
    cost = (int*)malloc(nov * sizeof(int));

    char src, minVertex, ch;
    int dist;

    for(int index=0; index<nov; index++)
        cost[index] = INT_MAX;
    for(int index=0; index<nov; index++)
        visited[index] = false;

    cout<<"Enter the source: ";
    cin>>src;
    cost[src-'A'] = 0;
    parent[src-'A'] = src;
    while(!isAllVisited())
    {
        minVertex = findMinCostVertex();
        visited[minVertex-'A'] = true;
        dist = cost[minVertex-'A'];
        for(tempHead=start; tempHead!=NULL && tempHead->ch!=minVertex; tempHead=tempHead->head_next);
        for(tempLink=tempHead->links; tempLink!=NULL; tempLink=tempLink->next)
        {
            ch = tempLink->ch;
            if(dist + tempLink->weight < cost[tempLink->ch -'A'] && !visited[ch-'A'])
                cost[ch-'A'] = tempLink->weight + dist, parent[ch-'A'] = minVertex;
        }
        //forUnderstanding();
    }
    cout<<"From source "<<src<<endl<<endl;
    cout<<"dest\tcost\tparent"<<endl;
    printSPT();

    return 0;
}