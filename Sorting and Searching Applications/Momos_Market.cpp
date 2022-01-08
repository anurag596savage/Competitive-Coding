#include<bits/stdc++.h>
using namespace std;

pair<int,int> momos_total_price(int* prefix_Sum, int n,int sum)
{
    int ans=-1;
    int start=0,end=n-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        
        if(prefix_Sum[mid]<=sum)
        {
            ans=mid;
            start=mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    pair<int,int> p;
    p.first=ans+1;
    if(ans!=-1)
    {
     	p.second=sum-prefix_Sum[ans];   
    }
    else
    {
        p.second=sum;
    }
    
    return p;
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
    int prefix_Sum[n];
    prefix_Sum[0]=arr[0];
    for(int i=1;i<n;i++)
    {
        prefix_Sum[i]=arr[i]+prefix_Sum[i-1];
    }
    int t;
    cin>>t;
    while(t--)
    {
        int sum;
        cin>>sum;
        pair<int,int> p= momos_total_price(prefix_Sum,n,sum);
        cout<<p.first<<" "<<p.second<<endl;
    }
    
    return 0;
}
