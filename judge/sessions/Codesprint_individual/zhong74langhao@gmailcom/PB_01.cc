#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int show[t];

    if (t < 1 || t > 100)
        return -1;

    for (int a = 0; a != t; a++)
    {

        int output = 0;
        int m , n;
        cin >> m , n;
       // if ( m < 2 || n > 100000)
       //     reutrn -1;

        int vertical;
        int horizontal;

        int k;
        cin >> k;

       // if (k < 1 || k > 10000)
        //    return -1;

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
