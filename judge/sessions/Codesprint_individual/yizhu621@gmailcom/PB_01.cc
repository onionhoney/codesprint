//
//  main.cpp
//  CodesprintLA ProblemB
//
//  Created by Yizhu Zhang on 1/28/17.
//  Copyright © 2017 Yizhu Zhang. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int m, n, l;
        int p = 0;
        int q = 0;
        cin >> m >> n;
        cin >> l;
        for (int j = 0; j < l; j++)
        {
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            if (c == m)
                p += 1;
            if (d == n)
                q += 1;
        }
        cout << (p+1)*(q+1) << endl;
    }
}
