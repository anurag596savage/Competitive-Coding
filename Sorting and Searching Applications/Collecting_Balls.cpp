#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool is_Possible(ll n,ll k)
{
    ll sum=0,current=n;
    while(current>0)
    {
        sum=sum+min(current,k);
        current=current-k;
        current=current-current/10;
    }
    if(2*sum>=n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

ll Find_K_Value(ll n)
{
    ll start=1,end=n;
    ll ans=INT_MAX;
    while(start<=end)
    {
        ll mid = start+(end-start)/2;
        if(is_Possible(n,mid))
        {
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}

int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        cout<<Find_K_Value(n)<<endl;
    }
    return 0;
}
