#include <bits/stdc++.h>
using namespace std;

int Find_Window(int* arr, int n)
{
    int time[n];
    int index=-1;
    int ans = INT_MAX;
    // Condition is i+t*n>=arr[i]=>t>=(arr[i]-i)/n
    for(int i=0;i<n;i++)
    {
        if((arr[i]-i)%n>0)
        {
            time[i]=((arr[i]-i)/n)+1;
        }
        else if((arr[i]-i)<0)
        {
            time[i]=0;
        }
        else
        {
            time[i]=(arr[i]-i)/n;
        }
    }
    int total_ans[n];
    for(int i=0;i<n;i++)
    {
        total_ans[i]=i+time[i]*n;
        if(total_ans[i]<ans)
        {
            ans=total_ans[i];
            index=i;
        }
    }
    return index+1;
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
    cout<<Find_Window(arr,n)<<endl;
    
  return 0;
}
