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
        stack<char> ch2;
        string cha;
        cin >> cha;
        for (char ch : cha)
        {

            if (ch2.size() == 0)
            {
                ch2.push(ch);
            }
            else
            {
                if (ch == ch2.top())
                {
                    ch2.pop();
                }
                else
                {
                    if ((ch == 'R' && ch2.top() == 'G') || (ch == 'G' && ch2.top() == 'R'))
                    {
                        ch2.pop();
                        while (!ch2.empty() && ch2.top() == 'Y')
                        {
                            ch2.pop();
                            break;
                        }
                        ch2.push('Y');
                    }
                    else if ((ch == 'R' && ch2.top() == 'B') || (ch == 'B' && ch2.top() == 'R'))
                    {
                        ch2.pop();
                        while (!ch2.empty() && ch2.top() == 'P')
                        {
                            ch2.pop();
                            break;
                        }
                            ch2.push('P');
                    }

                    else if ((ch == 'G' && ch2.top() == 'B') || (ch == 'B' && ch2.top() == 'G'))
                    {
                        ch2.pop();
                        while (!ch2.empty() && ch2.top() == 'C')
                        {
                            ch2.pop();
                            break;
                        }
                            ch2.push('C');
                    }

                    else
                    {
                        ch2.push(ch);
                    }
                }
            }
        }

        stack<char> qu;
        while (!ch2.empty())
        {
            qu.push(ch2.top());
            ch2.pop();
        }
        while (!qu.empty())
        {
            cout << qu.top();
            qu.pop();
        }
        cout<<endl;
        q--;
    }

    return 0;
}