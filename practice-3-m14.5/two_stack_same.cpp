// Question: Take two stacks of size N and M as input and check if both of them are the same or not. Don’t use STL to solve this problem.

// Sample Input
// Sample Output
// 5
// 10 20 30 40 50
// 5
// 10 20 30 40 50
// YES
// 5
// 10 20 30 40 50
// 4
// 10 20 30 40
// NO
// 5
// 10 20 30 40 50
// 5
// 50 40 30 20 10
// NO



#include <bits/stdc++.h>
using namespace std;
class myStack
{
public:
    list<int> l;
    void push(int val)
    {
        l.push_back(val);
    }
    void pop()
    {
        l.pop_back();
    }
    int top()
    {
        return l.back();
    }
    int size()
    {
        return l.size();
    }
    bool empty()
    {
        if (l.size() == 0)
            return true;
        else
            return false;
    }
};
class myStack2
{
public:
    list<int> l;
    void push(int val)
    {
        l.push_back(val);
    }
    void pop()
    {
        l.pop_back();
    }
    int top()
    {
        return l.back();
    }
    int size()
    {
        return l.size();
    }
    bool empty()
    {
        if (l.size() == 0)
            return true;
        else
            return false;
    }
};
int main()
{
    myStack st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    myStack2 st2;
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        st2.push(x);
    }
    int flag=0;
    while (!st.empty()&&!st2.empty())
    {
        if(st.size()!=st2.size()){
            flag=1;
            break;
        }
        if(st.top()!=st2.top()){
            flag=1;
            break;
        }
        st.pop();
        st2.pop();
    }
    if(flag==0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}