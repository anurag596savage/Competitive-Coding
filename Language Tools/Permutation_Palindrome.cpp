#include <bits/stdc++.h>
using namespace std;

char getChar(int i)
{
    return (char)(i+97);
}

vector<int> Permutation_Palindrome(string str)
{
    map<char,vector<int>> m;
    for(int i=0;i<str.length();i++)
    {
        m[str[i]].push_back(i);
    }
    vector<int> ans(str.length());
    int odd_count=0;
    for(int i=0;i<26;i++)
    {
       if(m[getChar(i)].size()%2>0)
       {
           odd_count++;
       }
    }
    if(odd_count>1)
    {
        vector<int> v;
        v.push_back(-1);
        return v;
    }
    int resultant_start=0,resultant_end=str.length()-1;
    map<char,vector<int>>::iterator it;
    for(it=m.begin();it!=m.end();it++)
    {
        int j=0;
        if(it->second.size()%2>0)
        {
            ans[str.length()/2]=it->second[j++]+1;
        }
        while(j<(it->second).size())
        {
            ans[resultant_start]=it->second[j++]+1;
            ans[resultant_end]=it->second[j++]+1;
            resultant_start++;
            resultant_end--;
        }
    }
    return ans;
    
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        vector<int> ans = Permutation_Palindrome(str);
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
