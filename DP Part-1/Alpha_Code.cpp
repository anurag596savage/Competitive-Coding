#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int CharToInt(char ch)
{
    int x = ch - '0';
    return x;
}

int Alpha_Code_Recursive(string &s, int n, int* arr)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    if(arr[n]!=-1)
    {
        return arr[n];
    }
    int count = Alpha_Code_Recursive(s,n-1,arr);
    if(10*CharToInt(s[n-2])+CharToInt(s[n-1])<=26)
    {
        count=(Alpha_Code_Recursive(s,n-2,arr) + count) % mod;
    }

    arr[n] = count;
    return count;

}

    
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        cin>>s;
        int n = s.length();
        int arr[n+1];
        for(int i=0;i<=n;i++)
        {
            arr[i]=-1;
        }
        bool flag = true;
        for(int i=0;i<s.size()-1;i++)
        {
            if(s[i]=='0' && s[i+1]=='0')
            {
                cout<<0<<endl;
                flag = false;
                break;
            }
        }

        if(flag)
        {
            cout<<Alpha_Code_Recursive(s,n,arr)<<endl;
        }

    }

    return 0;
}
