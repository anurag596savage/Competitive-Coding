#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int i=0,j=1;
    int ans=0;
    while(j<n)
    {
        if(abs(arr[i]-arr[j])<k)
        {
            j++;
        }
        if(abs(arr[i]-arr[j])>=k)
        {
            ans+=n-j;
            i++;
            if(i==j)
            {
                j++;
            }
        }
    }
    cout<<ans<<endl;

    return 0;
}
