#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
        int numCases;
                cin >> numCases;

                for (int i = 0; i < numCases; i++)
                {
                        int maxJumps;
                        cin >> maxJumps;

                        int ops31, ops32;
                        cin >> ops31 >> ops32;

                        int sizes31[ops31];
                        int sizes32[ops32];

                        for (int i = 0; i < ops31; i++)
                        {
                                scanf("%d", &sizes31[i]);
                        }

                        for (int i = 0; i < ops32; i++)
                        {
                                scanf("%d", &sizes32[i]);
                        }

                        int maxSize = 0;

                        for (int i = 0; i < ops31; i++)
                        {
                                for (int j = 0; j < ops32; j++)
                                {
                                        int posSize = sizes31[i] + sizes32[j];
                                        if ( posSize > maxSize && posSize < maxJumps )
                                                maxSize = posSize;
                                }
                        }

                        cout << maxSize << endl;
                }

        return 0;
}
