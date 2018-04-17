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





int main(int argc, const char * argv[]) {
    int num_instruction;
    cin >> num_instruction;
    vector<flower> instructionset;
    for (int i = 0; i < num_instruction; i++)
    {
        int lower, upper;
        char c;
        cin >> lower;
        cin >> upper;
        cin >> c;
        flower ins(lower, upper, c);
        instructionset.push_back(ins);
    }
    int k1,k2,k3,k4;
    cin >> k1;
    cin >> k2;
    cin >> k3;
    cin >> k4;
    
    bool out;
    
    out = false;
    for (int index = num_instruction-1; index >= 0; index--)
    {
        if (k1 <= instructionset[index].upper && k1 >= instructionset[index].lower)
        {
            cout <<instructionset[index].c << " ";
            out = true;
            break;
        }
    }
    if (!out)
        cout << 'a' << " ";
    
    
    out = false;
    for (int index = num_instruction-1; index >= 0; index--)
    {
        if (k2 <= instructionset[index].upper && k2 >= instructionset[index].lower)
        {
            cout <<instructionset[index].c << " ";
            out = true;
            break;
        }
    }
    if (!out)
        cout << 'a' << " ";
    
    
    out = false;
    for (int index = num_instruction-1; index >= 0; index--)
    {
        if (k3 <= instructionset[index].upper && k3 >= instructionset[index].lower)
        {
            cout <<instructionset[index].c << " ";
            out = true;
            break;
        }
    }
    if (!out)
        cout << 'a' << " ";
    
    
    out = false;
    for (int index = num_instruction-1; index >= 0; index--)
    {
        if (k4 <= instructionset[index].upper && k4 >= instructionset[index].lower)
        {
            cout <<instructionset[index].c << " ";
            out = true;
            break;
        }
    }
    if (!out)
        cout << 'a' << " ";
    
    
    return 0;
}