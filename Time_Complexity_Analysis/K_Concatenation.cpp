#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll kadane(int* arr, int n)
{
    ll current_sum=0,best_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        current_sum+=arr[i];
        best_sum=max(best_sum,current_sum);
        if(current_sum<0)
        {
            current_sum=0;
        }
    }
    return best_sum;
}

ll maxSumSubArray(int* arr, int n,int k)
{
    ll kadane_sum = kadane(arr,n);
    ll current_prefix_sum=0,best_prefix_sum=INT_MIN;

    for(int i=0;i<n;i++)
    {
        current_prefix_sum+=arr[i];
        best_prefix_sum=max(current_prefix_sum,best_prefix_sum);
    }
    ll total_sum = current_prefix_sum;
    ll current_suffix_sum=0,best_suffix_sum=INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        current_suffix_sum+=arr[i];
        best_suffix_sum=max(best_suffix_sum,current_suffix_sum);
    }
    if(k==1)
    {
        return kadane_sum;
    }
    if(total_sum>=0)
    {
        return max(best_suffix_sum+best_prefix_sum+total_sum*(k-2),kadane_sum);
    }
    else
    {
        return max(best_suffix_sum+best_prefix_sum,kadane_sum);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        int arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<maxSumSubArray(arr,n,k)<<endl;
    }
}
