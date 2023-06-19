// Question: Take a doubly linked list as input and check if it forms any palindrome or not.

// Sample Input
// Sample Output
// 10 20 30 20 10 -1
// YES
// 10 20 30 30 20 10 -1
// YES
// 10 20 30 40 20 10 -1
// NO
// 10 20 30 20 40 -1
// NO
// 10 20 30 10 10
// NO
// 10 20 20 20 10
// YES

#include <bits/stdc++.h>
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
void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}
int palindromr_linked_list(Node *head, Node *tail)
{
    Node *tmp = head;
    Node *tmp2 = tail;
    vector<int> v;
    while (tmp != NULL)
    {
        v.push_back(tmp->val);
        tmp = tmp->next;
    }

    int start = 0;
    int end = v.size() - 1;

    while (start < end)
    {
        if (v[start] != v[end])
            return 1;
        start++;
        end--;
    }

    return 0;
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
    int palindrome = palindromr_linked_list(head, tail);
    if (palindrome == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}