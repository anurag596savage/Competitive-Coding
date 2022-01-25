#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int first,second;
    cin>>first>>second;
    string s;
    cin>>s;
    long long int ans=0;
    long long int count=0;
    bool flag = false;
    for(int i=0;i<n;i++)
    {
        if(!flag && s[i]=='0')
        {
            count+=1;
            flag=true;
        }
        else if(flag && s[i]=='1')
        {
            flag=false;
        }
    }
    if(count==0)
    {
        cout<<ans<<endl;
    }
    else
    {
        ans = (count-1)*min(first,second)+second;
        cout<<ans<<endl;
    }

    return 0;
}
