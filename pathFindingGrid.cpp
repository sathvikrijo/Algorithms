#include<bits/stdc++.h>
using namespace std;

#define N 6

bool findPath(int grid[][N], int row, int col, int solution[][N])
{
    if((row==N-1 && col==N-1) && grid[row][col]==1)
    {
        solution[row][row] = 1;
        return true;
    }
    else if(row>=N || col>=N)
        return false;
    else if(grid[row][col] == 1)
    {
        grid[row][col] = 0;
        solution[row][col] = 1;
        if(findPath(grid, row+1, col, solution) == true)
            return true;
        if(findPath(grid, row, col+1, solution) == true)
            return true;
        if(findPath(grid, row-1, col, solution) == true)
            return true;
        if(findPath(grid, row, col-1, solution) == true)
            return true;
        grid[row][col] = 1;
        solution[row][col] = 0;
        return false;
    }
    return false;
}

void printPath(int solution[][N])
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
            cout<<solution[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    int grid[][N] = {{1, 0, 1, 1, 1, 1},
                    {1, 0, 1, 0, 0, 1},
                    {1, 0, 1, 1, 0, 1},
                    {1, 0, 0, 1, 0, 1},
                    {1, 1, 0, 1, 0, 1},
                    {0, 1, 1, 1, 0, 1}};

    int solution[N][N] = {{0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0}};

    if(findPath(grid,0,0,solution))
        printPath(solution);
    else
        cout<<"Path doesn't exists"<<endl;
    
    return 0;
}