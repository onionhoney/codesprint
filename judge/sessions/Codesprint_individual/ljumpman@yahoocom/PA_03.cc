//codesprint: January 28, 2017
//main.cpp

#include <iostream>
using namespace std;

int main()
{
    cout << "Test case: " << endl;
    int t, n, p, bi, ni;
    cin >> t;
    cin >> p >> n;
    int sum = 0;
    for (int i = 0; i < p; i++)
    {
        cin >> bi >> ni;
        sum += bi * ni;
    }
    
    if (t < 1 || t > 100)
        return 0;
    if (p < 1 || p > 1000)
        return 0;
    if (n < 1 || n > 50000)
        return 0;
    
    cout << sum << endl;
}




