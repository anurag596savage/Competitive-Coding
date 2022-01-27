#include <bits/stdc++.h>
using namespace std;

int Fibonacci_DP(int n)
{
    int *arr = new int[n+1];
    arr[0] = 1;
    arr[1] = 1;
    for(int i=2;i<=n;i++)
    {
        arr[i] = arr[i-1]+arr[i-2];
    }

    int ans = arr[n];
    delete[] arr;
    return ans;
}

int Fibonacci_Memoization(int n,int* arr)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    if(arr[n]!=0)
    {
        return arr[n];
    }

    int output = Fibonacci_Memoization(n-1,arr)+Fibonacci_Memoization(n-2,arr);
    arr[n] = output;
    return output;
}

int Fibonacci_Recursive(int n)
{

    if(n==0 || n==1)
    {
        return 1;
    }

    return Fibonacci_Recursive(n-1)+Fibonacci_Recursive(n-2);
}

int main()
{
    int n;
    cin>>n;

    cout<<Fibonacci_Recursive(n)<<endl;
    
    int *arr = new int[n+1];
    for(int i=0;i<=n;i++)
    {
        arr[i] = 0;
    }
    cout<<Fibonacci_Memoization(n,arr)<<endl;

    cout<<Fibonacci_DP(n)<<endl;

    delete []arr;

    return 0;
}
