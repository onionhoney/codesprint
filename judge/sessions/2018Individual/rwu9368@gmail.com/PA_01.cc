#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <cmath>
#include <sstream>
 
using namespace std;

string line;
ifstream infile;
int t, n, p, q;
int a[];
int b[];

istringstream instream;
infile.open("input.txt");

getline(infile, line);        
	instream.clear();
        instream >> atoi(t);
getline(infile, line);
	instream.clear();
	instream >> atoi(n);  	
getline(infile, line);
        instream.clear();
        instream >> atoi(p) >> atoi(q);
 getline(infile, line);
        instream.clear();
	while (i = 0; i < p; i++)
		instream >> atoi(a);
 getline(infile, line);
        instream.clear();
        while (i = 0; i < q; i++)
                instream >> atoi(b);


int aa[t];
for (i = 0; i < t; i++){
	int max = 0;
	for (int j = 0; j < p; j++){
		for (int k = 0; k < q; k++){
			int temp = a[j] + b[k];
			if (temp > max)
				max = temp;
		}
	}
	aa[t-1] = max;
}

return;
 


