#include<iostream>
#include<windows.h>
using namespace std;

int **grid;

void markclear(int r, int c, int n, int val)
{
    int i = r-1, j = c-1;
    while(i>=1 && j>=1)
        grid[i--][j--] += val;

    i = r-1, j = c;
    while(i>=1)
        grid[i--][j] += val;

    i = r+1, j = c-1;
    while(i<=n && j>=0)
        grid[i++][j--] += val;

    i = r, j = c+1;
    while(j<=n)
        grid[i][j++] += val;

    i = r+1, j = c+1;
    while(i<=n && j<=n)
        grid[i++][j++] += val;

    i = r+1, j = c;
    while(i<=n)
        grid[i++][j] += val;

    i = r+1, j = c-1;
    while(i<=n && j>=1)
        grid[i++][j--] += val;

    i = r, j = c-1;
    while(j>=1)
        grid[i][j--] += val;
    
    grid[r][c] += val;
}

void printGrid(int n)
{
    for(int rowIndex=1; rowIndex<=n; rowIndex++)
    {
        for(int colIndex=1; colIndex<=n; colIndex++)
        {
            if(grid[rowIndex][colIndex] == rowIndex)
                cout<<" Q ";
            else
                cout<<" - ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

int main()
{
    int n, row=1, col=0;
    cout<<"Enter the grid size: \n";
    cin>>n;

    int queens[n+1] = {0};

    grid = (int**)calloc(n+1, sizeof(int*));
    for(int index=0; index<n+1; index++)
        grid[index] = (int*)calloc(n+1, sizeof(int));
    
    while(row<=n)
    {
        for(col = col+1; col<=n; col++)
            if(grid[row][col] == 0 && queens[row]==0)
                break;
        if(col == n+1)
        {
            row--;
            col = queens[row];
            markclear(row, col, n, -row);
            queens[row] = 0;
            continue;
        }
        markclear(row, col, n, row);
        queens[row] = col;
        col=0;
        row++;
    }
    printGrid(n);
    return 0;
}