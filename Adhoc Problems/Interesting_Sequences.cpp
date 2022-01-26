#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,l;
    cin>>n>>k>>l;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int max_val = INT_MIN, min_val = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min_val)
        {
            min_val= arr[i];
        }
        if(arr[i]>max_val)
        {
            max_val = arr[i];
        }
    }
    
    long long int ans = LLONG_MAX;
    for(long long int i=min_val;i<=max_val;i++)
    {
        long long int decreasing=0,increasing=0;
        for(int j=0;j<n;j++)
        {
            if(arr[j]<i)
            {
                increasing += i-arr[j];
            }
            else if(arr[j]>i)
            {
                decreasing += arr[j]-i;
            }
        }
        
        if(decreasing>increasing)
        {
            continue;
        }
    	long long int possible_Ans=0;
        possible_Ans = (decreasing)*k + (increasing-decreasing)*l;
        ans = min(ans,possible_Ans);
    }

    cout<<ans<<endl;

    return 0;
}
