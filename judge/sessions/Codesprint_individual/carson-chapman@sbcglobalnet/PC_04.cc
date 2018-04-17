#include <iostream>
#include <string>
#include <vector>
//#include <cmath>
//#include <sstream>
//#include <bitset>
using namespace std;

int main(int argc, const char * argv[])
{
    int t = 0; // number of test cases
    cin >> t;
    int cases = 0;
    while (cases < t){
        int m = 0; // map rows
        int n = 0; // map columns
        cin >> m >> n;
        int a = 0; // whiskers starting x
        int b = 0; // whiskers starting y
        cin >> a >> b;
        
        
        vector<string> map;
        for (int i = 0; i < m; i++){
            string mapLine;
            cin >> mapLine;
            map.push_back(mapLine);
        }
        
        string result = "";
        
        // start pos = a, b
        
        a = a - 1;
        b = b - 1;
        bool searching = true;
        while (searching){
            // check up
            if (a - 1 >= 0){
                if (map[a - 1][b] == '#'){
                    map[a - 1][b] = '.';
                    a = a - 1;
                    result = result + "U";
                    continue;
                }
            }
            if (a + 1 < m){
                // check down
                if (map[a + 1][b] == '#'){
                    map[a + 1][b] = '.';
                    a = a + 1;
                    result = result + "D";
                    continue;
                }
            }
            if (b - 1 >= 0){
                // check left
                if (map[a][b - 1] == '#'){
                    map[a][b - 1] = '.';
                    b = b - 1;
                    result = result + "L";
                    continue;
                }
            }
            // check right
            if (b + 1 < n){
                if (map[a][b + 1] == '#'){
                    map[a][b + 1] = '.';
                    b = b + 1;
                    result = result + "R";
                    continue;
                }
            }
            searching = false;
        }
        cases++;
        cout << result << endl;
    }

    return 0;
}
