#include<iostream>
#include<stdlib.h>

using namespace std;

struct Node
{
	int data;
	Node *next, *prev;	
};

Node *srchead, *deshead, *auxhead, *srcTop, *desTop, *auxTop, *temp;

bool isTrue(int nod, int auxCount, int destCount)
{
	if(nod%2==0 && auxCount!=nod)
		return true;
	else if(nod%2!=0 && destCount!=nod)
		return true;
	else
		return false;
}

void printAxis()
{
	cout<<endl;
	//src printing
	cout<<"src: ";
	for(temp=srcTop; temp->data!=INT_MAX; temp=temp->prev)
		cout<<temp->data<<" ";
	cout<<endl;
	
	//des printing
	cout<<"des: ";
	for(temp=desTop; temp->data!=INT_MAX; temp=temp->prev)
		cout<<temp->data<<" ";
	cout<<endl;
	
	//aux printing
	cout<<"aux: ";
	for(temp=auxTop; temp->data!=INT_MAX; temp=temp->prev)
		cout<<temp->data<<" ";
	cout<<endl<<endl;
}

int main()
{
	int nod, destCount=0, auxCount=0;
	cout<<"Enter the number of discs: ";
	cin>>nod;
	
	//making first node as INT_MAX	
	temp = new Node();
	temp->data = INT_MAX;
	temp->prev = temp->next = NULL;
	srchead = temp;
	srcTop = srchead;
	
	temp = new Node();
	temp->data = INT_MAX;
	temp->prev = temp->next = NULL;
	deshead = temp;
	desTop = deshead;
	
	temp = new Node();
	temp->data = INT_MAX;
	temp->prev = temp->next = NULL;
	auxhead = temp;
	auxTop = auxhead;
	
	//printing all axis
	printAxis();
	
	for(int i=nod; i>0; i--)
	{
		temp = new Node();
		temp->data = i;
		temp->prev = srcTop;
			srcTop->next = temp;
			temp->prev = srcTop;
		srcTop = temp;
	}
	
	while(isTrue(nod,auxCount,destCount))
	{
		//src to dest
		if(desTop->data != INT_MAX && srcTop->data > desTop->data)
		{
			temp = desTop;
			desTop = desTop->prev;
			if(srcTop == NULL)
			{
				srcTop = temp;
				srchead = temp;
				temp->prev = NULL;
			}
			else
			{
				srcTop->next = temp;
				temp->prev = srcTop;
				srcTop = temp;
			}
			cout<<"dest to src"<<endl;
			destCount--;
		}
		else
		{
			temp = srcTop;
			srcTop = srcTop->prev;
			if(desTop == NULL)
			{
				desTop = temp;
				deshead = temp;
				temp->prev = NULL;
			}
			else
			{
				desTop->next = temp;
				temp->prev = desTop;
				desTop = temp;
			}
			cout<<"src to dest"<<endl;
			destCount++;
		}
		
		if(!isTrue(nod, auxCount, destCount))
			break;
		
		//src to aux
		if(auxTop->data != INT_MAX && srcTop->data > auxTop->data)
		{
			temp = auxTop;
			auxTop = auxTop->prev;
			if(srcTop == NULL)
			{
				srcTop = temp;
				srchead = temp;
				temp->prev = NULL;
			}
			else
			{
				srcTop->next = temp;
				temp->prev = srcTop;
				srcTop = temp;
			}
			cout<<"aux to src"<<endl;
			auxCount--;
		}
		else
		{
			temp = srcTop;
			srcTop = srcTop->prev;
			if(auxTop == NULL)
			{
				auxTop = temp;
				auxhead = temp;
				temp->prev = NULL;
			}
			else
			{
				auxTop->next = temp;
				temp->prev = auxTop;
				auxTop = temp;
			}
			cout<<"src to aux"<<endl;
			auxCount++;
		}
		
		if(!isTrue(nod, auxCount, destCount))
			break;
		
		//dest to aux
		if(auxTop->data != INT_MAX && desTop->data > auxTop->data)
		{
			temp = auxTop;
			auxTop = auxTop->prev;
			if(desTop == NULL)
			{
				desTop = temp;
				deshead = temp;
				temp->prev = NULL;
			}
			else
			{
				desTop->next = temp;
				temp->prev = desTop;
				desTop = temp;
			}
			cout<<"aux to dest"<<endl;
			destCount++;
			auxCount--;
		}
		else
		{
			temp = desTop;
			desTop = desTop->prev;
			if(auxTop == NULL)
			{
				auxTop = temp;
				auxhead = temp;
				temp->prev = NULL;
			}
			else
			{
				auxTop->next = temp;
				temp->prev = auxTop;
				auxTop = temp;
			}
			cout<<"dest to aux"<<endl;
			destCount--;
			auxCount++;
		}
	}
	
	printAxis();
	return 0;
}
