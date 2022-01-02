#include <bits/stdc++.h>
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    // Your Code goes here
    unordered_map<int,bool>m;
    unordered_map<int,int>index;
    int start=0;
    int count=0;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]=true;
        index[arr[i]]=i;
    }
    for(int i=0;i<n;i++)
    {
        if(m[arr[i]]==false)
        {
            continue;
        }
        int current_count=1;
        m[arr[i]]=false;
        int current_element=arr[i];
        int j=1;
        while(m.find(current_element+j)!=m.end())
        {
            current_count++;
            m[current_element+j]=false;
            j++;
        }
        int k = 1;
        while(m.find(current_element-k)!=m.end())
        {
            current_count++;
            m[current_element-k]=false;
            k++;
        }
        int starting_index = index[arr[i]-k+1];
        if(current_count>count || (current_count==count && starting_index<index[start]))
        {
            count=current_count;
            start=arr[i]-k+1;
        }
    }
    vector<int>v;
    if(count==1)
    {
        v.push_back(start);
    }
    else
    {
        v.push_back(start);
        v.push_back(start+count-1);
    }

    return v;
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
    vector<int> ans = longestConsecutiveIncreasingSequence(arr,n);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}
