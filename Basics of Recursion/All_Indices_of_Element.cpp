
#include<iostream>
using namespace std;



int allIndexes(int input[], int size, int x, int output[]) {
  
    if(size==0)
    {
        return 0;
    }
    bool flag = (input[0]==x);
    int ans = allIndexes(input+1,size-1,x,output);
    if(ans>0)
    {
        for(int i=0;i<ans;i++)
        {
            output[i]+=1;
        }
        if(!flag)
        {
            return ans;
        }
        else if(flag)
        {
            int i;
            for(i=ans;i>0;i--)
            {
                output[i]=output[i-1];
            }
            output[i]=0;
            return ans+1;
        }
    }
    if(ans==0)
    {
        if(flag)
        {
            output[0]=0;
            return 1;
        }
        else
        {
            return 0;
        }
    }

}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}
