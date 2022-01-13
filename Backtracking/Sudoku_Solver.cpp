#include <bits/stdc++.h>
using namespace std;
#define N 9

bool Find_Empty_Position(int arr[N][N],int &row,int &col)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(arr[i][j]==0)
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}

bool row_Check(int arr[N][N],int num,int row,int col)
{
    for(int j=0;j<N;j++)
    {
        if(arr[row][j]==num)
        {
            return false;
        }
    }
    return true;
}
bool col_Check(int arr[N][N],int num,int row,int col)
{
    for(int i=0;i<N;i++)
    {
        if(arr[i][col]==num)
        {
            return false;
        }
    }
    return true;
}

bool grid_Check(int arr[N][N],int num,int row,int col)
{
    int row_factor = row - row%3;
    int col_factor = col - col%3;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(arr[i+row_factor][j+col_factor]==num)
            {
                return false;
            }
        }
    }
    return true;
}

bool is_Safe(int arr[N][N],int num,int row,int col)
{
    if(row_Check(arr,num,row,col) && col_Check(arr,num,row,col) && grid_Check(arr,num,row,col))
    {
        return true;
    }
    return false;
}

bool Sudoku_Solver(int arr[N][N])
{
    int row,col;
    if(!Find_Empty_Position(arr,row,col))
    {
        return true;
    }
    for(int i=1;i<=9;i++)
    {
        if(is_Safe(arr,i,row,col))
        {
            arr[row][col]=i;
            if(Sudoku_Solver(arr))
            {
                return true;
            }
            arr[row][col]=0;
        }
    }
    return false;
}

int main()
{
    int arr[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>arr[i][j];
        }
    }
    if(Sudoku_Solver(arr))
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;

}
