#include <iostream>
#include <vector>
//#include <string>
using namespace std;

int eachTestcase (int currentCounter, vector<int>& intVector);

int main()
{
    vector <int> intVector;
    int x;
    while (cin >> x)
    {
        intVector.push_back(x);
    }
   /* for(int i=0; i < intVector.size(); i++){
        cout<<intVector[i]<<endl;
    }*/
    
    int testcase = intVector [0];

    int counter = 0;
    //cout<<testcase<<endl;
    
    //eachTestcase (counter, intVector);
    
    while (testcase != 0)
    {
        counter =eachTestcase (counter, intVector);
        testcase --;
    }
}


int eachTestcase (int currentCounter, vector<int>& intVector)
{
    int totalBeauty = 0;
    int totalPlanted = 0;
    currentCounter ++;
    int p = intVector[currentCounter];
    //cout << "number of type "<< p <<endl;
    currentCounter ++;
    int n = intVector[currentCounter];
    //cout << "number before die "<< n <<endl;
    int whereToStop = currentCounter + 2* p ;
    //cout <<"where to stop "<< whereToStop <<endl;
    
    while (currentCounter < whereToStop)
    {
        currentCounter++;
        int beauty = intVector [currentCounter];
        currentCounter++;
        int number = intVector [currentCounter];
        if (totalPlanted + number >= n)
        {
            totalBeauty =  totalBeauty + (n-totalPlanted) *beauty;
            break;
        }
        else
        {
            totalBeauty = totalBeauty + number * beauty;
            totalPlanted = totalPlanted + number;
            
        }
        
        //cout <<"totoalbeauty is now " << totalBeauty <<endl;
    }
    //cout << "final totalbeauty is " <<totalBeauty << endl;
    cout <<totalBeauty << endl;
    return whereToStop ;
}






