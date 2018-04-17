#include <iostream>

using namespace std;

int main()
{

    int t;
    cin >> t;

    int show[t];

    for (int k = 0; k != t; k++)
    {

        int p, n;
        cin >> p >> n;

        int arr[p][2];

        for (int i = 0; i != p; i++)
        {
            int beauty;
            int willing;
            cin >> beauty >> willing;
            arr[i][0] = beauty;
            arr[i][1] = willing;
        }

        int counting = 0;
        int total = 0;

        for (int c = 0; c != p; c++)
        {
            for (int j = 0; j != p; j++)
            {
                int maximum = 0;
                int pos = 0;
                int maximumN = 0;
                if (arr[j][0] > maximum)
                {
                    maximum = arr[j][0];
                    maximumN = arr[j][1];
                    pos = j;
                }

                for (int d = 0; d != maximumN; d++)
                {
                    total += maximum;
                    counting++;
                    if (counting == n)
                        break;

                }

                arr[j][0] = 0;
                arr[j][1] = 0;

            }


            if (counting == n)
                break;

        }

        show[k] = total;

    }

    for (int k = 0; k != t; k++)
        cout << show[k] << endl;

    cout << endl;
    return 0;
}
