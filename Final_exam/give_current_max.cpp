// Problem Statement

// You will be given a list A of size N. The list will contain data of some students where each student have Name, Roll and Marks. Then you will be given Q queries, for each query there will be some commands. Commands are given below -

// 0 X -> Insert X into the list where X is the data of a student which contain Name, Roll and Marks. Then print the current student's data who has the maximum Marks from the list.
// 1 -> Print the current student's data who has the maximum Marks from the list.
// 2 -> Delete the student who has the maximum Marks from the list and print the current student who has the maximum Marks from the list.
// Note: If there are multiple students with same Marks then we will select whose Roll is smaller. If the list is empty and you can't print anything then you should print "Empty".

// Input Format

// First line will contain N.
// Next N lines will contain Name, Roll and Marks of student A[i].
// Third line will contain Q.
// Next Q lines will contain the commands.
// Constraints

// 1 <= N+Q <= 10^5
// 1 <= |Name| <= 1000, Name will contain only English lowercase letters and will not contain any spaces.
// 0 <= Roll <= 10^5
// 0 <= Marks <= 100
// Output Format

// For each command, print as asked from the list.
// Sample Input 0

// 3
// akib 23 95
// jobbar 24 99
// ali 25 100
// 8
// 1
// 2
// 2
// 2
// 0 kabir 15 65
// 0 asif 55 65
// 2
// 0 tamim 35 65
// Sample Output 0

// ali 25 100
// jobbar 24 99
// akib 23 95
// Empty
// kabir 15 65
// kabir 15 65
// asif 55 65
// tamim 35 65

#include <bits/stdc++.h>
using namespace std;
class Student
{
public:
    string name;
    int roll;
    int marks;
    Student(string name, int roll, int marks)
    {
        this->marks = marks;
        this->roll = roll;
        this->name = name;
    }
};
class cmp
{
public:
    bool operator()(Student a, Student b)
    {
        if (a.marks < b.marks)
            return true;
        else if (a.marks > b.marks)
            return false;
        else
            return a.roll > b.roll;
    }
};


int main()
{
    int n;
    cin >> n;
    priority_queue<Student, vector<Student>, cmp> pq;
    for (int i = 0; i < n; i++)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student obj(name, roll, marks);
        pq.push(obj);
    }

    int Q;
    cin >> Q;

    while (Q--)
    {
        int command;
        cin >> command;

        if (command == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            Student obj(name, roll, marks);
            pq.push(obj);
            cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
        }
        else if (command == 1)
        {
            if (pq.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
            }
        }
        else if (command == 2)
        {
            if (pq.empty())
            {
                cout << "Empty" << endl;
            }
            else
            {
                pq.pop();
                if (pq.empty())
                {
                    cout << "Empty" << endl;
                }
                else
                {
                    cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
                }
            }
        }
    }
    return 0;
}