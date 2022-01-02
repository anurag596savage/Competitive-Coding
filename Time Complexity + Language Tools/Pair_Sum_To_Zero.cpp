#include <bits/stdc++.h>
using namespace std;

int pairSum(int *arr, int n) 
{
    unordered_map<int,int> m;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int counter=-arr[i];
        if(m.find(counter)!=m.end())
        {
            ans+=m[counter];
        }
        m[arr[i]]++;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<pairSum(arr,n)<<endl;

    return 0;
}
