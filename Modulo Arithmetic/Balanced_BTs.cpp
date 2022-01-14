#include <bits/stdc++.h>
using namespace std;

int Balanced_BTs(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    int x = Balanced_BTs(n-1);
    int y = Balanced_BTs(n-2);

    int m = pow(10,9)+7;

    long res1 = (long)x*x; 
    long res2 = (long)x*y*2;

    int ans1 = (int)(res1%m);
    int ans2 = (int)(res2%m);

    int ans = (ans1+ans2)%m;

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
        cout<<Balanced_BTs(n)<<endl;
    }

    return 0;
}
