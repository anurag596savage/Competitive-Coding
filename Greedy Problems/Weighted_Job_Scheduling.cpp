#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

class Triplet
{
	public :
	
	int start;
	int finish;
	int profit;	
};

bool compare(Triplet a,Triplet b)
{
	return a.finish<b.finish;
}

int main()
{
	int n;
	cin>>n;
	
	vector<Triplet>v(n);
	
	for(int i=0;i<n;i++)
	{
		Triplet t;
		cin>>t.start>>t.finish>>t.profit;
		v[i] = t;
	}
	
	sort(v.begin(),v.end(),compare);
	
	int* dp = new int[n];
	
	dp[0] = v[0].profit;
	
	for(int i=1;i<n;i++)
	{
		int latest=-1;
		int including = v[i].profit;
		
		/*
		
		for(int j=i-1;j>=0;j--)
		{
			if(v[j].finish<=v[i].start)
			{
				latest = j;
				break;
			}
		}
		*/
		int start = 0,end = i-1;
		while(start<=end)
		{
			int mid = start + (end-start)/2;
			if(v[mid].finish<=v[i].start)
			{
				if(v[mid+1].finish<=v[i].start)
				{
					start = mid+1;
				}
				else
				{
					latest = mid;
					break;
				}
			}
			else
			{
				end = mid - 1;
			}	
		}
		
		if(latest!=-1)
		{
			including += dp[latest];
		}
		dp[i] = max(including,dp[i-1]);
	}
	
	cout<<dp[n-1]<<endl;
	
	
	return 0;
}

