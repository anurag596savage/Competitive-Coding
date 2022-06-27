#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

bool compare(pair<int,int> a,pair<int,int> b)
{
	double x = (double)a.first/(double)a.second;
	double y = (double)b.first/(double)b.second;
	
	return x>y;
}

int main()
{
	int n,capacity;
	cin>>n>>capacity;
	
	vector<pair<int,int>>v(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first; // value
		cin>>v[i].second; // weight
	}
	
	sort(v.begin(),v.end(),compare);
	
	
	double current=0;
	double ans=0;
	int i=0;
	while(i<n && current<capacity)
	{
		if(v[i].second+current<=capacity)
		{
			current += v[i].second;
			ans += v[i].first;
			i++;
		}
		else
		{
			ans += ((double)(capacity-current)/(double)v[i].second)*v[i].first;
			break;
		}
	}
	cout<<setprecision(6)<<fixed;
	cout<<ans<<endl;
	
	return 0;
}

