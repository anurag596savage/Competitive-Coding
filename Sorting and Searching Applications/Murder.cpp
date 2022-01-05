#include <bits/stdc++.h>
using namespace std;

long long merge(long long* arr,int start, int mid, int end)
{
    long long a[end-start+1];
    int k=0;
    int i=start,j=mid+1;
    long long count=0;
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        {
            count+=(arr[i]*(end-j+1));
            a[k++]=arr[i++];
        }
        else
        {
            a[k++]=arr[j++];
        }
    }
    while(i<=mid)
    {
        a[k++]=arr[i++];
    }
    while(j<=end)
    {
        a[k++]=arr[j++];
    }
    for(int z=0;z<=(end-start);z++)
    {
        arr[z+start]=a[z];
    }

    return count;
}

long long merge_Sort(long long* arr, int n, int start, int end)
{
    if(start>=end)
    {
        return 0;
    }
    int mid = start+(end-start)/2;
    long long left_Count = merge_Sort(arr,n,start,mid);
    long long right_Count = merge_Sort(arr,n,mid+1,end);
    long long extra_Count = merge(arr,start,mid,end);

    return (left_Count+right_Count+extra_Count);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        long long ans = merge_Sort(arr,n,0,n-1);
        cout<<ans<<endl;
    }
}
