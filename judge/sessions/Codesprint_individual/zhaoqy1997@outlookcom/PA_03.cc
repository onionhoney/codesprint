
#include <iostream>
using namespace std;

int main()
{
    int numOfCases;
    cin>>numOfCases;
    
    int casesLeft = numOfCases;
    
    while (casesLeft != 0)
    {
        int currentNum = 0;
        int result = 0;
        //for each case: title + content
        int typeNum, totalNum;
        cin>>typeNum>>totalNum;
        
        int boardomTotal = 0;
        
        for (int i = 0; i < typeNum; i++)
        {
            int type = 0;//beauty level
            int boardem = 0;//num to get bored.
            cin >> type >> boardem;
            
            
            if (currentNum+boardem <= totalNum)
            {
                result += type*boardem;
                currentNum += boardem;
            }
            else
            {
                result += (totalNum-currentNum)*type;
                cout<<result<<endl;
                break;
            }
            boardomTotal += boardem;
        }
        casesLeft--;
    }
}
