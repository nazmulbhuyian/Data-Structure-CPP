// Problem Statement

// Arif, the magician is putting some magic colors in a box serially. But he is not providing any divider between the colors. So, the color may be mix up instantly.

// There are three types of colors- Red, Green and Blue. How they could mix up is given below -

// Red+Blue = Purple
// Red+Green = Yellow
// Blue+Green = Cyan
// And there are some other problems. If two same type of colors mix up, they will vanish each other. For example if two Purple colors get together, both of them will be vanished.

// Can you help the magician to get the final colors that will be in the box?

// Input Format

// First line will contain T, the number of test cases.
// Next line will contain N, number of colors in the box.
// Next line will contain N characters (R,G,B only) , first capital letter of the color.
// Constraints

// 0 < T <= 100
// 0 < N <= 100
// Output Format

// Output the first capital letter of the colors that are saved finally. If there are no colors in the box, the output could be empty in that case.
// Sample Input 0

// 2
// 3
// RBG
// 4
// RGBB
// Sample Output 0

// PG
// Y
// Sample Input 1

// 6
// 6
// RGGRRG
// 6
// RGRGRG
// 4
// RGGR
// 5
// RGGGR
// 4
// RGGB
// 18
// RBRBRBGRBRRGBGGBGB
// Sample Output 1

// Y
// Y

// YR
// YC
// PYPYC

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    while (q)
    {
        int clo;
        cin >> clo;
        stack<char> ch1;
        stack<char> ch2;
        // for (int i = 0; i < clo; i++)
        // {
            string sCh;
            cin >> sCh;
            for (char ch : sCh)
            {
                ch1.push(ch);
                if (ch2.size() == 0)
                {
                    ch2.push(ch);
                }
                else
                {
                    if(ch==ch2.top()){
                        ch2.pop();
                    }else{
                        if(ch=='R' && ch2.top()=='G'){
                            ch2.top()='Y';
                        }
                        else if(ch=='R' && ch2.top()=='B'){
                            ch2.top()='P';
                        }

                        else if(ch=='G' && ch2.top()=='B'){
                            ch2.top()='C';
                        }
                        else if(ch=='G' && ch2.top()=='R'){
                            ch2.top()='Y';
                        }

                        else if(ch=='B' && ch2.top()=='G'){
                            ch2.top()='C';
                        }
                        else if(ch=='B' && ch2.top()=='R'){
                            ch2.top()='P';
                        }
                        
                        else{
                            ch2.push(ch);
                        }
                    }
                }
            }
        // }

        string test;
        while (!ch2.empty())
        {
            // cout<<ch1.top()<<" ";
            test += ch2.top();
            ch2.pop();
        }
        cout<<test<<endl;

        q--;
    }

    return 0;
}