#include <iostream>
using namespace std;

void Print_Subsequence(string s, string output)
{
    if(s.length()==0)
    {
        cout<<output<<endl;
        return;
    }
    
    Print_Subsequence(s.substr(1),output);
    Print_Subsequence(s.substr(1),output+s[0]);
}

int main()
{
    string s;
    cin>>s;
    string output="";
    Print_Subsequence(s,output);

    return 0;
}
