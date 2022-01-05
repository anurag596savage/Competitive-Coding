#include <bits/stdc++.h>
using namespace std;

bool is_Possible(long long* arr,long long n,long long k,long long possible_Answer)
{
    long long count=0;
    
    for(int i=0;i<n;i++)
    {
        
        long long persons = arr[i]/possible_Answer;
        count+=persons;
        if(count>=k)
        {
            
            return true;
        }
        
    }
    
    return false;
    
}

long long Max_Chocolates_Distribution(long long* arr, long long n, long long k,long long sum)
{
    long long start=0,end=sum;
    long long ans = 0;
    while(start<=end)
    {
        long long mid = start + (end-start)/2;
        if(is_Possible(arr,n,k,mid))
        {
            ans=mid;
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,k;
        cin>>n>>k;
        long long arr[n];
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        cout<<Max_Chocolates_Distribution(arr,n,k,sum)<<endl;
    }

    return 0;
}
