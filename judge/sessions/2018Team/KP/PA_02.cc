#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int testcase_no;
    cin>>testcase_no;
    long long results[100];
    for(int i=0;i<testcase_no;i++)
    {
        int number,adjust_num;
        cin>>number;
        cin>>adjust_num;
        cin.get();
        int count = 0;
        char current;
        long long result = 0;
        string input;
        getline(cin,input);
        for(int k=0;k<number;k++)
        {
            char temp;
            temp = input[k];
            if(temp=='H')
                continue;
            if(count==0)
                current = temp;
            if(temp==current)
            {
                count++;
                if(count==adjust_num)
                {
                    count = 0;
                    if(temp=='L')
                    {
                        result++;
                    }
                    else if(temp=='R'){
                        result--;
                    }
                }
            }
            else
            {
                count = 1;
                current = temp;
            }
        }
      results[i] = result;
    }  
    for(int i=0;i<testcase_no;i++)
    {
        cout<<results[i]<<endl;
    }
    return 0;
}