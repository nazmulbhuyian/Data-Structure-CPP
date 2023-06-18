// Problem Statement

// You need to take a singly linked list of integer value as input. Then you need to print the singly linked list in reverse order, after that print the original linked list also.

// Note: You must use singly linked list, otherwise you will not get marks.

// Input Format

// Input will contain the values of the singly linked list, and will terminate with -1.
// Constraints

// 1 <= N <= 10^6; Here N is the maximum number of nodes of the linked list.
// 0 <= V <= 10^9; Here V is the value of each node.
// Output Format

// In first line, output the linked list in reverse order.
// In second line, print the original linked list.
// Sample Input 0

// 10 20 30 40 50 -1
// Sample Output 0

// 50 40 30 20 10
// 10 20 30 40 50
// Sample Input 1

// 20 40 50 10 -1
// Sample Output 1

// 10 50 40 20
// 20 40 50 10


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
void print_recursion(Node *n)
{
    // base case
    if (n == NULL)
        return;
    print_recursion(n->next);
    cout << n->val << " ";
}
void print_linekd_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
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
    print_recursion(head);
    cout<<endl;
    print_linekd_list(head);
    return 0;
}

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
// void insert_tail(Node *&head, int val)
// {
//     Node *newNode = new Node(val);
//     if (head == NULL)
//     {
//         head = newNode;
//         return;
//     }
//     Node *tmp = head;
//     while (tmp->next != NULL)
//     {
//         tmp = tmp->next;
//     }
//     tmp->next = newNode;
// }
// void print_recursion(Node *n)
// {
//     // base case
//     if (n == NULL)
//         return;
//     print_recursion(n->next);
//     cout << n->val << " ";
// }
// int main()
// {
//     Node *head = NULL;
//     int val;
//     while (true)
//     {
//         cin >> val;
//         if (val == -1)
//             break;
//         insert_tail(head, val);
//     }
//     print_recursion(head);
//     cout<<endl;
//     for (Node *i = head; i != NULL; i = i->next)
//     {
//         cout << i->val << " ";
//     }
//     return 0;
// }

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
// void insert_at_tail(Node *&head, int v)
// {
//     Node *newNode = new Node(v);
//     if (head == NULL)
//     {
//         head = newNode;
//         return;
//     }

//     Node *tmp = head;
//     while (tmp->next != NULL)
//     {
//         tmp = tmp->next;
//     }
//     tmp->next = newNode;
// }
// void print_reverse(Node *n)
// {
//     if (n == NULL)
//         return;

//     print_reverse(n->next);
//     cout << n->val << " ";
// }
// void print_linked_list(Node *head)
// {
//     cout << endl;
//     Node *tmp = head;
//     // while (tmp != NULL)
//     // {
//     //     cout << tmp->val << " ";
//     //     tmp = tmp->next;
//     // }
//     for (Node *i = head; i != NULL; i = i->next)
//     {
//         cout << i->val << " ";
//     }
// }
// int main()
// {
//     int val;
//     Node *head = NULL;
//     while (true)
//     {
//         cin >> val;
//         if (val == -1)
//             break;
//         insert_at_tail(head, val);
//     }
//     print_reverse(head);
//     print_linked_list(head);
//     return 0;
// }