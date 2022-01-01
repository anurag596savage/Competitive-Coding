#include<bits/stdc++.h>
using namespace std;
int main()
{
    int size;
    cin>>size;
    string s;
    cin>>s;
    unordered_map<char,int> m;
    for(int i=0;i<s.length();i++)
    {
        m[s[i]]++;
    }
    cout<<m['a']<<" "<<m['s']<<" "<<m['p']<<endl;
}
