#include <bits/stdc++.h>
using namespace std;

void Print_Possible_Paths(int** arr,int n,int row,int col,int** ans)
{

    if(row==n-1 && col==n-1)
    {
        ans[row][col]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<ans[i][j]<<" "; 
            }
        }
        ans[row][col]=0;
        cout<<endl;
        return;
    }

    if(arr[row][col]==0)
    {
        return;
    }
    else
    {
        ans[row][col]=1;
        if(col+1<n && ans[row][col+1]!=1)
        {
            Print_Possible_Paths(arr,n,row,col+1,ans);
        }
        if(row+1<n && ans[row+1][col]!=1)
        {
            Print_Possible_Paths(arr,n,row+1,col,ans);
        }
        if(col-1>=0 && ans[row][col-1]!=1)
        {
            Print_Possible_Paths(arr,n,row,col-1,ans);
        }
        if(row-1>=0 && ans[row-1][col]!=1)
        {
            Print_Possible_Paths(arr,n,row-1,col,ans);
        }
        ans[row][col]=0;
        return;
    }

}

int main()
{
    int n;
    cin>>n;

    int** arr = new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    int** ans = new int*[n];
    for(int i=0;i<n;i++)
    {
        ans[i] = new int[n];
        for(int j=0;j<n;j++)
        {
            ans[i][j]=0;
        }
    }

    Print_Possible_Paths(arr,n,0,0,ans);
    

    return 0;
}
