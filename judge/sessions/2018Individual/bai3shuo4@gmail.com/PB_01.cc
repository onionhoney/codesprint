#include <iostream>
#include <list>
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
int main(){
    int n_sam;
    cin >> n_sam;

    for(int i = 0; i < n_sam; i++){

        int count[3] = {0,0,0};
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 100; k++){
                int curr;
                cin >> curr;
                if(curr == 0)
                    count[j]++;
            }
        }
        cout << count[0] << ' '<< count[1] << ' '<< count[2] << endl;



    }

}