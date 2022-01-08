#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,ll> momos_total_price(ll* prefix_Sum, ll n, ll sum)
{
    ll ans=-1;
    ll start=0,end=n-1;
    while(start<=end)
    {
        ll mid=start+(end-start)/2;
        
        if(prefix_Sum[mid]<=sum)
        {
            ans=mid;
            start=mid+1;
        }else if(prefix_Sum[mid + 1] > sum && prefix_Sum[mid] < sum){
            ans = mid - 1;
            break;
        }else
        {
            end = mid-1;
        }
    }
    pair<ll,ll> p;
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
    ll arr[n];
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    ll prefix_Sum[n];
    prefix_Sum[0]=arr[0];
    for(ll i=1;i<n;i++)
    {
        prefix_Sum[i]=arr[i]+prefix_Sum[i-1];
    }
    ll t;
    cin>>t;
    while(t--)
    {
        ll sum;
        cin>>sum;
        pair<ll,ll> p= momos_total_price(prefix_Sum,n,sum);
        cout<<p.first<<" "<<p.second<<endl;
    }
    
    return 0;
}
