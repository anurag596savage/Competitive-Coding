#include <iostream>
using namespace std;

string s[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void Print_Keypad(int n,string output)
{
    if(n==0 || n==1)
    {
        cout<<output<<endl;
        return;
    }

    int digit=n%10;
    for(int i=0;i<s[digit].length();i++)
    {
        Print_Keypad(n/10,s[digit][i]+output);
    }
}

int main()
{
    int n;
    cin>>n;
    string output="";
    Print_Keypad(n,output);

    return 0;
}
