#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n,m;
    cin>>n>>m;
    ll arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int current_count=0;
    int end = n-1;
    ll current_query;
    queue<ll>q;
    while(m--)
    {
        cin>>current_query;
        ll ans;
        for(;current_count<current_query;current_count++)
        {
            if(end>=0 && (q.empty() || (arr[end]>=q.front())))
            {
                ans = arr[end];
                end--;
            }
            else
            {
                ans = q.front();
                q.pop();
            }
            q.push(ans/2);
        }
        cout<<ans<<endl;
    }

    return 0;
}
