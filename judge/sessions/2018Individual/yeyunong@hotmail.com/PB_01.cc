#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int testcase_no;
    cin>>testcase_no;
    for(int i=0;i<testcase_no;i++)
    {
        int results[3];
        for(int k=0;k<3;k++)
        {
            for(int j=0;j<100;j++)
            {
                int temp;
                cin>>temp;
                if(temp==1)
                {
                    results[k] = j;
                }
            }
        }
        for(int k=0;k<2;k++)
        {
            cout<<results[k]<<" ";
        }
        cout<<results[2]<<endl;
    }
}