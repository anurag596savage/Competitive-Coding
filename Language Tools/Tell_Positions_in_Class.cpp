#include <bits/stdc++.h>
using namespace std;

class Student
{
    public :

    string name;
    int roll;
    int sum;
};

bool compare(Student s1, Student s2)
{
    if(s1.sum!=s2.sum)
    {
        return s1.sum>s2.sum;
    }
    else
    {
        return s1.roll<s2.roll;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<Student>v;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        int a,b,c;
        cin>>a>>b>>c;
        int total = (a+b+c);
        Student s;
        s.name=str;
        s.roll=i+1;
        s.sum=total;
        v.push_back(s);
    }

    sort(v.begin(),v.end(),compare);

    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" " <<v[i].name<<endl;
    }
}
