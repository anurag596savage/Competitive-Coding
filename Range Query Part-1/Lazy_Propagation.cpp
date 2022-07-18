#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

void buildTree(int* arr,int n,int* segmentTree,int index,int start,int end)
{
	if(start==end)
	{
		segmentTree[index] = arr[start];
		return;
	}
	
	int mid = start+(end-start)/2;
	buildTree(arr,n,segmentTree,2*index,start,mid);
	buildTree(arr,n,segmentTree,2*index+1,mid+1,end);
	
	segmentTree[index] = min(segmentTree[2*index],segmentTree[2*index+1]);
	return;
}

void updateTreeLazy(int* segmentTree,int* lazyTree,int index,int start,int end,int left,int right,int value)
{
	if(left>right)
	{
		return;
	}
	
	// Let us do the pending work for the current node
	if(lazyTree[index]!=0)
	{
		segmentTree[index] += lazyTree[index];
		if(start!=end)
		{
			lazyTree[2*index] += lazyTree[index];
			lazyTree[2*index+1] += lazyTree[index];
		}
		lazyTree[index] = 0;
	}
	
	// If the range does not overlap at all
	if(start>right || end<left)
	{
		return;
	}
	
	// For complete overlap
	else if(start>=left && end<=right)
	{
		segmentTree[index] += value;
		if(start!=end)
		{
			lazyTree[2*index] += value;
			lazyTree[2*index+1] += value; 
		}
		
		return;
	}
	
	// For partial overlap
	else
	{
		int mid = start+(end-start)/2;
		updateTreeLazy(segmentTree,lazyTree,2*index,start,mid,left,right,value);
		updateTreeLazy(segmentTree,lazyTree,2*index+1,mid+1,end,left,right,value);
		
		segmentTree[index] = min(segmentTree[2*index],segmentTree[2*index+1]);
	}
}

int getQuery(int* segmentTree,int* lazyTree,int index,int start,int end,int left,int right)
{
	if(lazyTree[index]!=0)
	{
		segmentTree[index] += lazyTree[index];
		if(start!=end)
		{
			lazyTree[2*index] += lazyTree[index];
			lazyTree[2*index+1] += lazyTree[index];
		}
		lazyTree[index] = 0;
	}
	
	if(start==end)
	{
		return segmentTree[index];
	}
	
	else if(start>right || end<left)
	{
		return INT_MIN;
	}
	
	else if(start>=left && end<=right)
	{
		return segmentTree[index];
	}
	else
	{
		int mid = start+(end-start)/2;
		int a = getQuery(segmentTree,lazyTree,2*index,start,mid,left,right);
		int b = getQuery(segmentTree,lazyTree,2*index+1,mid+1,end,left,right);
		
		segmentTree[index] = min(a,b);
	}
}

int main()
{
	int n;
	cin>>n;
	
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int* segmentTree = new int[4*n];
	int* lazyTree = new int[4*n]();
	
	buildTree(arr,n,segmentTree,1,0,n-1);
	
	int x,y,value;
	cin>>x>>y>>value;
	updateTreeLazy(segmentTree,lazyTree,1,0,n-1,x-1,y-1,value);
	
	int l,r;
	cin>>l>>r;
	cout<<getQuery(segmentTree,lazyTree,1,0,n-1,l-1,r-1)<<endl;
	
	return 0;
}

