#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int testcase_no;
    cin>>testcase_no;
    int results[15];
    for(int i=0;i<testcase_no;i++)
    {
        int room_num,passage_num,ability,max_possible;
        cin>>room_num;
        cin>>passage_num;
        cin>>ability;
        int result = passage_num;
        int* connected = new int[room_num+1]{};
        map<int,int> component;
        int* component_size = new int[room_num+1]{};
        max_possible = room_num*(room_num-1)/2;
        int index = 0;
        for(int k=0;k<passage_num;k++)
        {
            int first,second;
            cin>>first;
            cin>>second;
            connected[first]++;
            connected[second]++;
            if(connected[first]==1&&connected[second]==1)
            {
                component[first] = index;
                component[second] = index;
                component_size[index]+=2;
                index++;
            }
            else if(connected[first]==1)
            {
                component[first] = component[second];
                component_size[component[first]]++;
            }
            else if(connected[second]==1)
            {
                component[second] = component[first];
                component_size[component[first]]++;
            }
        }
        for(int k=1;k<=room_num;k++)
        {
            if(component.find(k)==component.end())
            {
                component_size[index] = 1;
                index++;
            }
        }
        result = 0;
        for(int k=0;k<room_num;k++)
        {
            result+= component_size[k]*(component_size[k]-1)/2;
        }
        for(int k=0;k<ability;k++)
        {
            int max = 0;
            int max_index = 0;
            int second_max = 0;
            int second_index = -1;
            for(int p=0;p<room_num;p++)
            {
                if(component_size[p]>max)
                {
                    max = component_size[p];
                    max_index = p;
                }
                else if(component_size[p]>second_max)
                {
                    second_max =  component_size[p];
                    second_index = p;
                }
            }
            if(second_index==-1)
            {
                result = max_possible;
                break;
            }
            result+= max*second_max;
            component_size[max_index] += second_max;
            component_size[second_index] = 0;
        }
        delete []connected;
        delete []component_size;
        results[i] = result;
    }
    for(int i=0;i<testcase_no;i++)
    {
        cout<<results[i]<<endl;
    }
}