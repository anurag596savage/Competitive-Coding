#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

bool compare(int a,int b)
{
	return a>b;
}

int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>v(n);
		
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
		}
		sort(v.begin(),v.end(),compare);
		
		long ans = 0;
		
		for(int i=0;i<n;i++)
		{
			ans += (long)v[i]*pow(2,i);
		}
		cout<<ans<<endl;
		
	}
	
	return 0;
}

