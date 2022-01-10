#include <bits/stdc++.h>
using namespace std;

void merge(int* arr, int start, int mid, int end)
{
    int i=start,j=mid+1;
    int ans[end-start+1];
    int k=0;
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
    for(int z=0;z<=end-start;z++)
    {
        arr[z+start]=ans[z];
    }
}

void merge_Sort(int* arr, int n, int start, int end)
{
    if(start>=end)
    {
        return;
    }
    int mid=start+(end-start)/2;
    merge_Sort(arr,n,start,mid);
    merge_Sort(arr,n,mid+1,end);
    merge(arr,start,mid,end);
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
        merge_Sort(arr,n,0,n-1);
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
