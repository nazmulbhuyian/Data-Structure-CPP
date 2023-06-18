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
    // cout << "Your Linked List: ";
    Node *tmp = head;
    vector<int> v;
    int cnt=0;
    while (tmp != NULL)
    {
        // cout << tmp->val << " ";
        cnt++;
        v.push_back(tmp->val);
        tmp = tmp->next;
    }
    if(cnt%2==1){
        int mid=cnt/2;
        cout <<endl<<"Size of midle linked list is: "<<v[mid]<< endl;
    }
    else{
        int mid1=cnt/2-1;
        int mid2=mid1+1;
        cout <<endl<<"Size of midle linked list is: "<<v[mid1]<<" and "<<v[mid2]<< endl;
    }
    // cout <<endl<<"Size of linked list is: "<<cnt<< endl;
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