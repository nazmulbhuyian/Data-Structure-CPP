// Problem Statement

// You need to take a singly linked list of integer value as input and print the maximum and minimum value of the singly linked list.

// Note: You must use singly linked list, otherwise you will not get marks.

// Input Format

// Input will contain the values of the singly linked list, and will terminate with -1.
// Constraints

// 1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
// 0 <= V <= 1000; Here V is the value of each node.
// Output Format

// Output the maximum value then the minimum value.
// Sample Input 0

// 2 4 1 5 3 6 -1
// Sample Output 0

// 6 1
// Sample Input 1

// 2 -1
// Sample Output 1

// 2 2



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
    tail = newNode;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_tail(head, tail, val);
    }
    int max = INT_MIN;
    int min = INT_MAX;
    for (Node *i = head; i != NULL; i = i->next)
    {
            if (max < i->val)
            {
                max = i->val;
            }
    }
    for (Node *i = head; i != NULL; i = i->next)
    {
            if (min > i->val)
            {
                min = i->val;
            }
    }
    cout<<max<<" "<<min;
    return 0;
}