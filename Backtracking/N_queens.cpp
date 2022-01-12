#include <bits/stdc++.h>
using namespace std;

bool is_Possible(int** arr,int n,int row,int col)
{
    if(row==0)
    {
        return true;
    }
    for(int i=row;i>=0;i--)
    {
        if(arr[i][col]==1)
        {
            return false;
        }
    }

    for(int i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(arr[i][j]==1)
        {
            return false;
        }

    }

    for(int i=row,j=col;i>=0 && j<n;i--,j++)
    {
        if(arr[i][j]==1)
        {
            return false;
        }

    }
    return true;
}

void Print_Possible_Paths_helper(int** arr,int n,int row,int col)
{

    if(row==n)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<arr[i][j]<<" "; 
            }
        }
        cout<<endl;
        return;
    }
    if(is_Possible(arr,n,row,col))
    {
        arr[row][col]=1;
        for(int j=0;j<n;j++)
        {
            Print_Possible_Paths_helper(arr,n,row+1,j);
            if(row+1==n)
            {
                arr[row][col]=0;
                return;
            }
        }
        arr[row][col]=0;   
    }

    return;

}   

void Print_Possible_Paths(int n)
{
    int **arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            arr[i][j]=0;
        }
    }
    for(int j=0;j<n;j++)
    {
        Print_Possible_Paths_helper(arr,n,0,j);
    }
}

int main()
{
    int n;
    cin>>n;
    Print_Possible_Paths(n);

    return 0;
}
