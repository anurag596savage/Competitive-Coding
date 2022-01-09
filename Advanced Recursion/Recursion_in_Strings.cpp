#include <iostream>
#include <cstring>
using namespace std;

void RemoveChar(char s[])
{
    if(s[0]=='\0')
    {
        return;
    }
    if(s[0]!='x')
    {
        RemoveChar(s+1);
    }
    else
    {
        int i;
        for(i=1;s[i]!='\0';i++)
        {
            s[i-1]=s[i];
        }
        s[i-1]=s[i];
        RemoveChar(s);
    }
}

int length(char s[])
{
    if(s[0]=='\0')
    {
        return 0;
    }
    int smallAns=length(s+1);
    return 1+smallAns;
}

int main()
{
    char s[1000];
    cin>>s;
    cout<<length(s)<<endl;
    char str[1000];
    cin>>str;
    RemoveChar(str);
    cout<<str;

    return 0;
}
