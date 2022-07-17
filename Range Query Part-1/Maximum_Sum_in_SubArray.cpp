#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

struct node
{
	int max_sum;
	int best_prefix_sum;
	int best_suffix_sum;
	int sum;	
};



void builtTree(int* arr,int n,struct node* segmentTree,int index,int start,int end)
{
	
	if(start==end)
	{
		segmentTree[index].max_sum = arr[start];
		segmentTree[index].best_prefix_sum = arr[start];
		segmentTree[index].best_suffix_sum = arr[start];
		segmentTree[index].sum = arr[start];
		
		return;
	}
	
	
	int mid = start+(end-start)/2;
	
	builtTree(arr,n,segmentTree,2*index,start,mid);
	builtTree(arr,n,segmentTree,2*index+1,mid+1,end);
	
	segmentTree[index].best_prefix_sum = max({segmentTree[2*index].best_prefix_sum,
		segmentTree[2*index].sum+segmentTree[2*index+1].best_prefix_sum});
	
	segmentTree[index].best_suffix_sum = max({segmentTree[2*index+1].best_suffix_sum,
		segmentTree[2*index+1].sum+segmentTree[2*index].best_suffix_sum});
	
	segmentTree[index].sum = segmentTree[2*index].sum+segmentTree[2*index+1].sum;
	
	segmentTree[index].max_sum = max({segmentTree[2*index].max_sum,segmentTree[2*index+1].max_sum,
		segmentTree[2*index].sum+segmentTree[2*index+1].best_prefix_sum,
		segmentTree[2*index].best_suffix_sum+segmentTree[2*index+1].sum,
		segmentTree[2*index].best_suffix_sum+segmentTree[2*index+1].best_prefix_sum,
		segmentTree[2*index].sum+segmentTree[2*index+1].sum});

	
	return;
}

struct node getQuery(struct node* segmentTree,int index,int start,int end,int left,int right)
{
	if(start>right || end<left)
	{
		struct node temp;
		temp.max_sum = -10000;
		temp.best_prefix_sum = -100000;
		temp.best_suffix_sum = -100000;
		temp.sum = -100000;
		return temp;
	}
	else if(start>=left && end<=right)
	{
		return segmentTree[index];
	}
	else
	{
		int mid = start+(end-start)/2;
		struct node a = getQuery(segmentTree,2*index,start,mid,left,right);
		struct node b = getQuery(segmentTree,2*index+1,mid+1,end,left,right);
		struct node ans;
        
		ans.max_sum = max({a.max_sum,b.max_sum,a.sum+b.best_prefix_sum,
			a.best_suffix_sum+b.sum,a.best_suffix_sum+b.best_prefix_sum,a.sum+b.sum});
	
		ans.best_prefix_sum = max({a.best_prefix_sum,a.sum+b.best_prefix_sum});
	
		ans.best_suffix_sum = max({b.best_suffix_sum,b.sum+a.best_suffix_sum});
	
		ans.sum = a.sum+b.sum;
		
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
	struct node segmentTree[4*n];
	builtTree(arr,n,segmentTree,1,0,n-1);
	
	
	int t;
	cin>>t;
	while(t--)
	{
		int x,y;
		cin>>x>>y;
		
		cout<<getQuery(segmentTree,1,0,n-1,x-1,y-1).max_sum<<endl;
	}
	
	return 0;
}

