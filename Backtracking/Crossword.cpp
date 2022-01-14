#include <bits/stdc++.h>
using namespace std;

#define N 10

bool is_Valid_Vertical(char arr[N][N],int row,int col,string words[],int current_Index,int word_size)
{
    int space = N-row;
    if(space<word_size)
    {
        return false;
    }
    for(int i=0;i<(word_size);i++)
    {
        if(arr[i+row][col]=='-' || arr[i+row][col]==words[current_Index][i])
        {
            continue;
        }
        else
        {
            return false;
        }
        
    }

    return true;
}
bool is_Valid_horizontal(char arr[N][N],int row,int col,string words[],int current_Index,int word_size)
{
    int space = N-col;
    if(space<word_size)
    {
        return false;
    }
    for(int j=0;j<(word_size);j++)
    {
        if(arr[row][j+col]=='-' || arr[row][j+col]==words[current_Index][j])
        {
            continue;
        }
        else
        {
            return false;
        }
        
    }

    return true;
}

void set_Vertical(char arr[N][N],bool state[],int word_size,int row,int col,string words[],int current_Index)
{
    for(int i=0;i<(word_size);i++)
    {
        if(!state[i])
        {
            state[i]=true;
            arr[i+row][col]=words[current_Index][i];
        }
    }
}

void set_horizontal(char arr[N][N],bool state[],int word_size,int row,int col,string words[],int current_Index)
{
    for(int j=0;j<(word_size);j++)
    {
        if(!state[j])
        {
            state[j]=true;
            arr[row][j+col]=words[current_Index][j];
        }
    }
}

void reset_Vertical(char arr[N][N],bool state[],int word_size,int row,int col,string words[],int current_Index)
{
    for(int i=0;i<(word_size);i++)
    {
        if(state[i])
        {
            state[i]=false;
            arr[i+row][col]='-';
        }
    }
}

void reset_horizontal(char arr[N][N],bool state[],int word_size,int row,int col,string words[],int current_Index)
{
    for(int j=0;j<(word_size);j++)
    {
        if(state[j])
        {
            state[j]=false;
            arr[row][j + col]='-';
        }
    }
}

void set_helper(bool helper[],int size)
{
    for(int i=0;i<size;i++)
    {
        helper[i]=false;
    }
}

bool Solve_Crossword(char arr[N][N],string words[],int size,int current_Index)
{
    if(current_Index==size)
    {
        return true;
    }

    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(arr[i][j]=='-' || arr[i][j]==words[current_Index][0])
            {

                if(is_Valid_Vertical(arr,i,j,words,current_Index,words[current_Index].length()))
                {
                    bool helper[words[current_Index].length()];
                    set_helper(helper,words[current_Index].length());
                    set_Vertical(arr,helper,words[current_Index].length(),i,j,words,current_Index);
                    if(Solve_Crossword(arr,words,size,current_Index+1))
                    {
                        return true;
                    }
                    reset_Vertical(arr,helper,words[current_Index].length(),i,j,words,current_Index);
                }

                if(is_Valid_horizontal(arr,i,j,words,current_Index,words[current_Index].length()))
                {
                    bool helper[words[current_Index].length()];
                    set_helper(helper,words[current_Index].length());
                    set_horizontal(arr,helper,words[current_Index].length(),i,j,words,current_Index);
                    if(Solve_Crossword(arr,words,size,current_Index+1))
                    {
                        return true;
                    }
                    reset_horizontal(arr,helper,words[current_Index].length(),i,j,words,current_Index);
                }
            }

        }
    }

    return false;
}

int main()
{
    char arr[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    string s;
    cin>>s;
    string words[10];
    int j=0;
    string current_string;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==';')
        {
            words[j++]=current_string;
            current_string="";
        }
        else
        {
            current_string+=s[i];
        }
    }
    words[j]=current_string;

    int size=j+1;
    
    Solve_Crossword(arr,words,size,0);
    
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }

    return 0;
}
