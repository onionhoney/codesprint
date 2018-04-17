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
    
    if (t < 1 || t > 100)
    cout << "Invalid." << endl;
    if (p < 1 || p > 1000)
    cout << "Invalid." << endl;
    if (n < 1 || n > 50000)
    cout << "Invalid." << endl;
    
    int sum = 0;
    for (int i = 0; i < p; i++)
    {
        if (i == n)
            cout << sum << endl;
        cin >> bi >> ni;
        sum += bi * ni;
    }
    
}




