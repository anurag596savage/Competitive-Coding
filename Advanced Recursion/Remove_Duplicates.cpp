#include <bits/stdc++.h>
using namespace std;

void Remove_Duplicates(char s[])
{
    if(s[0]=='\0')
    {
        return;
    }
    if(s[0]!=s[1])
    {
        Remove_Duplicates(s+1);
    }
    else
    {
        int i;
        for(i=1;s[i]!='\0';i++)
        {
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        Remove_Duplicates(s);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[10000];
        cin>>s;
        Remove_Duplicates(s);
        cout<<s<<endl;
    }
    return 0;
}
