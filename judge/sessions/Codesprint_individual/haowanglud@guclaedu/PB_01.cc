#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class flower{
public:
    flower(int num_type, int num_sig);
    int x;
    int y;
};

flower::flower(int num_type, int num_sig)
{
    x = num_type;
    y = num_sig;
}



int main(int argc, const char * argv[]) {
    int num_round;
    cin >> num_round;
    
    for (int i = 0; i < num_round; i++)
    {
        int hori, vert, linenum;
        cin >> hori;
        cin >> vert;
        cin >> linenum;
        
        int num_vert = 0, num_hori = 0;
        
        for (int j = 0; j < linenum; j++)
        {
            int x1, y1, x2, y2;
            cin >> x1;
            cin >> y1;
            cin >> x2;
            cin >> y2;
            if (x1 == x2)
                num_vert++;
            if (y1 == y2)
                num_hori++;
            
        }
        cout << (num_hori+1)*(num_vert+1) << endl;
        
        
        
        
        
        
    }
    
    
    return 0;
}