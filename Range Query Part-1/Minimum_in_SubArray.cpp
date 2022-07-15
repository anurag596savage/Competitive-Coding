#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

void buildTree(int* arr,int n,int* segmentTree,int start,int end,int index)
{
	if(start==end)
	{
		segmentTree[index] = arr[start];
		return;
	}
	int mid = start+(end-start)/2;
	buildTree(arr,n,segmentTree,start,mid,2*index);
	buildTree(arr,n,segmentTree,mid+1,end,2*index+1);
	
	segmentTree[index] = min(segmentTree[2*index],segmentTree[2*index+1]);
	return;
}

void updateTree(int* arr,int n,int* segmentTree,int start,int end,int index,int pos,int value)
{
	if(start==end)
	{
		arr[pos] = value;
		segmentTree[index] = value;
		return;
	}
	
	int mid = start+(end-start)/2;
	if(pos<=mid)
	{
		updateTree(arr,n,segmentTree,start,mid,2*index,pos,value);
	}
	else
	{
		updateTree(arr,n,segmentTree,mid+1,end,2*index+1,pos,value);
	}
	
	segmentTree[index] = min(segmentTree[2*index],segmentTree[2*index+1]);
	return;
}

int getQuery(int* segmentTree,int start,int end,int left,int right,int index)
{
	if(start>right || end<left)
	{
		return INT_MAX;
	}
	else if(start>=left && end<=right)
	{
		return segmentTree[index];
	}
	else
	{
		int mid = start+(end-start)/2;
		int a = getQuery(segmentTree,start,mid,left,right,2*index);
		int b = getQuery(segmentTree,mid+1,end,left,right,2*index+1);
		
		return min(a,b);
	}
}

int main()
{
	int n,t;
	cin>>n>>t;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int segmentTree[2*n];
	buildTree(arr,n,segmentTree,0,n-1,1);
	while(t--)
	{
		char ch;
		cin>>ch;
		int x,y;
		cin>>x>>y;
		if(ch=='q')
		{
			int left,right;
			left = x;
			right = y;
			cout<<getQuery(segmentTree,0,n-1,left-1,right-1,1)<<endl;
		}
		else 
		{
			int pos,value;
			pos = x;
			value = y;
			updateTree(arr,n,segmentTree,0,n-1,1,pos-1,value);
		}
	}
	
	
	return 0;
}

