#include <iostream>
#include <vector>
using namespace std;
struct node {
    int beauty;
    int num;
};
int main(int argc, const char * argv[]) {
    int test_case = 0;
    cin >> test_case;
    for(int j = 0; j < test_case; j++){
        int flower_type = -1;
        int flower_num = -1;
        int count = 0;

        vector<node> v;

        cin >> flower_type >> flower_num;

        for(; count < flower_type; count++){
            node temp;
            cin >> temp.beauty >> temp.num;
            v.push_back(temp);
        }

        int sum = 0;
        int result = 0;
        for(int i = 0; i < v.size(); i++){
            if(sum + v[i].num <= flower_num){
                result += v[i].beauty * v[i].num;
                sum += v[i].num;
            }
            else{
                result += v[i].beauty * (flower_num - sum);
            }
        }
        cout << result << endl;
    }
}
