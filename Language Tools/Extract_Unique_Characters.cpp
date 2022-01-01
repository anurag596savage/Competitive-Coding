#include <iostream>
#include <string>
using namespace std;
#include <set>


string uniqueChar(string str) {
	// Write your code here
    string ans;
    set<char>s;
    for(int i=0;i<str.length();i++)
    {
        if(s.find(str[i])==s.end())
        {
            s.insert(str[i]);
            ans+=str[i];
        }
    }
    return ans;
}

int main() {
    string str;
    cin >> str;
   
