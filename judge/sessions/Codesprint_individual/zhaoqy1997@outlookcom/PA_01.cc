#include <string>
using namespace std;

int main()
{
    int numOfCases = 0;
    cin>>numOfCases;
    
    int casesLeft = numOfCases;
    
    while (casesLeft != 0)
    {
        int currentNum = 0;
        int result = 0;
        //for each case: title + content
        int typeNum = 0, totalNum = 0;
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
            }
            else
            {
                result += (totalNum-currentNum)*type;
            }
            boardomTotal += boardem;
        }
        casesLeft--;
        cout<<result<<endl;
    }
}
