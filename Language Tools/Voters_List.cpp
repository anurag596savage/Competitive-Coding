#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    vector<int>v;
    for(int i=0;i<(a+b+c);i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    vector<int>output;
    for(int i=0;i<v.size()-1;)
    {
        int j=i+1;
        int count=1;
        while(v[j]==v[i])
        {
            count++;
            j++;
        }
        if(count>=2)
        {
            output.push_back(v[i]);
        }
        i=j;
    }
    cout<<output.size()<<endl;
    for(int i=0;i<output.size();i++)
    {
        cout<<output[i]<<endl;
    }

    return 0;
}
