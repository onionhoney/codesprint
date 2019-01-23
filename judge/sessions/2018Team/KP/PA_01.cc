#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int testcase_no;
    cin>>testcase_no;
    for(int i=0;i<testcase_no;i++)
    {
        int number,adjust_num;
        cin>>number;
        cin>>adjust_num;
        int count = 0;
        char current;
        int result = 0;
        for(int k=0;k<number;k++)
        {
            char temp;
            cin>>temp;
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
        cout<<result<<endl;
    }
    return 0;
}