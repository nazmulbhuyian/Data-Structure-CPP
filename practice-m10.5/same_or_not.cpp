// Question: Take two doubly linked lists as input and check if they are the same or not.

// Sample Input
// Sample Output
// 10 20 30 40 50 -1
// 10 20 30 40 50 -1
// YES
// 10 20 30 40 50 -1
// 10 20 30 40 -1
// NO
// 10 20 30 40 -1
// 10 20 30 40 50 -1
// NO
// 10 20 30 40 -1
// 40 30 20 10 -1
// NO
// 1 2 3 4 5 -1
// 5 4 1 2 6 -1
// NO


#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert_tail(Node *&head, Node *&tail, int val){
    Node *newNode = new Node(val);
    if(tail == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next=newNode;
    newNode->prev=tail;
    tail=tail->next;
}

int print_linked(Node *head, Node *head2){
    Node *tmp = head;
    Node *tmp2 = head2;

    while (tmp != NULL && tmp2 != NULL)
    {
        if(tmp->val != tmp2->val){
            return 1;
        }
        tmp = tmp->next;
        tmp2 = tmp2->next;
    }

    if(tmp == NULL && tmp2 == NULL){
        return 0;
    }else{
        return 1;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int val;
    while (true)
    {
        cin>>val;
        if(val == -1)break;
        insert_tail(head, tail, val);
    }
    
    Node *head2 = NULL;
    Node *tail2 = NULL;
    int val2;
    while (true)
    {
        cin>>val2;
        if(val2 == -1)break;
        insert_tail(head2, tail2, val2);
    }
    int same = print_linked(head, head2);
    if(same == 0){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}