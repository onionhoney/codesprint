#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int getlist(list<int> &list_tmp,int n){
    auto it1 = next(list_tmp.begin(), n);
    return *it1;
}

void readlist(list<int> &intList){
    list<int>::const_iterator iterator;
    for (iterator = intList.begin(); iterator != intList.end(); ++iterator) {
        std::cout << *iterator << ' ';
    }

    cout << endl;
}

bool contains(list<int> &intList, int var){
    return (std::find(intList.begin(), intList.end(), var) != intList.end());
}

int min(int a, int b){
    return a>b?b:a;
}

int C_x_2(int x){
    return x*(x-1)/2;
}
int main(){

    int n_sample;
    cin >> n_sample;

    for(int sample = 0; sample < n_sample; sample++) {


        int shot_number;
        int miss_number;

        cin >> shot_number;
        cin >> miss_number;

        string shot_seq;
        cin >> shot_seq;

        int position = 0;
        int record_cons = 0;
        char pre = shot_seq[1];
        for (int i = 2; i <= shot_number; i++) {
            if (pre != shot_seq[i]) {
                record_cons = 0;
                pre = shot_seq[i];
            } else {
                if (shot_seq[i] == 'R') {
                    if (record_cons == miss_number - 1)
                        position--;
                    else if (record_cons < miss_number - 1)
                        record_cons++;
                } else if (shot_seq[i] == 'L') {
                    if (record_cons == miss_number - 1)
                        position++;
                    else if (record_cons < miss_number - 1)
                        record_cons++;
                }

            }
        }

        cout << position << endl;
    }

}