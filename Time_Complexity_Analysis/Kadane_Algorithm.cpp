#include <iostream>
#include <climits>
using namespace std;

int kadane(int* arr, int n)
{
    int current_sum=0;
    int best_sum=INT_MIN;
    for(int i=0;i<n;i++)
    {
        current_sum+=arr[i];
        if(best_sum<current_sum)
        {
            best_sum=current_sum;
        }
        if(current_sum<0)
        {
            current_sum=0;
        }
    }
    return best_sum;
    
}

int main()
{
    int arr[]={1,5,7,-12,4};
    int n=5;
    cout<<"The largest subarray sum is "<<kadane(arr,n)<<endl;
    return 0;
}
