#include <bits/stdc++.h>
using namespace std;

int getPair(int* arr, int start, int end,int sum)
{
    int pair_sum=0;
    while(start<end)
    {
        if(arr[start]+arr[end]<sum)
        {
            start++;
        }
        else if(arr[start]+arr[end]>sum)
        {
            end--;
        }
        else
        {
            if(arr[start]==arr[end])
            {
                int element_count = end-start+1;
                pair_sum += ((element_count*(element_count-1))/2);
                return pair_sum;
            }
            int startElement=arr[start];
            int endElement = arr[end];
            int tempStart=start+1;
            int tempEnd = end-1;
            while(tempStart<=tempEnd && arr[tempStart]==startElement)
            {
                tempStart++;
            }
            while(tempEnd>=tempStart && arr[tempEnd]==endElement)
            {
                tempEnd--;
            }
            int total_Elements_Start = tempStart-start;
            int total_Elements_End = end-tempEnd;
            pair_sum+=((total_Elements_Start)*(total_Elements_End));
            start=tempStart;
            end=tempEnd;
        }
    }
    return pair_sum;
}

int tripletSum(int *arr, int n, int num)
{
    int triplet_sum_pair = 0;
    for(int i=0;i<n-1;i++)
    {
        int sum = num-arr[i];
        int pair_sum = getPair(arr,i+1,n-1,sum);
        triplet_sum_pair+=pair_sum;
    }
    return triplet_sum_pair;
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
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        int num;
        cin>>num;
        sort(arr,arr+n);
        cout<<tripletSum(arr,n,num)<<endl;
    }

    return 0;
}
