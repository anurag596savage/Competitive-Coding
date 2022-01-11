#include <iostream>
using namespace std;

int Subsequence(string s,string output[])
{
    if(s.empty())
    {
        output[0]="";
        return 1;
    }
    string smallString = s.substr(1);
    int smallAns = Subsequence(smallString,output);
    for(int i=0;i<smallAns;i++)
    {
        output[i+smallAns]=s[0]+output[i];
    }

    return 2*smallAns;
}

int main()
{
    string s;
    cin>>s;
    string* sp = new string[1000];
    int count = Subsequence(s,sp);
    for(int i=0;i<count;i++)
    {
        cout<<sp[i]<<endl;
    }

    return 0;
}
