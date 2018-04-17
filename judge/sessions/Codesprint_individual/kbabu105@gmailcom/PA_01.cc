//
//  main.cpp
//  CodeSprint
//
//  Created by Krishna on 1/28/17.
//  Copyright © 2017 Krishna. All rights reserved.
//

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    //in:
    //1:
        //t # test cases [1, 100]
    //2:
        //p # types of flowers she can draw [1, 1000]
        //n # flowers she can draw  b4 dead tablet [1,5000]
    //3:
        //p lines w/ ith line signifying of type i flower:
            //bi [<=1000] beauty of flower of type i
            //ni [>=1] # of flowers willing to draw of type i
    
    
    //out:
    //Output a single integer for each test case,
        //the maximum beauty of a field Rin can create.
    //cout << "Input\n";

    int t(0);
    cin >> t;
    
    for(int j = t; j > 0; j--)
    {
    int p(0), n(0), bsum(0), bi(0), ni(0), flowers(0);
        
    cin >> p >> n;
    
    for (int i = p; i > 0; i--)
    {
        int nicount(0);
        cin >> bi >> ni;

        while(((flowers+1)<=n) && (nicount<ni))
        {
            bsum += bi;  //sum of beauties as long as not over ni of that ith flower
            nicount++;
            flowers++;
        }
    }

    cout << bsum << "\n";}
    
    
    return 0;
}
