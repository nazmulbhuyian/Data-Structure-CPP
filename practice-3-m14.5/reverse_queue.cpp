// Question: Take a queue of size N as input. You need to copy those elements in another queue in reverse order. You might use stack here. You should use STL to solve this problem. After copying in another queue, print the elements of that queue.

// Sample Input
// Sample Output
// 5
// 10 20 30 40 50
// 50 40 30 20 10



#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    queue<int> q;
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    // st2=st;
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}