#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    int testcase;
    cin>>testcase;
    for(int i=0;i<testcase;i++)
    {
        int number;
        int ability;
        cin>>number;
        cin>>ability;
        int table[1002];
        int opt[1002][1002]={0} ;
        int count[1002][1002] = {0};
        for(int k=1;k<=number;k++)
        {
            int temp;
            cin>>temp;
            table[k] = temp;
        }
        for(int k=2;k<=number+1;k++ )
        {
            for(int j=2;j<=ability+1;j++)
            {
                if(k==number+1&&j==ability+1)
                {
                    if(count[k-1][j]!=ability+1){
                        opt[k][j] = opt[k-2][j-1]+table[k-1];
                        break;
                    }
                    else if(count[k-2][j-1]!=ability)
                    {
                        opt[k][j] =opt[k-1][j];
                        break;
                    }

                }
                opt[k][j] = max(opt[k-1][j],opt[k-2][j-1]+table[k-1]);
                if(opt[k-1][j]>opt[k-2][j-1]+table[k-1])
                    count[k][j] = count[k-1][j];
                else
                    count[k][j] = count[k-2][j-1]+1;
            }
        }
        cout<<opt[number+1][ability+1]<<endl;
    }
}