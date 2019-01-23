#include <iostream>
using namespace std;

int createUnhappiness(int * mental, int mentalSize, int * tiltStrength, int tiltStrengthSize, int numPings);

int main()
{
        int numCases;
        cin >> numCases;

        for (int i = 0; i < numCases; i++)
        {
                int numPings;
                cin >> numPings;

                int teamSize;
                cin >> teamSize;

                int pingTypes;
                cin >> pingTypes;

                int mental[teamSize];
                int tiltStrength[pingTypes];

                for (int i = 0; i < teamSize; i++)
                {
                        cin >> mental[i];
                }

                for (int i = 0; i < pingTypes; i++)
                {
                        cin >> tiltStrength[i];
                }

                int sad = createUnhappiness(mental, teamSize, tiltStrength, pingTypes, numPings);

                cout << sad << endl;
        }
}

int createUnhappiness(int * mental, int mentalSize, int * tiltStrength, int tiltStrengthSize, int numPings)
{
    int totalUnhappiness = 0;
    for (int j = 0; j < numPings; j++)
    {
        int max = -1;
        int maxPos = -1;

        int mentalMin = -1;
        int mentalMinPos = 0;

        int tiltStrengthMin = -1;
        int tiltStrengthMinPos = 0;

        int isInTiltStrength = 0;

        for (int i = 0; i < mentalSize; i++)
        {
            if (mental[i] > max)
            {
                max = mental[i];
                maxPos = i;
            }

            if (mental[i] < mentalMin || mentalMin == -1)
            {
                mentalMin = mental[i];
                mentalMinPos = i;
            }
        }

        for (int i = 0; i < tiltStrengthSize; i++)
        {
            if (tiltStrength[i] > max)
            {
                max = tiltStrength[i];
                maxPos = i;
                isInTiltStrength = 1;
            }

            if (tiltStrength[i] < tiltStrengthMin || tiltStrengthMin == -1)
            {
                tiltStrengthMin = tiltStrength[i];
                tiltStrengthMinPos = i;
            }
        }

        totalUnhappiness += max;
		
        if (isInTiltStrength)
        {
            tiltStrength[maxPos] -= 1;
            mental[mentalMinPos] -= 1;
        }
        else
        {
            mental[maxPos] -= 1;
            tiltStrength[tiltStrengthMinPos] -= 1;
        }
		}
        return totalUnhappiness;
}