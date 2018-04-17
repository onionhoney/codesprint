#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int show[t];

    for (int a = 0; a != t; a++)
    {
        int output = 0;
        int m, n;
        cin >> m >> n;

        int vertical = 0;
        int horizontal = 0;

        int k;
        cin >> k;

        for (int j = 0; j != k; j++)
        {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            if (x1 == x2)
                vertical++;
            if (y1 == y2)
                horizontal++;
        }

        int temp = vertical + 1;

        output = horizontal * temp;
        show[a] = output;
    }

    for (int i = 0; i != a; i++)
        cout << show[a] << endl;

    cout << endl;
    return 0;
}
