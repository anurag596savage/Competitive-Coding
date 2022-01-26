#include <bits/stdc++.h>
using namespace std;

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
        bool flag = true;
        int cost = 0;
        for(int i=0;i<n;i++)
        {
            if(abs(arr[i]-(i+1))>2)
            {
                flag = false;
                break;
            }
            if(arr[i]>i+1)
            {
                cost+=(arr[i]-(i+1));
            }
            if(i>=2 && arr[i]-arr[i-2]==-2)
            {
                cost = cost + 1;
            }
        }
        if(flag)
        {
            cout<<"YES"<<endl;
            cout<<cost<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
