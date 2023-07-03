// Problem Statement

// You need to take a singly linked list of integer value as input. You need to tell if the singly linked list forms a palindrome or not.

// Note: You need to solve this using singly linked list, otherwise you will not get marks.

// Input Format

// Input will contain the values of the singly linked list, and will terminate with -1.
// Constraints

// 1 <= N <= 10^6; Here N is the maximum number of nodes of the linked list.
// 0 <= V <= 1000; Here V is the value of each node.
// Output Format

// Output "YES" if it forms a palindrom otherwise print "NO".
// Sample Input 0

// 1 2 3 2 1 -1
// Sample Output 0

// YES
// Sample Input 1

// 1 2 2 1 -1
// Sample Output 1

// YES
// Sample Input 2

// 1 -1
// Sample Output 2

// YES
// Sample Input 3

// 1 2 3 1 -1
// Sample Output 3

// NO

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert_tail(Node *&head, Node *&tail, int val)
{
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
void check_palindrom(Node *head)
{
    Node *tmp = head;
    vector<int> v;
    while (tmp != NULL)
    {
        v.push_back(tmp->val);
        tmp = tmp->next;
    }
    int flag = 0;
    int start = 0;
    int end = v.size() - 1;

    while (start < end)
    {
        if (v[start] != v[end])
            flag = 1;
        start++;
        end--;
    }
    if(flag==0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
}
int main()
{
    int val;
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_tail(head, tail, val);
    }
    check_palindrom(head);
    return 0;
}