#include<iostream>
#include<memory.h>
using namespace std;
char **reactor;

void neutrons(int x, int y, int size)
{
    int i = x, j = y;
    while(i>=1 && j>=1)
    {
        if(reactor[--i][--j] != '#')
            reactor[i][j] = '-';
    }

    i = x, j = y;
    while(i>=1 && j<size)
    {
        if(reactor[--i][++j] != '#')
            reactor[i][j] = '-';
    }

    i = x, j = y;
    while(i<size && j<size)
    {
        if(reactor[++i][++j] != '#')
            reactor[i][j] = '-';
    }

    i = x, j = y;
    while(i<size && j>=1)
    {
        if(reactor[++i][--j] != '#')
            reactor[i][j] = '-';
    }

}

int main()
{
    int size, noa, nor, x, y, no, itr;
    char ch;
    cout<<"Enter the size of the reactor: ";
    cin>>size;
    reactor = (char**)calloc(size+2, sizeof(char*));
    for(int i=0; i<size+2; i++)
        reactor[i] = (char*)calloc(size+2, sizeof(char));
    for(int rIndex=0; rIndex<size+2; rIndex++)
    {
        for(int cIndex=0; cIndex<size+2; cIndex++)
            reactor[rIndex][cIndex]='0';
        cout<<endl;
    }
    cout<<"Enter the number of atoms:\n";
    cin>>noa;
    cout<<"Enter the atom's positions\n";
    while(noa--)
    {
        cin>>x>>y;
        reactor[x][y] = '#';
    }
    cout<<"Enter the number of rays:\n";
    cin>>nor;
    cout<<"Enter the rays:\n";
    while(nor--)
    {
        int rItr, cItr;
        cin>>ch>>no;
        if(ch == 'R')
        {
            for(rItr=1; rItr<size+1; rItr++)
            {
                if(reactor[no][rItr] == '#')
                {
                    reactor[no][0] = 'H';
                    neutrons(no,rItr,size+1);
                    break;
                }
                else
                {
                    if(reactor[no][rItr]=='-')
                    {
                        reactor[size+1][rItr] = 'r';
                        break;
                    }
                    if(reactor[no-1][rItr]=='#' && reactor[no+1][rItr]=='#')
                    {
                        reactor[no][0] = 'R';
                        break;
                    }
                }
            }
            if(rItr==size+1)
                reactor[no][size+1] = 'P';
        }
        else
        {
            if(ch == 'C')
            {
                for(cItr=size; cItr>=1; cItr--)
                {
                    if(reactor[cItr][no] == '#')
                    {
                        reactor[size+1][no] = 'H';
                        neutrons(cItr,no,size+1);
                        break;
                    }
                    else
                    {
                        if(reactor[cItr][no]=='-')
                        {
                            reactor[cItr][size+1] = 'c';
                            break;
                        }
                        if(reactor[cItr][no-1]=='#' && reactor[cItr][no+1]=='#')
                        {
                            reactor[size+1][no] = 'R';
                            break;
                        }
                    }
                }
                if(cItr==0)
                    reactor[0][no] = 'P';
            }
        }
    }
    for(int rIndex=0; rIndex<size+2; rIndex++)
    {
        for(int cIndex=0; cIndex<size+2; cIndex++)
        {
            if(reactor[rIndex][cIndex] == 'r')
            {
                for(itr=rIndex-1; itr>=1 && reactor[itr][cIndex]!='-'; itr--);
                cout<<'R'<<itr<<"  ";
            }
            else if(reactor[rIndex][cIndex] == 'c')
            {
                for(itr=cIndex-1; itr>=1 && reactor[rIndex][itr]!='-'; itr--);
                cout<<'C'<<itr<<"  ";
            }
            else if(reactor[rIndex][cIndex] == '0')
                cout<<'-'<<"   ";
            else
                cout<<reactor[rIndex][cIndex]<<"   ";
        }
        cout<<endl;
    }
    return 0;
}