
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
        //cout<<"type num = "<<typeNum<<endl;
        //cout<<"total num = " <<totalNum<<endl;

        int i;
        for (i = 0; i < typeNum; i++)
        {
            //cout << "current type num = "<<i+1<<endl;
            int type = 0;//beauty level
            int boardem = 0;//num to get bored.
            cin >> type >> boardem;
            //cout<<"type = "<<type<<endl;
            //cout<<"boardem = "<<boardem<<endl;
            //cout<<"current num = " << currentNum<<endl;
            //cout<<"result = "<<result<<endl;
            
            
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
             //cout<<"current num after if= " << currentNum<<endl;
             //cout<<"result after if= "<<result<<endl;
        }
        if (i == typeNum)
            cout<<result<<endl;
        casesLeft--;
    }
}
