#include <iostream>
#include <cstring>
using namespace std;

void Replace_Character(char s[], char a, char b)
{
    if(s[0]=='\0')
    {
        return;
    }
    if(s[0]!=a)
    {
        Replace_Character(s+1,a,b);
    }
    else
    {
        s[0]=b;
        Replace_Character(s+1,a,b);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        char s[1000];
        cin>>s;
        char first,second;
        cin>>first>>second;
        Replace_Character(s,first,second);
        cout<<s<<endl;
    }
    return 0;
}
