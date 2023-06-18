// Problem Statement

// You have a singly linked list which is empty initially. Then you will be given Q queries. In each query you will be given two values X and V.

// If X is 0 that means you will insert the value V to the head of the linked list.
// And if X is 1 then you will insert the value V to the tail of the linked list.
// After that for each query you need to print the value of the head and tail of the list.
// Note: You must use singly linked list, otherwise you will not get marks.

// Input Format

// First line will contain Q.
// Next Q lines will contain X and V.
// Constraints

// 1 <= Q <= 10^6;
// 0 <= X <= 1;
// 0 <= V <= 10^9
// Output Format

// For each query ouput the value of head and tail of the linked list.
// Sample Input 0

// 5
// 0 10
// 0 20
// 1 30
// 0 40
// 1 50
// Sample Output 0

// 10 10
// 20 10
// 20 30
// 40 30
// 40 50
// Explanation 0

// Query 1: 10 is inserted at head. Linked list looks like: 10->NULL. Now both head and tail are 10.
// Query 2: 20 is inserted at head. Linked list looks like: 20->10->NULL. Now head is at 20 and tail is at 10.
// Query 3: 30 is inserted at tail. Linked list looks like: 20->10->30->NULL. Now head is at 20 and tail is at 30.
// Query 4: 40 is inserted at head. Linked list looks like: 40->20->10->30->NULL. Now head is at 40 and tail is at 30.
// Query 5: 50 is inserted at tail. Linked list looks like: 40->20->10->30->50->NULL. Now head is at 40 and tail is at 50.
// Sample Input 1

// 3
// 1 10
// 1 20
// 0 30
// Sample Output 1

// 10 10
// 10 20
// 30 20
// Explanation 1

// Query 1: 10 is inserted at tail. Linked list looks like: 10->NULL. Now both head and tail are 10.
// Query 2: 20 is inserted at tail. Linked list looks like: 10->20->NULL. Now head is at 10 and tail is at 20.
// Query 3: 30 is inserted at head. Linked list looks like: 30->10->20->NULL. Now head is at 30 and tail is at 20.

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
void insert_head(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}
void insert_tail( Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail = newNode;
}
void print_linked_list(Node *head, Node *tail)
{
    cout<<head->val<<" "<<tail->val<<endl;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int q;
    cin >> q;
    while (q)
    {
        int ht, val;
        cin >>ht>> val;
        if(ht==0){
            insert_head(head, tail, val);
        }
        else if(ht==1){
            insert_tail(head, tail, val);
        }
        print_linked_list(head, tail);
        q--;
    }
    return 0;
}