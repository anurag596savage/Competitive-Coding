#include <bits/stdc++.h>
using namespace std;

int Product_Natural_Num(int n)
{
    int ans=1;
    int m = pow(10,9)+7;
    
    for(int i=2;i<=n;i++)
    {
        long long temp = ((long)(ans)*i)%m;
        ans = (int)temp%m;
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<Product_Natural_Num(n)<<endl;
    }

    return 0;
}
