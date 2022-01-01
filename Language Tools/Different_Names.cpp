#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write your code here
    map<string,int> m;
    while(1)
    {
        string s;
        cin>>s;
        if(s.length()==0)
        {
            break;
        }
        m[s]++;
    }
    int count=0;
    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        if(it->second>1)
        {
         	cout<<it->first<<" "<<it->second<<endl;   
            count++;
        }
    }
    if(!count)
    {
        cout<<"-1"<<endl;
    }
}
