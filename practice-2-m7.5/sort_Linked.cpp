// Question: Take a singly linked list as input and sort it in descending order. Then print the list.



// Sample Input
// Sample Output
// 1 4 5 2 7 -1
// 7 5 4 2 1
// 20 40 30 10 50 60 -1
// 60 50 40 30 20 10

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
    // tmp ekhon last node e
    tmp->next = newNode;
}
void print_linked_list(Node *head)
{
    Node* current = head;
    int temp;
    while (current->next != NULL) {
        Node* index = current->next;
        
        while (index != NULL) {
            if (current->val < index->val) {
                temp = current->val;
                current->val = index->val;
                index->val = temp;
            }
            index = index->next;
        }
        
        current = current->next;
    }
    Node *tmp2 = head;
    while (tmp2 != NULL)
    {
        cout << tmp2->val << " ";
        tmp2 = tmp2->next;
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