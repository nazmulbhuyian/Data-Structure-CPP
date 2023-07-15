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
        list<char> ch2;
        for (int i = 0; i < clo; i++)
        {
            char ch;
            cin >> ch;
            if (ch2.size() == 0)
            {
                ch2.push_back(ch);
            }
            else
            {
                if (ch == ch2.back())
                {
                    ch2.pop_back();
                }
                else
                {
                    if ((ch == 'R' && ch2.back() == 'G') || (ch == 'G' && ch2.back() == 'R'))
                    {
                        ch2.pop_back();
                        if(ch2.back() == 'Y'){
                            ch2.pop_back();
                        }else ch2.push_back('Y');
                    }
                    else if ((ch == 'R' && ch2.back() == 'B') || (ch == 'B' && ch2.back() == 'R'))
                    {
                        ch2.pop_back();
                        if(ch2.back() == 'P'){
                            ch2.pop_back();
                        }else ch2.push_back('P');
                    }

                    else if ((ch == 'G' && ch2.back() == 'B') || (ch == 'B' && ch2.back() == 'G'))
                    {
                        ch2.pop_back();
                        if(ch2.back() == 'C'){
                            ch2.pop_back();
                        }else ch2.push_back('C');
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