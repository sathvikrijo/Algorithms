#include<iostream>
#include<memory.h>

using namespace std;

int main()
{
    int Tindex, Pindex, TindexStart;
    int BMt[256];
    string text, pattern;
    cout<<"Enter the text: \n";
    getline(cin, text);
    cout<<"Enter the pattern to be searched: \n";
    cin>>pattern;

    for(int index=0; index<256; index++)
        BMt[index] = pattern.length();
    
    for(int index=0; index<pattern.length()-1; index++)
        BMt[pattern[index]] = pattern.length()-index-1;
    
    Pindex = pattern.size()-1;
    for(Tindex=pattern.size()-1; Tindex<text.size(); )
    {
        TindexStart = Tindex;
        while(Pindex>=0 && text[Tindex]==pattern[Pindex])
        {
            Tindex--;
            Pindex--;
        }
        if(Pindex<0)
            cout<<"Pattern Found at :"<<Tindex+1<<endl;

        Tindex = BMt[text[TindexStart]] + TindexStart;
        Pindex = pattern.size()-1;
    }
    return 0;
}