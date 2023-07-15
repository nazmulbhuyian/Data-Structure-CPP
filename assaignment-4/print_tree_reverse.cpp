// Problem Statement

// You will be given a binary tree as input in level order. You need to print the binary tree in reverse way. Here, reverse way means you need to print from the last level and from left to right.

// For example:

// image

// The output for the above tree will be: 40 50 60 20 30 10

// Input Format

// Input will contain the binary tree in level order. -1 means there is no node available.
// Constraints

// 1 <= Maximum number of nodes <= 10^5
// 1 <= Node's value <= 1000
// Output Format

// Output the tree in reverse way as described.
// Sample Input 0

// 10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
// Sample Output 0

// 40 50 60 20 30 10

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        // 1. ber kore ano
        Node *p = q.front();
        q.pop();

        // 2. jabotiyo ja kaj ache
        int l, r;
        cin >> l >> r;
        Node *myLeft;
        Node *myRight;
        if (l == -1)
            myLeft = NULL;
        else
            myLeft = new Node(l);
        if (r == -1)
            myRight = NULL;
        else
            myRight = new Node(r);

        p->left = myLeft;
        p->right = myRight;

        // 3. children gulo ke push koro
        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

int main()
{
    Node *root = input_tree();
    vector<int> v;
    queue<Node *> q;
    if (root)
        q.push(root);
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        v.push_back(node->val);
        if (node->right)
            q.push(node->right);
        if (node->left)
            q.push(node->left);
        
    }
    while (!v.empty())
    {
        cout<<v.back()<<" ";
        v.pop_back();
    }
    
    return 0;
}