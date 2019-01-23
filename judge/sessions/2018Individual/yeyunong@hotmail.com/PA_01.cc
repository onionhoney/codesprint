#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int testcase_no;
    cin>>testcase_no;
    for(int i=0;i<testcase_no;i++)
    {
        int result = 0;
        int ability ;
        cin>>ability;
        int cs31_no,cs32_no;
        cin>>cs31_no;
        cin>>cs32_no;
        int cs31[1000] = {0};
        int cs32[1000] = {0};
        for(int k=0;k<cs31_no;k++)
        {
            cin>>cs31[k];
        }
        for(int j=0;j<cs32_no;j++)
        {
            cin>>cs32[j];
        }
        for(k=0;k<cs31_no;k++)
        {
            for(j=0;j<cs32_no;j++)
            {
                if(cs31[k]+cs32[j]>ability)
                    continue;
                else
                {
                    result = max(result,cs31[k]+cs32[j]);
                }
            }
        }
        cout<<result<<endl;
    }
}