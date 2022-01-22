#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[100000]={0};
    int max_x=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(arr[x/2]<y)
        {
            arr[x/2]=y;
        }

        if(x>max_x)
        {
            max_x = x;
        }

    }
    long long area=0;
    for(int i=max_x;i>0;i--)
    {
        if(arr[i]<arr[i+1])
        {
            arr[i]=arr[i+1];
        }
        
        area+=arr[i];
    }

    cout<<2*area<<endl;

    return 0;
}
