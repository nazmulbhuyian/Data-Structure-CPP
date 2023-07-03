// Problem Statement

// You are given a doubly linked list of strings. These strings refer to web addresses without any spaces. You will be given Q queries. In each query you will be given some commands. Type of commands are -

// visit address - You need to go to that address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
// next - You need to go to the next address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
// prev - You need to go to the previous address from where you are in that list and print that address if it is in the list. Otherwise print "Not Available".
// Note: You can use Linked List or STL List to solve this problem.

// Input Format

// First line will contain the values of the doubly linked list, and will terminate with the string "end".
// Second line will contain Q.
// Next Q lines will contain the commands. It is guranteed that you will get "visit address" command at first which will contain a valid address.
// Constraints

// 1 <= N <= 1000; Here N is the maximum number of nodes of the linked list.
// 1 <= Q <= 1000;
// 1 <= |Address| <= 100; Here |Address| is the length of the string address.
// Output Format

// For each query output as asked.
// Sample Input 0

// facebook google phitron youtube twitter end
// 11
// visit phitron
// prev
// prev
// prev
// prev
// next
// visit twitter
// next
// next
// prev
// visit django
// Sample Output 0

// phitron
// google
// facebook
// Not Available
// Not Available
// google
// twitter
// Not Available
// Not Available
// youtube
// Not Available

// #include <iostream>
// #include <string>
// using namespace std;
// struct Node {
//     string address;
//     Node* prev;
//     Node* next;
// };
// Node* createNode(string address) {
//     Node* newNode = new Node();
//     newNode->address = address;
//     newNode->prev = nullptr;
//     newNode->next = nullptr;
//     return newNode;
// }
// void insertNode(Node* head, Node* newNode) {
//     if (head == nullptr) {
//         head = newNode;
//     } else {
//         newNode->next = head;
//         head->prev = newNode;
//         head = newNode;
//     }
// }
// void printList(Node* head) {
//     while (head != nullptr) {
//         cout << head->address << endl;
//         head = head->next;
//     }
// }
// void visit(Node* head, string address) {
//     while (head != nullptr) {
//         if (head->address == address) {
//             cout << head->address << endl;
//             break;
//         }
//         head = head->next;
//     }
// }
// void next(Node* head) {
//     if (head == nullptr) {
//         cout << "Not Available" << endl;
//     } else {
//         cout << head->next->address << endl;
//     }
// }
// void prev(Node* head) {
//     if (head == nullptr) {
//         cout << "Not Available" << endl;
//     } else {
//         cout << head->prev->address << endl;
//     }
// }
// int main() {
//     Node* head = nullptr;
//     string address;

//     cin >> address;
//     while (address != "end") {
//         Node* newNode = createNode(address);
//         insertNode(head, newNode);
//         cin >> address;
//     }

//     int Q;
//     cin >> Q;

//     while (Q--) {
//         string command;
//         cin >> command;
//         if (command == "visit") {
//             cin >> address;
//             visit(head, address);
//         } else if (command == "next") {
//             next(head);
//         } else if (command == "prev") {
//             prev(head);
//         }
//     }

//     return 0;
// }



// a b c d e f g h i j k l m n o p q r s t u v w x y z end
// 6
// visit s
// next
// visit p
// prev
// prev
//  
// s
// t
// p
// o
// n
// r

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string add;
    Node *next;
    Node *prev;
    Node(string add)
    {
        this->add = add;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert_tail(Node *&head, Node *&tail, string add)
{
    Node *newNode = new Node(add);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}
void visit(Node *head, string add, Node *&tmp)
{
    if (head == NULL)
    {
        cout << "Not Available" << endl;
        return;
    }
    Node *test=head;
    while (test!=NULL)
    {
        if (test->add == add)
        {
            cout << add << endl;
            tmp=test;
            return;
        }
        else
        {
            test = test->next;
        }
    }
    cout<<"Not Available"<<endl;
}
void prev(Node *&tmp, Node *head){
    if (tmp == head)
    {
        cout << "Not Available" << endl;
        return;
    }
    if(tmp->prev!=NULL){
        cout<<tmp->prev->add<<endl;
        tmp=tmp->prev;
        return;
    }
    else{
        cout<<"Not Available"<<endl;
        return;
    }
}
void next(Node *&tmp){
    if(tmp->next!=NULL){
        cout<<tmp->next->add<<endl;
        tmp=tmp->next;
        return;
    }
    else{
        cout<<"Not Available"<<endl;
        return;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    while (true)
    {
        string add;
        cin >> add;
        if (add == "end")
            break;
        insert_tail(head, tail, add);
    }
    int q;
    cin >> q;
    Node *tmp = head;
    while (q)
    {
        string command;
        cin >> command;
        if (command == "visit")
        {
            string add;
            cin >> add;
            visit(head, add, tmp);
        }
        else if (command == "next")
        {
            next(tmp);
        }
        else if (command == "prev")
        {
            prev(tmp, head);
        }
        q--;
    }
    return 0;
}