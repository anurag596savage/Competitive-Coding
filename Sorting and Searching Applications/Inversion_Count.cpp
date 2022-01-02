#include <iostream>
using namespace std;


long long merge_Count(long long* arr,int start,int mid,int end)
{
    long long count=0;
    int i=start;
    int j=mid+1;
    long long ans[end-start+1];
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
            count+=mid-i+1;
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
    return count;
}

long long merge_Sort(long long* arr,int n,int start,int end)
{
    if(start>=end)
    {
        return 0;
    }
    int mid = start+(end-start)/2;
    long long left_Count = merge_Sort(arr,n,start,mid);
    long long right_Count = merge_Sort(arr,n,mid+1,end);
    long long extra_Count = merge_Count(arr,start,mid,end);
    
    return (left_Count+right_Count+extra_Count);
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    if(n==0 || n==1)
    {
        return 0;
    }
    return merge_Sort(arr,n,0,n-1);
}

int main()
{
    int n;
    cin >> n;

    long long* arr = new long long[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    delete arr;
}
