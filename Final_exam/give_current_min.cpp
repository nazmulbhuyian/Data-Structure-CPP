// Problem Statement

// You will be given a list A of size N. Then you will be given Q queries, for each query there will be some commands. Commands are given below -

// 0 X -> Insert X into the list. Then print the current minimum value from the list.
// 1 -> Print the minimum value from the list.
// 2 -> Delete the minimum value from the list and print the current minimum value from the list.
// Note: If the list is empty and you can't print anything then you should print "Empty".

// Input Format

// First line will contain N.
// Second line will contain the list A of size N.
// Third line will contain Q.
// Next Q lines will contain the commands.
// Constraints

// 1 <= N+Q <= 10^5
// -10^9 <= A[i] <= 10^9 ; Here A[i] means the values of the list A.
// -10^9 <= X <= 10^9
// Output Format

// For each command, print as asked from the list.
// Sample Input 0

// 4
// 10 -10 -5 -20
// 10
// 1
// 2
// 2
// 2
// 2
// 0 10
// 1
// 2
// 0 20
// 1
// Sample Output 0

// -20
// -10
// -5
// 10
// Empty
// 10
// 10
// Empty
// 20
// 20
// Sample Input 1

// 6
// 45 -30 83 -99 19 75 
// 9
// 1
// 2
// 2
// 0 32
// 0 6
// 2
// 2
// 0 -86
// 1
// Sample Output 1

// -99
// -30
// 19
// 19
// 6
// 19
// 32
// -86
// -86


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        pq.push(arr[i]);
    }

    int q;
    cin >> q;

    while (q--) {
        int cmd;
        cin >> cmd;

        if (cmd == 0) {
            int X;
            cin >> X;
            pq.push(X);
            cout << pq.top() << endl;
        } else if (cmd == 1) {
            if (pq.empty()) {
                cout << "Empty" << endl;
            } else {
                cout << pq.top() << endl;
            }
        } else if (cmd == 2) {
            if (pq.empty()) {
                cout << "Empty" << endl;
            } else {
                pq.pop();
                if (pq.empty()) {
                    cout << "Empty" << endl;
                } else {
                    cout << pq.top() << endl;
                }
            }
        }
    }

    return 0;
}






// #include <iostream>
// using namespace std;

// struct Node {
//   int data;
//   Node* next;
// };

// Node* head = NULL;
// Node* min_node = NULL;

// void insert(int x) {
//   Node* new_node = new Node();
//   new_node->data = x;
//   new_node->next = NULL;

//   if (head == NULL) {
//     head = new_node;
//     min_node = new_node;
//   } else if (x < min_node->data) {
//     new_node->next = min_node;
//     min_node = new_node;
//   } else {
//     new_node->next = head;
//     head = new_node;
//   }
// }

// void print_min() {
//   if (min_node == NULL) {
//     cout << "Empty" << endl;
//   } else {
//     cout << min_node->data << endl;
//   }
// }

// void delete_min() {
//   if (min_node == NULL) {
//     cout << "Empty" << endl;
//   } else {
//     Node* temp = min_node;
//     min_node = min_node->next;
//     delete temp;
//     cout << min_node->data << endl;
//   }
// }

// int main() {
//   int n, q;
//   cin >> n;
//   for (int i = 0; i < n; i++) {
//     int x;
//     cin >> x;
//     insert(x);
//   }

//   cin >> q;
//   for (int i = 0; i < q; i++) {
//     int command;
//     cin >> command;
//     if (command == 0) {
//       int x;
//       cin >> x;
//       insert(x);
//     } else if (command == 1) {
//       print_min();
//     } else {
//       delete_min();
//     }
//   }
//   return 0;
// }