// Question: Take a stack of size N as input and copy those elements to another stack to get the values in the order they were inserted and print them. You should use STL to solve this problem.


// Sample Input
// Sample Output
// 5
// 10 20 30 40 50
// 10 20 30 40 50



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
int main()
{
    // myStack st;
    stack<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    stack<int> st2;
    while (!st.empty())
    {
        st2.push(st.top());
        st.pop();
    }
    // st2=st;
    while (!st2.empty())
    {
        cout<<st2.top()<<" ";
        st2.pop();
    }
    return 0;
}