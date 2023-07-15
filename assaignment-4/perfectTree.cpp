// Problem Statement

// You will be given a binary tree as input in level order. You need to tell if the binary tree is perfect or not. A binary tree is called perfect if all leaf nodes are at the maximum depth of the tree, and the tree is completely filled with no gaps.

// Here is an example of perfect binary tree:

// image

// Also there is formula available to tell if a binary tree is perfect or not. The formula is :

// Total number of nodes = (2^maxHeight)-1
// Note: Here height is counted from 1. In the above image maximum height is 4, so total number of nodes are 2^4-1=15. So there should be 15 nodes to call it a perfect binary tree.

// Input Format

// Input will contain the binary tree in level order. -1 means there is no node available.
// Constraints

// 1 <= Maximum number of nodes <= 10^5
// 1 <= Node's value <= 1000
// Output Format

// Output "YES" if the tree is perfect, "NO" otherwise.
// Sample Input 0

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
// Sample Output 0

// YES
// Sample Input 1

// 10 20 30 40 -1 60 -1 -1 -1 -1 -1
// Sample Output 1

// NO
// Sample Input 2

// 10 20 -1 -1 -1
// Sample Output 2

// NO
// Sample Input 3

// 10 20 30 40 50 60 70 -1 -1 -1 -1 -1 -1 -1 -1
// Sample Output 3

// YES

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
int total_nodes(Node *root)
{
    if (root == nullptr)
        return 0;

    queue<Node *> q;
    q.push(root);
    int count = 0;

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        count++;

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }

    return count;
}
int max_height(Node *root)
{
    if (root == NULL)
        return 0;
    int l = max_height(root->left);
    int r = max_height(root->right);
    return (max(l, r) + 1);
}
int main()
{
    Node *root = input_tree();
    int totalNodes = total_nodes(root);
    int maxHeight = max_height(root);
    if(totalNodes == pow(2, maxHeight)-1){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}