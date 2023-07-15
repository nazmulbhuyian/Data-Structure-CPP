// Problem Statement

// There are a list of N values which were inserted into a stack and a list of M values which were inserted into a queue. After that the elements of the stack and queue are removed and put them into the list where the belong. You need to tell if both of the list are same or not after removing those elements from the stack and queue.

// Note: You need to use STL Stack and Queue to solve this problem. You can't insert those values to anything else.

// Input Format

// First line will contain N and M.
// Second line will contain list A with N values.
// Third line will contain list B with M values.
// Constraints

// 1 <= N, M <= 10^6
// 0 <= Values of list A and B <= 1000
// Output Format

// Output "YES" if they were same, otherwise "NO".
// Sample Input 0

// 5 5
// 10 20 30 40 50
// 50 40 30 20 10
// Sample Output 0

// YES
// Sample Input 1

// 4 4
// 10 20 30 40
// 10 20 30 40
// Sample Output 1

// NO
// Sample Input 2

// 5 4
// 10 20 30 40 50
// 50 40 30 20
// Sample Output 2

// NO



#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    int n;
    cin >> n;
    int m;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    queue<int> q;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    
    int flag=0;
    int cnt = (st.size()!=q.size());
    if(cnt!=0)flag=1;
    else{
        while (!st.empty())
        {
           if(st.top()!=q.front()){
            flag=1;
            break;
            }
           else{
            st.pop();
            q.pop();
           }
        }
        
    }
    if(flag==0)cout<<"YES";
    else cout<<"NO";


    return 0;
}