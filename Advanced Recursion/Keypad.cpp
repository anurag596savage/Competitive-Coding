#include <iostream>
using namespace std;

string s[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int Keypad(int n,string output[])
{
    if(n==0 || n==1)
    {
        output[0]="";
        return 1;
    }
    int smallCount=Keypad(n/10,output);
    int digit=n%10;
    int digit_length=s[digit].length();
    for(int i=0;i<smallCount;i++)
    {
        for(int j=1;j<digit_length;j++)
        {
            output[i+smallCount*j]=output[i];
        }
    }
    for(int i=0;i<smallCount;i++)
    {
        for(int j=0;j<digit_length;j++)
        {
            output[i+smallCount*j]=output[i+smallCount*j] + s[digit][j];
        }
    }
    return digit_length*smallCount;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string output[10000];
        int count = Keypad(n,output);
        for(int i=0;i<count && count<10000;i++)
        {
            cout<<output[i]<<endl;
        }
    }
    return 0;
}
