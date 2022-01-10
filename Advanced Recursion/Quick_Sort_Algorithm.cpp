#include <bits/stdc++.h>
using namespace std;

int Partition(int* arr,int start,int end)
{
    int element = arr[start];
    int count=0;
    for(int i=start+1;i<=end;i++)
    {
        if(arr[i]<=element)
        {
            count++;
        }
    }
    if(count==0)
    {
        return start;
    }
    else
    {
        int temp=arr[start];
        arr[start]=arr[start+count];
        arr[start+count]=temp;
        int position = start+count;

        int i=start,j=end;
        while(i<position && j>position)
        {
            if(arr[i]<=arr[position])
            {
                i++;
            }
            else if(arr[j]>arr[position])
            {
                j--;
            }
            else
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;
                j--;
            }
        }

        return position;

    }
}

void quick_Sort(int* arr,int n,int start,int end)
{
    if(start>=end)
    {
        return;
    }
    int index = Partition(arr,start,end);
    quick_Sort(arr,n,start,index-1);
    quick_Sort(arr,n,index+1,end);
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
        quick_Sort(arr,n,0,n-1);
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
