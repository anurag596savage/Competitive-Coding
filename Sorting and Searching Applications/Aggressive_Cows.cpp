#include <bits/stdc++.h>
using namespace std;

bool is_Possible(int* arr, int n,int c,int possible_ans)
{
    int count=1;
    int previous_stall=arr[0];
    for(int i=1;i<n;i++)
    {
        if(count==c)
        {
            return true;
        }
        int current_stall=arr[i];
        if((current_stall-previous_stall)>=possible_ans)
        {
            count++;
            previous_stall=current_stall;
        }
    }
    return (count==c);
}

int largest_Min_Distance(int* arr,int n,int c)
{
    int ans=-1;
    int start=0,end=arr[n-1]-arr[0];
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(is_Possible(arr,n,c,mid))
        {
           ans = mid;
            start=mid+1;
        }
        else
        {
            end = mid-1;
        }
    }
    return ans;   

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int c;
        cin>>c;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        cout<<largest_Min_Distance(arr,n,c)<<endl;
    }

    return 0;
}
