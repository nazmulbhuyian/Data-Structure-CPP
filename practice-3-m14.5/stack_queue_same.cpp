// Question: Take a stack of size N and a queue of size M as input. Then check if both of them are the same or not in the order of removing. You should use STL to solve this problem.

// Sample Input
// Sample Output
// 5
// 10 20 30 40 50
// 5
// 10 20 30 40 50
// NO
// 5
// 10 20 30 40 50
// 4
// 10 20 30 40
// NO
// 5
// 10 20 30 40 50
// 5
// 50 40 30 20 10
// YES



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
class myQueue
{
public:
    list<int> l;
    void push(int val)
    {
        l.push_back(val);
    }
    void pop()
    {
        l.pop_front();
    }
    int front()
    {
        return l.front();
    }
    int size()
    {
        return l.size();
    }
    bool empty()
    {
        return l.empty();
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

    myQueue q;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    int flag=0;
    while (!st.empty()&&!q.empty())
    {
        if(st.size()!=q.size()){
            flag=1;
            break;
        }
        if(st.top()!=q.front()){
            flag=1;
            break;
        }
        st.pop();
        q.pop();
    }
    if(flag==0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}