#include <bits/stdc++.h>
using namespace std;

int findDuplicate(int *arr, int n)
{
    /*
    // Method-1
    int possible_sum=0;
    for(int i=0;i<n-1;i++)
    {
        possible_sum+=i;
    }
    int actual_sum=0;
    for(int i=0;i<n;i++)
    {
        actual_sum+=arr[i];
    }
    int ans = actual_sum-possible_sum;
    return ans;
    */
    // Method-2
    unordered_map<int,int> freq_count;
    for(int i=0;i<n;i++)
    {
        freq_count[arr[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(freq_count[arr[i]]>1)
        {
            return arr[i];
        }
    }
    
    return -1;
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
        cout<<findDuplicate(arr,n)<<endl;
    }

    return 0;
}
