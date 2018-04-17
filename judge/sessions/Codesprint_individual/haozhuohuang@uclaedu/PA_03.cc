#include <iostream>
#include <vector>
using namespace std;
struct node {
    int beauty;
    int num;
};
int main(int argc, const char * argv[]) {
    int a = 0;
    int b = 0;
    int c= 0;
    bool flag = false;
    while(true){
        int test_case;
        int flower_type;
        int flower_num;
        int count = 0;
        if(!flag){
            cin >> test_case;
            flag = true;
        }

        vector<node> v;

        cin >> flower_type >> flower_num;
        cout << flower_type << flower_num << endl;
        for(; count < flower_type; count++){
            node temp;
            cin >> temp.beauty >> temp.num;
            v.push_back(temp);
        }

        int sum = 0;
        int result = 0;
        for(int i = v.size() - 1; i >=0; i--){
            if(sum <= flower_num + v[i].num){
                result += v[i].beauty * v[i].num;
            }
            else{
                result += v[i].beauty * (flower_num - sum);
            }
        }

        cout << result << endl;

    }
}
