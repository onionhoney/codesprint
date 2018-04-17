#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
    int beautyArray[50000];
    int maxIndTypeArray[50000];
    int maxTestCases = 100;
    int testCaseNumber = 0;
    int maxType;
    int maxTotal = 0;
    int beauty;
    int maxIndType;
    int pos = 0;
    int finalBeauty[100];
    
    cin >> maxTestCases;
    
    while (testCaseNumber != maxTestCases)
    {
        cin >> maxType >> maxTotal;
        for (int c = 0; c < maxType; c++)
        {
            cin >> beauty >> maxIndType;
            beautyArray[pos] = beauty;
            maxIndTypeArray[pos] = maxIndType;
            pos++;
        }
        pos  = 0;
        for (int c = 0; c < maxType; c++)
        {
            if (maxIndTypeArray[pos] < maxTotal)
            {
                finalBeauty[testCaseNumber] += maxIndTypeArray[pos] * beautyArray[pos];
                maxTotal = maxTotal - maxIndTypeArray[pos];
                pos++;
            }
            else if (maxIndTypeArray[pos] == maxTotal)
            {
                finalBeauty[testCaseNumber] += maxIndTypeArray[pos] * beautyArray[pos];
                maxTotal = maxTotal - maxIndTypeArray[pos];
                break;
            }
            else
            {
                finalBeauty[testCaseNumber] += maxTotal * beautyArray[pos];
                maxTotal = 0;
                break;
            }
        }
        for (int c = 0; c < maxType; c++)
        {
            beautyArray[c] = 0;
            maxIndTypeArray[c] = 0;
        }
        testCaseNumber++;
        maxType = 0;
        maxTotal = 0;
        beauty = 0;
        maxIndType = 0;
        pos = 0;
    }
    for (int c = 0; c < maxTestCases; c++)
    {
        cout << finalBeauty[c] << endl;
    }
}
