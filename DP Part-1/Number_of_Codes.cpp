#include <bits/stdc++.h>
using namespace std;

int Num_Codes_DP(int* arr,int size)
{
    if(size==0 || size==1)
    {
        return 1;
    }
    int* output = new int[size+1];
    output[0] = 1;
    output[1] = 1;
    for(int i=2;i<=size;i++)
    {
        output[i]=output[i-1];
        if(10*arr[i-2]+arr[i-1]<=26)
        {
            output[i]+=output[i-2];
        }
    }
    int ans = output[size];
    delete []output;
    return ans;
}

int Num_Codes_Memoization(int* arr,int size,int* output)
{
    if(size==0 || size==1)
    {
        return 1;
    }

    if(output[0]!=0)
    {
        return output[size];
    }
    int ans = Num_Codes_Memoization(arr,size-1,output);
    if(arr[size-2]*10+arr[size-1]<=26)
    {
        ans+=Num_Codes_Memoization(arr,size-2,output);
    }
    output[size] = ans;
    return ans;
}

int Num_Codes_Recursive(int* arr,int size)
{
    if(size==0 || size==1)
    {
        return 1;
    }

    int output = Num_Codes_Recursive(arr,size-1);
    if(arr[size-2]*10+arr[size-1]<=26)
    {
        output+=Num_Codes_Recursive(arr,size-2);
    }
    return output;
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
    cout<<Num_Codes_Recursive(arr,n)<<endl;

    int *output = new int[n+1];
    for(int i=0;i<=n;i++)
    {
        output[i]=0;
    }
    cout<<Num_Codes_Memoization(arr,n,output)<<endl;

    cout<<Num_Codes_DP(arr,n)<<endl;

    delete[] output;

    return 0;
}
