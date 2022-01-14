#include <bits/stdc++.h>
using namespace std;

int Count_Subset(int* arr,int n,int current_Index,int k,int current_sum,int count)
{
    if(current_Index==n)
    {
        if(current_sum==k)
        {
            count++;
        }
        return count;
    }
    count = Count_Subset(arr,n,current_Index+1,k,current_sum+arr[current_Index],count);
    count = Count_Subset(arr,n,current_Index+1,k,current_sum,count);
    return count;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<Count_Subset(arr,n,0,k,0,0)<<endl;
    }
  
    return 0;
}
