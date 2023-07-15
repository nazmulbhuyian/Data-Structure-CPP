// Problem Statement

// There are a list of N values which were inserted into a stack and a list of M values which were inserted into a queue. After that the elements of the stack and queue are removed and put them into the list where the belong. You need to tell if both of the list are same or not after removing those elements from the stack and queue.

// Note: You need to implement Stack and Queue to solve this problem. You can't insert those values to anything else and also you can't use STL here. You can implement stack and queue by linked list or array as you wish.

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
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class myStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push(int val)
    {
        sz++;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        newNode->prev = tail;
        tail->next = newNode;
        tail = tail->next;
    }
    void pop()
    {
        sz--;
        Node *deleteNode = tail;
        tail = tail->prev;
        if (tail == NULL)
        {
            head = NULL;
        }
        else
        {
            tail->next = NULL;
        }

        delete deleteNode;
    }
    int top()
    {
        return tail->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        if (sz == 0)
            return true;
        else
            return false;
    }
};
class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push(int val)
    {
        sz++;
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = tail->next;
    }
    void pop()
    {
        sz--;
        Node *deleteNode = head;
        head = head->next;
        delete deleteNode;
        if (head == NULL)
        {
            tail = NULL;
        }
    }
    int front()
    {
        return head->val;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        if (sz == 0)
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
    int m;
    cin >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    myQueue q;
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    // while (!st.empty())
    // {
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    list<int> li1;
    while (!st.empty())
    {
        li1.push_back(st.top());
        st.pop();
    }
    // while (li1.size()!=0)
    // {
    //     cout<<li1.front()<<" ";
    //     li1.pop_front();
    // }


    // while (!q.empty())
    // {
    //     cout<<q.front()<<" ";
    //     q.pop();
    // }
    list<int> li2;
    while (!q.empty())
    {
        li2.push_back(q.front());
        q.pop();
    }
    // while (li2.size()!=0)
    // {
    //     cout<<li2.front()<<" ";
    //     li2.pop_front();
    // }
    


    int flag=0;
    int cnt = (li1.size()!=li2.size());
    if(cnt!=0)flag=1;
    else{
        while (!li1.empty())
        {
           if(li1.front()!=li2.front()){
            flag=1;
            break;
            }
           else{
            li1.pop_front();
            li2.pop_front();
           }
        }
        
    }
    if(flag==0)cout<<"YES";
    else cout<<"NO";


    return 0;
}