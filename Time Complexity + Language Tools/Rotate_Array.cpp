#include <bits/stdc++.h>
using namespace std;

void Reverse(int* arr,int start, int end)
{
    int i=start,j=end;
    while(i<j)
    {
        swap(arr[i],arr[i]);
        i++;
        j--;
    }
}

void rotate(int *input, int d, int n)
{
    if(n==0)
    {
        return;
    }
    if(d>=n)
    {
        d = d % n;
    }

    Reverse(input,0,n-1);
    Reverse(input,0,n-d-1);
    Reverse(input,n-d,n-1);
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
        int d;
        cin>>d;
        rotate(arr,d,n);
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
