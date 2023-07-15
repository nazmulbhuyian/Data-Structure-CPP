// Problem Statement

// You will be given a binary tree as input in level order. You need to give the maximum and minimum values of all the leaf nodes available.

// For example:

// image

// The output for the above tree will be: 60 40

// Input Format

// Input will contain the binary tree in level order. -1 means there is no node available.
// Constraints

// 1 <= Maximum number of nodes <= 10^5
// 1 <= Node's value <= 1000
// Output Format

// Output the maximum value then the minimum value of all leaf nodes.
// Sample Input 0

// 10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1
// Sample Output 0

// 60 40


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
vector<int> v;
void find_leaf(Node* root){
        if(root == NULL) return;
        if(root->left==NULL && root->right==NULL) v.push_back(root->val);
        find_leaf(root->left);
        find_leaf(root->right);
}
void max_min_leaf(vector<int> v){
    int max = v[0];
    int min = v[0];
    while(!v.empty()){
        if(v.back() > max) max = v.back();
        if(v.back() < min) min = v.back();
        v.pop_back();
    }
    cout<<max<<" "<<min;
}
int main()
{
    Node *root = input_tree();
    find_leaf(root);
    max_min_leaf(v);
    return 0;
}