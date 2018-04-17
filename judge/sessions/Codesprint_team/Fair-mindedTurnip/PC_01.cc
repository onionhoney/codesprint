#include <iostream>
#include <string>
using namespace std;

bool pnp(int speed, int loc, int period){
    double time = double(loc)/double(speed);
    
    int judge = time/period;
    
    if (judge%2 == 0)
    {
        //cerr << "uh!";
        return true;
        
    }
    else{
        return false;
        
    }
    
}
int main()
{
    int numtest;
    cin >> numtest;
    string answer = "";
    for (int i = 0; i < numtest; i++)
    {
        int d;
        int n;
        int r;
        cin >> d;
        cin >> n;
        cin >> r;
//        cerr << d;
//        cerr << n;
//        cerr << r;
        int lights[n][2];
        for (int i = 0; i < n; i++)
        {
            cin >> lights[i][0];
            cin >> lights[i][1];
        
        }
        
        int speed = -1;
        for (int i = r; i > 0; i--)
        {
            bool pass = true;
            for (int j = 0; j < n; j++)
            {
                if (!(pnp(i,lights[j][0],lights[j][1])))
                {
                    pass = false;
                    
                    break;
                }
            }
            if (pass == true){
                speed = i;
                //cerr << speed;
                break;
            }
        }
        
        answer += to_string(speed);
        answer += "\n";
        speed = -1;
        
        /* code */
    }
    cout << answer;
}
