#include <iostream>
#include <string>

using namespace std;

int main()
{
    char a, b, c, d;
    a = 'a';
    b = 'a';
    c = 'a';
    d = 'a';

    int t;
    cin >> t;

    int range [t][2];
    char show[t];

    for (int k = 0; k != t; k++)
    {
        int l, r;
        char cc;

        cin.ignore(100000000000000, '\n');

        cin >> l >> r >> cc;
        range[k][0] = l;
        range[k][1] = r;
        show[k] = cc;
    }

    int aaa, bbb, ccc, ddd;

    cin >> aaa >> bbb >> ccc >> ddd;

    int leftmost = 0;
    int note = 0;

    for (int k = 0; k != t; k++)
    {
        if (range[k][0] < aaa && range[k][1] > aaa)
        {
            if (range[k][0] > leftmost)
                {leftmost = range[k][0];
                    a = show[k];
                }
        }
    }

    leftmost = 0;
    note = 0;

    for (int k = 0; k != t; k++)
    {
        if (range[k][0] < bbb && range[k][1] > bbb)
        {
            if (range[k][0] > leftmost)
            {
                leftmost = range[k][0];
                b = show[k];
            }

        }
    }

    leftmost = 0;
    note = 0;

    for (int k = 0; k != t; k++)
    {
        if (range[k][0] < ccc && range[k][1] > ccc)
        {
            if (range[k][0] > leftmost)
                {leftmost = range[k][0];
                 c = show[k];
                }
        }
    }

    leftmost = 0;
    note = 0;

    for (int k = 0; k != t; k++)
    {
        if (range[k][0] < ddd && range[k][1] > ddd)
        {
            if (range[k][0] > leftmost)
                {leftmost = range[k][0];
                 d = show[k];
                }
        }

    }

    cout << a << " " << b << " " << c << " " << d;
    cout <<  endl;
    return 0;
}
