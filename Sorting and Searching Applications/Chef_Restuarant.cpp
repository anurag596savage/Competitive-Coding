#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            v.push_back(make_pair(a,b));
        }

        sort(v.begin(),v.end());

        while(m--)
        {
            int current_time;
            cin>>current_time;
            int position = lower_bound(v.begin(),v.end(),make_pair(current_time,0))-v.begin();
            if(position==0)
            {
                int ans = v[0].first-current_time;
                cout<<ans<<endl;
            }
            else
            {
                int ans = -1;
                if(current_time<v[position-1].second)
                {
                    ans = 0;
                }
                else if(position<v.size())
                {
                    ans = v[position].first-current_time;
                }
                cout<<ans<<endl;
            }
        }
    }
}
