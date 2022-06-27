#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int* arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		
		sort(arr,arr+n);
		
		int minima = INT_MAX;
		
		for(int i=1;i<n;i++)
		{
			minima = min(minima,arr[i]-arr[i-1]); 
		}
		
		cout<<minima<<endl;
	}
	
	return 0;
}

