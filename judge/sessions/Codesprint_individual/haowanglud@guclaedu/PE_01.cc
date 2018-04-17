#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class flower{
public:
    flower(int num_type, int num_sig, char rep);
    int upper;
    int lower;
    char c;
};

flower::flower(int num_type, int num_sig, char rep)
{
    lower = num_type;
    upper = num_sig;
    c = rep;
}




int ways_to_climb(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 4;
    
    return ways_to_climb(n-1)+ways_to_climb(n-2)+2*ways_to_climb(n-3);
    
    
}



int main(int argc, const char * argv[]) {
    int num_round;
    
    cin >>num_round;
    for (int i = 0; i < num_round; i++)
    {
        vector<int> stairs;
        int num;
        cin >> num;
        
        if (num <= 0)
            return 0;
        
        for (int j = 0; j < num; j++)
        {
            int each;
            cin >> each;
            stairs.push_back(each);
        }
        
        
        int result = 1;
        for (int n = 0; n < stairs.size(); n++)
        {
            result *= ways_to_climb(stairs[n]);
        }
        
        cout << result%10007 << endl;
    }
    
    
    return 0;
}