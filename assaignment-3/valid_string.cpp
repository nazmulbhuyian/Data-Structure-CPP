// Problem Statement

// Given a string s containing just the characters 'A' and 'B, determine if the input string is valid.

// An input string is valid if the string is empty after doing some operatios. The available operations are:

// B can delete its previous available character A along with itself. If there is no A available to delete, it will not delete itself.
// A can delete its previous available character B along with itself. If there is no B available to delete, it will not delete itself.
// Input Format

// First line will contain T, the number of test cases.
// Next T lines will contain the string S.
// Constraints

// 1 <= T <= 1000
// 1 <= |S| <= 1000; Here |S| means the length of the string.
// Output Format

// Output "YES" if the string is valid, otherwise "NO".
// Sample Input 0

// 10
// AABB
// BABA
// BBAA
// ABAB
// AAAB
// ABBB
// ABBA
// BAABAB
// BBBAABA
// AAABABBABB
// Sample Output 0

// YES
// YES
// YES
// YES
// NO
// NO
// YES
// YES
// NO
// YES

// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int quaries;
//     cin >> quaries;
//     while (quaries)
//     {
//         list<char> l;
//         string s;
//         cin >> s;
//         int countA = 0;
//         int countB = 0;
//         for (char c : s)
//         {

//             l.push_back(c);

//             // while (!l.empty())
//             // {
//             //     cout<<l.front()<<" ";
//             //     l.pop_front();
//             // }

//             if (c == 'a')
//             {
//                 countA++;
//                 if (countB > 0)
//                 {
//                     countB--;
//                     countA--;
//                 }
//             }
//             else if (c == 'b')
//             {
//                 countB++;
//                 if (countA > 0)
//                 {
//                     countA--;
//                     countB--;
//                 }
//             }
//         }
//         cout << countA << " " << countB;
//         quaries--;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
void checkSame(string s)
{
    list<char> l;
    for (char c : s)
    {
        l.push_back(c);
    }
    int cntA = 0;
    int cntB = 0;
    while (!l.empty())
    {
        if (l.front() == 'A')
        {
            cntA++;
            if (cntB > 0)
            {
                cntA--;
                cntB--;
            }
            l.pop_front();
        }
        else
        {
            cntB++;
            if (cntA > 0)
            {
                cntA--;
                cntB--;
            }
            l.pop_front();
        }
    }
    if(cntA==0 && cntB==0){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
}
int main()
{
    int quaries;
    cin >> quaries;
    while (quaries)
    {
        string s;
        cin >> s;
        checkSame(s);
        quaries--;
    }
    return 0;
}