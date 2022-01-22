#include <bits/stdc++.h>
using namespace std;

int Cost_String_Equalise(string s,string t,int n)
{
    int cost = 0;
    int i=0;
    while(i<n)
    {
        if(s[i]==t[i])
        {
            i++;
        }
        else if(i<n && s[i]!=s[i+1] && s[i+1]!=t[i+1])
        {
            cost+=1;
            i+=2;
        }
        else
        {
            cost++;
            i++;
        }
    }
    return cost;
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string t;
    cin>>t;
    cout<<Cost_String_Equalise(s,t,n)<<endl;
    
    return 0;
}
