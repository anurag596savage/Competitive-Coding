#include <bits/stdc++.h>
using namespace std;

int* prodExceptSelf(int arr[], int n)
{
    int* ans = new int[n];

    int lp=1;
    for(int i=0;i<n;i++)
    {
        ans[i]=lp;
        lp*=arr[i];

    }
    
    int rp=1;
    for(int i=n-1;i>=0;i--)
    {
        ans[i]*=rp;
        rp*=arr[i];
    }
    return ans;
}

int main()
{
    int arr[] = {1,2,3,4};
    int* ans = prodExceptSelf(arr,4);
    for(int i=0;i<4;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<4;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
