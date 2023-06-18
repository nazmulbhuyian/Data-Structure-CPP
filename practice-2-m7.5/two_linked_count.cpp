// Question: Take two singly linked lists as input and check if their sizes are same or not.

// Sample Input
// Sample Output
// 2 1 5 3 4 9 -1
// 1 2 3 4 5 6 -1
// YES
// 5 1 4 5 -1
// 5 1 4 -1
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
int print_linked_list(Node *head)
{
    cout << endl;
    cout << "Your Linked List: ";
    Node *tmp = head;
    int cnt=0;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        cnt++;
        tmp = tmp->next;
    }
    // cout <<endl<<"Size of linked list is: "<<cnt<< endl;
    return cnt;
}
int print_linked_list2(Node2 *head)
{
    cout << endl;
    cout << "Your Linked List: ";
    Node2 *tmp = head;
    int cnt=0;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        cnt++;
        tmp = tmp->next;
    }
    // cout <<endl<<"Size of linked list is: "<<cnt<< endl;
    cout<<endl;
    return cnt;
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
    int cnt1 = print_linked_list(head);
    int cnt2 = print_linked_list2(head2);
    if(cnt1 ==cnt2){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}