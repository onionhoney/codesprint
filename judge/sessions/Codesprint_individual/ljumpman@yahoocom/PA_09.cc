//codesprint: January 28, 2017
//main.cpp

#include <iostream>
using namespace std;

int main()
{
    int t, n, p, bi, ni;
    cin >> t;
    
    if (t < 1 || t > 100)
    cout << "Invalid." << endl;
    
    for (int i = 0; i < t; i++)
    {
        cin >> p >> n;
        if (p < 1 || p > 1000)
        cout << "Invalid." << endl;
        if (n < 1 || n > 50000)
        cout << "Invalid." << endl;
        
        int sum = 0;
        int j = 0;
        while(j < n)
        {
            cin >> bi >> ni;
            sum += bi * ni;
            j+=ni;
        }
        cout << sum << endl;
    }
}




