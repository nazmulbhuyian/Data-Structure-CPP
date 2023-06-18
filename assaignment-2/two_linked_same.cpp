// Problem Statement

// You will be given two singly linked list of integer values as input. You need to check if all the elements of both list are same which means both list are same. If they are same print "YES" otherwise print "NO".

// Note: You must use singly linked list, otherwise you will not get marks.

// Input Format

// First line will contain the values of the first singly linked list, and will terminate with -1.
// Second line will contain the values of the second singly linked list, and will terminate with -1.
// Constraints

// 1 <= N1, N2 <= 1000; Here N1 and N2 is the maximum number of nodes of the first and second linked list.
// 0 <= V <= 1000; Here V is the value of each node.
// Output Format

// Output "YES" or "NO".
// Sample Input 0

// 10 20 30 40 -1
// 10 20 30 40 -1
// Sample Output 0

// YES
// Sample Input 1

// 10 20 30 40 -1
// 10 20 30 -1
// Sample Output 1

// NO
// Sample Input 2

// 10 20 30 40 -1
// 40 30 20 10 -1
// Sample Output 2

// NO




#include<bits/stdc++.h>
using namespace std;
class Node
{
    public:
        int val;
        Node* next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
class Node2
{
    public:
        int val;
        Node2* next;
    Node2(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};
void insert_at_tail(Node *&head, int v)
{
    Node *newNode = new Node(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    // tmp ekhon last node e
    tmp->next = newNode;
}
void insert_at_tail2(Node2 *&head, int v)
{
    Node2 *newNode = new Node2(v);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node2 *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }
    // tmp ekhon last node e
    tmp->next = newNode;
}
int print_linked_list(Node *head, Node2 *head2)
{
    Node *tmp = head;
    Node2 *tmp2 = head2;
    while (tmp != NULL && tmp2 != NULL) {
        if (tmp->val != tmp2->val) {
            return 0;
        }
        tmp = tmp->next;
        tmp2 = tmp2->next;
    }

    
    if (tmp == NULL && tmp2 == NULL) {
        return 1;
    } else {
        return 0;
    }
    return 1;
}
int main()
{
    int val;
    Node *head = NULL;
    int val2;
    Node2 *head2 = NULL;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(head, val);
    }
    while (true)
    {
        cin >> val2;
        if (val2 == -1)
            break;
        insert_at_tail2(head2, val2);
    }
    int same = print_linked_list(head, head2);
    if(same == 0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}