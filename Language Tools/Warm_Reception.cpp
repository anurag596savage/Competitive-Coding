#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int arrival[n];
    for(int i=0;i<n;i++)
    {
        cin>>arrival[i];
    }
    int departure[n];
    for(int i=0;i<n;i++)
    {
        cin>>departure[i];
    }
    sort(arrival,arrival+n);
    sort(departure,departure+n);
    int ans = 1;
    int i=1,j=0;
    int current_count=1;
    while(i<n && j<n)
    {
        if(arrival[i]<departure[j])
        {
            current_count++;
            i++;
        }
        else
        {
            current_count--;
            j++;
        }
        ans = max(ans,current_count);
    }
    cout<<ans<<endl;

    return 0;
}
