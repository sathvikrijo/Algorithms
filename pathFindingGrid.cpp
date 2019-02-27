#include<bits/stdc++.h>
#define N 6
#define M 5
using namespace std;

void findPath(char grid[][N])
{
    queue<pair<int,int>> q;
    pair<int,int> rc;
    int row, col;
    bool pathExists = false;

    q.push(make_pair(0,0));
    while(!q.empty())
    {
        rc = q.front();
        q.pop();
        row = rc.first;
        col = rc.second;
        //check if it is reached
        if(grid[row][col]=='C')
        {
            pathExists = true;
            break;
        }
        //else checks for neighbours
        else
        {
            if(grid[row-1][col]=='1' || grid[row-1][col]=='C')
                q.push(make_pair(row-1,col));
            if(grid[row+1][col]=='1' || grid[row+1][col]=='C')
                q.push(make_pair(row+1,col));
            if(grid[row][col-1]=='1' || grid[row][col-1]=='C')
                q.push(make_pair(row,col-1));
            if(grid[row][col+1]=='1' || grid[row][col+1]=='C')
                q.push(make_pair(row,col+1));
        }
        grid[row][col] = '0';
    }
    if(pathExists)
        cout<<"YES";
    else
        cout<<"NO";
    
}

int main()
{
    char grid[][N] = {{'1', '0', '1', '1', '0', '0'}, 
                    {'1', '1', '0', '1', '0', '1'}, 
                    {'0', '1', '1', 'C', '0', '1'}, 
                    {'0', '1', '0', '0', '0', '1'},
                    {'0', '1', '1', '1', '1', '1'}};
    
    findPath(grid);

    return 0;
}