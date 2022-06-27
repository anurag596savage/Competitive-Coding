#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

bool compare(pair<int,int>a,pair<int,int>b)
{
	return a.second<b.second;
}

int main()
{
	int n;
	cin>>n;
	
	vector<pair<int,int>>v(n);
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first;
		cin>>v[i].second;
	}
	
	sort(v.begin(),v.end(),compare);
	
	int ans = 1;
	int current = v[0].second;
	for(int i=1;i<n;i++)
	{
		if(v[i].first>=current)
		{
			ans = ans + 1;
			current = v[i].second; 
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}

