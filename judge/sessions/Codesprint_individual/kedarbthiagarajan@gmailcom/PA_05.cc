//
//  main.cpp
//  codesprint
//
//  Created by Kedar Thiagarajan on 1/28/17.
//  Copyright © 2017 Kedar Thiagarajan. All rights reserved.
//

using namespace std;
#include <vector>
#include <iostream>
#include <string>
#include <math.h>

class Coord
{
private:
    int x;
    int y;
public:
    Coord(int x1, int y1);
    int getx(){return x;};
    int gety(){return y;};
};

Coord::Coord(int x1, int y1)
{
    x = x1;
    y = y1;
}
int main()
{
    int t;
    cin >> t;
    int numDom = 1;
    for(int i = 0; i < t; i++)
    {
        int m, n, k;
        cin >> m >> n;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            int x1,x2,y1,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            Coord one(x1,y1);
            Coord two(x2,y2);
            
            if(one.getx() == two.getx())
            {
                numDom *= 2;
            }
            else
                numDom += 2;
            
        }
    }
    
    cout << numDom << endl;
}