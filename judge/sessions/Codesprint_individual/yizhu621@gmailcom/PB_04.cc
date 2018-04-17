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
    int size[tc];
    for (int i = 0; i < tc; i++)
    {
        size[i] = 0;
        int m, n, l;
        int p = 0;
        int q = 0;
        cin >> m >> n;
        cin >> l;
        for (int j = 0; j < l; j++)
        {
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            if (a == c)
            {
                if (a != 0 and a != m)
                    p += 1;
            }
            if (b == d)
            {
                if (b != 0 and b != n)
                    q += 1;
            }
        }
        size[i] = (p+1) * (q+1);
    }
    for (int i = 0; i < tc; i++)
        cout << size[i] << endl;
}
