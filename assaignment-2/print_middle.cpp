// Problem Statement

// You need to take a singly linked list of integer value as input. Then you need to sort the linked list in descending order and print the middle element of it. If there are multiple values in the middle, print both.

// Note: You must use singly linked list, otherwise you will not get marks.

// Input Format

// Input will contain the values of the singly linked list, and will terminate with -1.
// Constraints

// 1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
// 0 <= V <= 1000; Here V is the value of each node.
// Output Format

// Output the value/values of the middle element.
// Sample Input 0

// 20 10 40 30 50 -1
// Sample Output 0

// 30
// Sample Input 1

// 20 30 10 40 60 50 -1
// Sample Output 1

// 40 30
// Sample Input 2

// 726 -1
// Sample Output 2

// 726
// Sample Input 3

// 348 726 -1
// Sample Output 3

// 726 348

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
    tmp->next = newNode;
}
void print_linked_list(Node *head)
{
    Node *current = head;
    int temp;
    while (current->next != NULL)
    {
        Node *index = current->next;

        while (index != NULL)
        {
            if (current->val < index->val)
            {
                temp = current->val;
                current->val = index->val;
                index->val = temp;
            }
            index = index->next;
        }

        current = current->next;
    }
    Node *tmp = head;
    vector<int> v;
    int cnt = 0;
    while (tmp != NULL)
    {
        cnt++;
        v.push_back(tmp->val);
        tmp = tmp->next;
    }
    if (cnt == 1)
    {
        cout << v[0];
    }
    else
    {
    if (cnt % 2 == 1)
    {
        int mid = cnt / 2;
        cout<< v[mid] << endl;
    }
    else
    {
        int mid1 = cnt / 2 - 1;
        int mid2 = mid1 + 1;
        cout<< v[mid1] << " " << v[mid2] << endl;
    }
    }
}
int main()
{
    int val;
    Node *head = NULL;
    while (true)
    {
        cin >> val;
        if (val == -1)
            break;
        insert_at_tail(head, val);
    }
    print_linked_list(head);
    return 0;
}