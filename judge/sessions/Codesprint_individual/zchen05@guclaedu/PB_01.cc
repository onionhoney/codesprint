#include <iostream>
#include <vector>
using namespace std;

int eachTestCase (int currentCounter, vector<int>& intVector);

int main()
{
    vector <int> intVector;
    int x;
    while (cin >> x)
    {
        intVector.push_back(x);
    }
    //for(int i=0; i < intVector.size(); i++){
    //    cout<<intVector[i]<<endl;
    //}
    
    int testcase = intVector [0];
    
    int counter = 0;
    
    while (testcase != 0)
    {
        //cout << "This is a test case"<<endl;
        counter = eachTestCase (counter, intVector);
        testcase --;
    }
}

int eachTestCase (int currentCounter, vector<int>& intVector)
{
    currentCounter ++;
    int m_length = intVector[currentCounter];
    currentCounter ++;
    int n_width = intVector[currentCounter];
    currentCounter ++;
    int total_line = intVector[currentCounter];
    int whereToStop = currentCounter + total_line * 4;
    //cout <<"where to stop is "<<whereToStop<<endl;
    int lpart = 1;
    int wpart = 1;
    while (currentCounter < whereToStop)
    {
        currentCounter++;
        int x1 = intVector[currentCounter];
        currentCounter++;
        int y1 = intVector[currentCounter];
        currentCounter++;
        int x2 = intVector[currentCounter];
        currentCounter++;
        int y2 = intVector[currentCounter];
        if(x1 == x2 && (y1 == n_width || y2 == n_width) )
            lpart ++;
        if(y1 == y2 && (x1 == m_length || x2 == m_length))
            wpart ++;
    }
   // cout<<"l part is "<<lpart <<" w part is "<<wpart<<endl;
    cout << lpart * wpart <<endl;
    return whereToStop ;
    
}