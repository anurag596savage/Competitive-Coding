#include <bits/stdc++.h>
using namespace std;

bool merge(int* arr,int start,int mid, int end)
{
    bool flag=true;
    if(abs(arr[mid]-arr[mid+1])!=1 && arr[mid]>arr[mid+1])
    {
        flag = false;
    }
    int i=0,j=mid+1;
    int k=0;
    int ans[end-start+1];
    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        {
            ans[k++]=arr[i++];
        }
        else
        {
            ans[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        ans[k++]=arr[i++];
    }
    while(j<=end)
    {
        ans[k++]=arr[j++];
    }
    for(int z=0;z<=(end-start);z++)
    {
        arr[z+start]=ans[z];
    }
    return flag;
}

bool is_Possible(int* arr, int n,int start, int end)
{
    if(start>=end)
    {
        return true;
    }
    int mid = start+(end-start)/2;
    bool left_Ans=is_Possible(arr,n,start,mid);
    bool right_Ans=is_Possible(arr,n,mid+1,end);
    bool extra_Ans=merge(arr,start,mid,end);

    return (left_Ans && right_Ans && extra_Ans);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        if(is_Possible(arr,n,0,n-1))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
