// Problem Statement

// You need to take a singly linked list of integer value as input. You need to remove the duplicate values and print the unique values in ascending order.

// Note: You need to solve this using singly linked list, otherwise you will not get marks.

// Input Format

// Input will contain the values of the singly linked list, and will terminate with -1.
// Constraints

// 1 <= N <= 10^3; Here N is the maximum number of nodes of the linked list.
// 0 <= V <= 1000; Here V is the value of each node.
// Output Format

// Output the new singly linked list in ascending order.
// Sample Input 0

// 1 2 1 3 2 4 2 1 3 -1
// Sample Output 0

// 1 2 3 4
// Sample Input 1

// 2 2 2 2 -1
// Sample Output 1

// 2
// Sample Input 2

// 10 4 2 1 5 6 -1
// Sample Output 2

// 1 2 4 5 6 10
// Sample Input 3

// 5 4 3 5 4 2 5 3 2 4 5 1 2 3 4 5 -1
// Sample Output 3

// 1 2 3 4 5
// Sample Input 4

// 4 3 5 4 2 3 2 4 1 2 3 4 -1
// Sample Output 4

// 1 2 3 4 5

// #include <bits/stdc++.h>
// using namespace std;
// class Node
// {
// public:
//     int val;
//     Node *next;
//     Node(int val)
//     {
//         this->val = val;
//         this->next = NULL;
//     }
// };
// void insert_at_tail(Node *&head, Node *&tail, int val)
// {
//     Node *newNode = new Node(val);
//     if (head == NULL)
//     {
//         head = newNode;
//         tail = newNode;
//         return;
//     }
//     tail->next = newNode;
//     tail = tail->next;
// }
// Node* remove_duplicate(Node *head)
// {
//     if (head == NULL)return head;
//     Node *tmp = head;
//     while (tmp->next != NULL)
//     {
//         if (tmp->val == tmp->next->val)
//         {
//             tmp->next = tmp->next->next;
//         }
//         if (tmp->next == NULL)
//             break;
//         else if (tmp->val != tmp->next->val)
//         {
//             tmp = tmp->next;
//         }
//     }
//     return head;
// }
// int main()
// {
//     Node *head = NULL;
//     Node *tail = NULL;
//     int val;
//     while (true)
//     {
//         cin >> val;
//         if (val == -1)
//             break;
//         insert_at_tail(head, tail, val);
//     }
//     Node *print_linked=remove_duplicate(head);
//     while (print_linked!=NULL)
//     {
//         cout<<print_linked->val<<" ";
//         print_linked=print_linked->next;
//     }

//     return 0;
// }

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
void insert_at_tail(Node *&head, Node *&tail, int val)
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
void sort_linked_list(Node *head)
{
    Node* current = head;
    int temp;
    while (current->next != NULL) {
        Node* index = current->next;
        
        while (index != NULL) {
            if (current->val > index->val) {
                temp = current->val;
                current->val = index->val;
                index->val = temp;
            }
            index = index->next;
        }
        
        current = current->next;
    }
}
void remove_duplicate(Node *head)
{
    Node *tmp = head;
    while (tmp->next != NULL)
    {
        if (tmp->val == tmp->next->val)
        {
            tmp->next = tmp->next->next;
        }
        else if (tmp->val != tmp->next->val)
        {
            tmp = tmp->next;
        }
    }
    Node *print_linked = head;
    while (print_linked != NULL)
    {
        cout << print_linked->val << " ";
        print_linked = print_linked->next;
    }
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
        insert_at_tail(head, tail, val);
    }
    sort_linked_list(head);
    remove_duplicate(head);

    return 0;
}