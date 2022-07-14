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
	
	int mid = (start+end)/2;
	buildTree(arr,n,segmentTree,start,mid,2*index);
	buildTree(arr,n,segmentTree,mid+1,end,2*index+1);
	
	segmentTree[index] = segmentTree[2*index]+segmentTree[2*index+1];
	return;
}


void updateTree(int* arr,int n,int* segmentTree,int index,int pos,int value,int start,int end)
{
	if(start==end)
	{
		arr[pos] = value;
		segmentTree[index] = value;
		return;
	}
	
	int mid = (start+end)/2;
	if(pos<=mid)
	{
		updateTree(arr,n,segmentTree,2*index,pos,value,start,mid);
	}
	else
	{
		updateTree(arr,n,segmentTree,2*index+1,pos,value,mid+1,end);
	}
	
	segmentTree[index] = segmentTree[2*index]+segmentTree[2*index+1];
	return;
}

int getQuery(int* segmentTree,int start,int end,int left,int right,int index)
{
	if(left>end || right<start)
	{
		return 0;
	}
	
	else if(start>=left && end<=right)
	{
		return segmentTree[index];
	}
	
	else
	{
		int mid = start+end/2;
		
		int a = getQuery(segmentTree,start,mid,left,right,2*index);
		int b = getQuery(segmentTree,mid+1,end,left,right,2*index+1);
		return a+b;
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
	int* segmentTree = new int[2*n];
	
	buildTree(arr,n,segmentTree,0,n-1,1);
	
	int pos,value;
	cin>>pos>>value;
	
	updateTree(arr,n,segmentTree,1,pos,value,0,n-1);
	
	for(int i=1;i<2*n;i++)
	{
		cout<<segmentTree[i]<<endl;
	}
	
	int left,right;
	cin>>left>>right;
	
	cout<<"The result of the interval : "<<getQuery(segmentTree,0,n-1,left,right,1)<<endl;
	
	return 0;
}

