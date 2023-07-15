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
        stack<char> test;
        list<char> ch2;
        for (int i = 0; i < clo; i++)
        {
            char ch;
            cin >> ch;
            if (ch2.size() == 0)
            {
                ch2.push_back(ch);
                test.push(ch);
            }
            else
            {
                if (ch == ch2.back())
                {
                    ch2.pop_back();
                }
                else
                {
                    if (ch == 'R' && ch2.back() == 'G')
                    {

                        ch2.back() = 'Y';
                        if (ch2.back() == test.top())
                        {
                            while (ch2.back() == test.top())
                            {
                                ch2.pop_back();
                            }
                            while (!test.empty())
                            {
                                test.pop();
                            }
                        }
                        else
                        {
                            while (!test.empty())
                            {
                                test.pop();
                            }
                            test.push('Y');
                        }
                    }
                    else if (ch == 'R' && ch2.back() == 'B')
                    {
                        ch2.back() = 'P';
                        if (ch2.back() == test.top())
                        {
                            while (ch2.back() == test.top())
                            {
                                ch2.pop_back();
                            }
                            while (!test.empty())
                            {
                                test.pop();
                            }
                        }
                        else
                        {
                            while (!test.empty())
                            {
                                test.pop();
                            }
                            test.push('P');
                        }
                    }

                    else if (ch == 'G' && ch2.back() == 'B')
                    {
                        ch2.back() = 'C';
                        if (ch2.back() == test.top())
                        {
                            while (ch2.back() == test.top())
                            {
                                ch2.pop_back();
                            }
                            while (!test.empty())
                            {
                                test.pop();
                            }
                        }
                        else
                        {
                            while (!test.empty())
                            {
                                test.pop();
                            }
                            test.push('C');
                        }
                    }
                    else if (ch == 'G' && ch2.back() == 'R')
                    {
                        ch2.back() = 'Y';
                        if (ch2.back() == test.top())
                        {
                            while (ch2.back() == test.top())
                            {
                                ch2.pop_back();
                            }
                            while (!test.empty())
                            {
                                test.pop();
                            }
                        }
                        else
                        {
                            while (!test.empty())
                            {
                                test.pop();
                            }
                            test.push('Y');
                        }
                    }

                    else if (ch == 'B' && ch2.back() == 'G')
                    {
                        ch2.back() = 'C';
                        if (ch2.back() == test.top())
                        {
                            while (ch2.back() == test.top())
                            {
                                ch2.pop_back();
                            }
                            while (!test.empty())
                            {
                                test.pop();
                            }
                        }
                        else
                        {
                            while (!test.empty())
                            {
                                test.pop();
                            }
                            test.push('C');
                        }
                    }
                    else if (ch == 'B' && ch2.back() == 'R')
                    {
                        ch2.back() = 'P';
                        if (ch2.back() == test.top())
                        {
                            while (ch2.back() == test.top())
                            {
                                ch2.pop_back();
                            }
                            while (!test.empty())
                            {
                                test.pop();
                            }
                        }
                        else
                        {
                            while (!test.empty())
                            {
                                test.pop();
                            }
                            test.push('P');
                        }
                    }

                    else
                    {
                        ch2.push_back(ch);
                    }
                }
            }
        }

        string tes;
        while (!ch2.empty())
        {
            tes += ch2.front();
            ch2.pop_front();
        }
        cout << tes << endl;

        q--;
    }

    return 0;
}