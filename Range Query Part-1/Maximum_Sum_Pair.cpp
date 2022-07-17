#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007


void buildTree(int* arr,int n,pair<int,int>* segmentTree,int index,int start,int end)
{
	
	if(start==end)
	{
		segmentTree[index].first = arr[start];
		segmentTree[index].second = INT_MIN;
		return;
	}
	
	int mid = start+(end-start)/2;
	buildTree(arr,n,segmentTree,2*index,start,mid);
	buildTree(arr,n,segmentTree,2*index+1,mid+1,end);
	
	segmentTree[index].first = max(segmentTree[2*index].first,segmentTree[2*index+1].first);
	segmentTree[index].second = min(max(segmentTree[2*index].first,segmentTree[2*index+1].second),
		max(segmentTree[2*index].second,segmentTree[2*index+1].first));
	return;
}


void updateTree(int* arr,int n,pair<int,int>* segmentTree,int index,int start,int end,int pos,int value)
{
	
	if(start==end)
	{
		arr[pos] = value;
		segmentTree[index].first = value;
		return;
	}
	
	int mid = start+(end-start)/2;
	if(pos<=mid)
	{
		updateTree(arr,n,segmentTree,2*index,start,mid,pos,value);
	}
	else
	{
		updateTree(arr,n,segmentTree,2*index+1,mid+1,end,pos,value);
	}
	
	segmentTree[index].first = max(segmentTree[2*index].first,segmentTree[2*index+1].first);
	segmentTree[index].second = min(max(segmentTree[2*index].first,segmentTree[2*index+1].second),
		max(segmentTree[2*index].second,segmentTree[2*index+1].first));
	
	return;
}

pair<int,int> getQuery(pair<int,int>* segmentTree,int index,int start,int end,int left,int right)
{
	if(left>end || right<start)
	{
		return make_pair(INT_MIN,INT_MIN);
	}
	else if(start>=left && end<=right)
	{
		return segmentTree[index];
	}
	
	else
	{
		int mid = start + (end-start)/2;
		pair<int,int>a = getQuery(segmentTree,2*index,start,mid,left,right);
		pair<int,int>b = getQuery(segmentTree,2*index+1,mid+1,end,left,right);
		pair<int,int>ans;
		ans.first = max(a.first,b.first);
		ans.second = min(max(a.first,b.second),max(a.second,b.first));
		return ans;
	}
	
}

int main()
{
	int n;
	cin>>n;
	
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	pair<int,int> segmentTree[4*n];
	
	buildTree(arr,n,segmentTree,1,0,n-1);
	
	
	int t;
	cin>>t;
	while(t--)
	{
		char ch;
		cin>>ch;
		int x,y;
		cin>>x>>y;
		if(ch=='U')
		{
			updateTree(arr,n,segmentTree,1,0,n-1,x-1,y);
		}
		else
		{
			pair<int,int> ans = getQuery(segmentTree,1,0,n-1,x-1,y-1);
			cout<<(ans.first+ans.second)<<endl;
		}
	}
	
	return 0;
}

