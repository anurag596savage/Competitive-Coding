#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

struct Tree
{
	long long data;
	long long sum;	
};

struct Lazy
{
	int value;
	int query;	
};

void buildTree(int* arr,int n,struct Tree* segmentTree,int index,int start,int end)
{
	if(start==end)
	{
		segmentTree[index].data = (long long)arr[start]*arr[start];
		segmentTree[index].sum = (long long)arr[start];
		return;
	}
	
	int mid = start+(end-start)/2;
	buildTree(arr,n,segmentTree,2*index,start,mid);
	buildTree(arr,n,segmentTree,2*index+1,mid+1,end);
	
	segmentTree[index].data = segmentTree[2*index].data+segmentTree[2*index+1].data;
	segmentTree[index].sum = segmentTree[2*index].sum+segmentTree[2*index+1].sum;
	
	return;
}

void updateTree(struct Tree* segmentTree,struct Lazy* lazyTree,int index,int start,int end,int l,int r,int query,int value)
{
	if(start>end)
	{
		return;
	}
	if(lazyTree[index].value!=0)
	{
		if(lazyTree[index].query==1)
		{
			segmentTree[index].data += (end-start+1)*lazyTree[index].value*lazyTree[index].value+
			2*lazyTree[index].value*segmentTree[index].sum;
			segmentTree[index].sum += (end-start+1)*lazyTree[index].value;
			
			if(start!=end)
			{
				lazyTree[2*index].value += lazyTree[index].value;
				lazyTree[2*index].query = lazyTree[index].query;
				lazyTree[2*index+1].value += lazyTree[index].value;
				lazyTree[2*index+1].query = lazyTree[index].query;
			}
		}
		else if(lazyTree[index].query==0)
		{
			segmentTree[index].data = (end-start+1)*lazyTree[index].value*lazyTree[index].value;
			segmentTree[index].sum = (end-start+1)*lazyTree[index].value;
			if(start!=end)
			{
				lazyTree[2*index].value = lazyTree[index].value;
				lazyTree[2*index].query = lazyTree[index].query;
				lazyTree[2*index+1].value = lazyTree[index].value;
				lazyTree[2*index+1].query = lazyTree[index].query;
			}
		}
		
		lazyTree[index].value = 0;
	}
	
	if(start>r || end<l)
	{
		return;
	}
	
	else if(start>=l && end<=r)
	{
		if(query==1)
		{
			segmentTree[index].data += (end-start+1)*value*value+2*value*segmentTree[index].sum;
			segmentTree[index].sum += (end-start+1)*value;
			if(start!=end)
			{
				lazyTree[2*index].value += value;
				lazyTree[2*index].query = query;
				lazyTree[2*index+1].value += value;
				lazyTree[2*index+1].query = query;
			}
		}
		else
		{
			segmentTree[index].data = (end-start+1)*value*value;
			segmentTree[index].sum = (end-start+1)*value;
			if(start!=end)
			{
				lazyTree[2*index].value = value;
				lazyTree[2*index].query = query;
				lazyTree[2*index+1].value = value;
				lazyTree[2*index+1].query = query;
			}
		}
		return;
	}
	
	else
	{
		int mid = start+(end-start)/2;
		updateTree(segmentTree,lazyTree,2*index,start,mid,l,r,query,value);
		updateTree(segmentTree,lazyTree,2*index+1,mid+1,end,l,r,query,value);
		segmentTree[index].data = segmentTree[2*index].data+segmentTree[2*index+1].data;
		segmentTree[index].sum = segmentTree[2*index].sum+segmentTree[2*index+1].sum;
		
		return;
	}
}

struct Tree getQuery(struct Tree* segmentTree,struct Lazy* lazyTree,int index,int start,int end,int l,int r)
{
	if(lazyTree[index].value!=0)
	{
		
		if(lazyTree[index].query==1)
		{
			segmentTree[index].data += (end-start+1)*lazyTree[index].value*lazyTree[index].value+
			2*lazyTree[index].value*segmentTree[index].sum;
			segmentTree[index].sum += (end-start+1)*lazyTree[index].value;
			if(start!=end)
			{
				lazyTree[2*index].value += lazyTree[index].value;
				lazyTree[2*index].query = lazyTree[index].query;
				lazyTree[2*index+1].value += lazyTree[index].value;
				lazyTree[2*index+1].query = lazyTree[index].query;
			}
		}
		else
		{
			segmentTree[index].data = (end-start+1)*lazyTree[index].value*lazyTree[index].value;
			segmentTree[index].sum = (end-start+1)*lazyTree[index].value;
			if(start!=end)
			{
				lazyTree[2*index].value = lazyTree[index].value;
				lazyTree[2*index].query = lazyTree[index].query;
				lazyTree[2*index+1].value = lazyTree[index].value;
				lazyTree[2*index+1].query = lazyTree[index].query;
			}
		}
		
		lazyTree[index].value = 0;
	}
	else if(start>r || end<l)
	{
		struct Tree ans;
		ans.data = 0;
		ans.sum = 0;
		return ans;
	}
	else if(start>=l && end<=r)
	{
		return segmentTree[index];
	}
	else
	{
		int mid = start+(end-start)/2;
		struct Tree a = getQuery(segmentTree,lazyTree,2*index,start,mid,l,r);
		struct Tree b = getQuery(segmentTree,lazyTree,2*index+1,mid+1,end,l,r);
		
		struct Tree ans;
		ans.data = a.data+b.data;
		ans.sum = a.sum+b.sum;
		
		return ans; 
	}
}


int main()
{
	int t;
	cin>>t;
	
	while(t--)
	{
		int n,q;
		cin>>n>>q;
		
		int* arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		struct Tree* segmentTree = new Tree[4*n];
		struct Lazy* lazyTree = new Lazy[4*n];
		for(int i=1;i<4*n;i++)
		{
			lazyTree[i].value = 0;
		}
		buildTree(arr,n,segmentTree,1,0,n-1);
		
		
		while(q--)
		{
			int query;
			cin>>query;
			int x,y;
			cin>>x>>y;
			if(query==2)
			{
				struct Tree ans = getQuery(segmentTree,lazyTree,1,0,n-1,x-1,y-1);
				cout<<ans.data<<endl;
			}
			else
			{
				int value;
				cin>>value;
				updateTree(segmentTree,lazyTree,1,0,n-1,x-1,y-1,query,value);
			}
		}
		
		
	}
	
	return 0;
}

