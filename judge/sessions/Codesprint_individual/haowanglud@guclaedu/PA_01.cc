#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class flower{
public:
    flower(int num_type, int num_sig);
    int num;
    int sig;
};

flower::flower(int num_type, int num_sig)
{
    num = num_type;
    sig = num_sig;
}

bool small(flower x, flower y)
{
    return x.sig < y.sig;
}


int main(int argc, const char * argv[]) {
    int num_round;
    int num_type;
    int num_total;
    cin >> num_round;
    
    for (int i = 0; i < num_round; i++)
    {
        bool finish = false;
        cin >> num_type;
        cin >> num_total;
        vector<flower> flowerset;
//        vector<int> significance;
        for (int j = 0; j < num_type; j++)
        {
            int num_type_i, num_level_i;
            cin >> num_level_i;
            cin >> num_type_i;
            flower x(num_type_i, num_level_i);
            flowerset.push_back(x);
        }
        
        sort(flowerset.begin(), flowerset.end(),small);
        
        int total_score = 0, n=0;
        
        for (int index = (int)flowerset.size()-1; index >= 0; index--)
        {
            //count current number of each type
            int each = 0;
            
            while (each < flowerset[index].num)
            {
                total_score += flowerset[index].sig;
                each++;
                n++;
                
                if (n == num_total || ((index == 0) && (each == flowerset[index].num)))
                {
                    cout <<  total_score << endl;
                    finish = true;
                    break;
                }
            }
            if (finish)
                break;
        }

        
        
    }
    
    
    return 0;
}
