// Question: Take a singly linked list as input and check if the linked list contains any duplicate value. You can assume that the maximum value will be 100.

// Sample Input
// Sample Output
// 5 4 8 6 2 1 -1
// NO

// 2 4 5 6 7 4 -1
// YES

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
    cout << endl;
    cout << "Your Linked List: ";
    Node *tmp = head;
    int dup = 0;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";

        Node *runner = tmp->next;
        while (runner != NULL)
        {
            if (runner->val == tmp->val)
            {
                dup = 1; // Duplicate found
            }
            runner = runner->next;
        }

        tmp = tmp->next;
    }
    if(dup == 0){
        cout <<endl<<"NO"<< endl;
    }
    else{
        cout <<endl<<"YES"<< endl;
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