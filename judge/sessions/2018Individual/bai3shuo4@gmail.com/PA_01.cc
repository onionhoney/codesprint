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

    for (int i = 0; i < n_sam; i++){

        int jump;
        cin >> jump;

        int cs_31;
        cin >> cs_31;
        int cs_32;
        cin >> cs_32;

        list<int> cs_31_size;
        list<int> cs_32_size;

        for (int i  = 0; i < cs_31; i++){
            int n;
            cin >> n;
            cs_31_size.push_back(n);
        }

        for (int i = 0; i < cs_32; i++){
            int n;
            cin >> n;
            cs_32_size.push_back(n);
        }

        cs_31_size.sort();
        cs_32_size.sort();


        list<int> res;

        for (int i = 0; i < cs_31; i++){
            int small = getlist(cs_31_size,i);
            int total = 0;
            for (int j = cs_32-1; j >= 0; j--){
                int huge = getlist(cs_32_size,j);
                total = huge + small;
                if(total <= jump)
                    break;
            }
            res.push_back(total);
        }
        res.sort();

        if(getlist(res,res.size()-1) == jump) {
            cout << jump << endl;
            continue;
        }

        for (int i = 0; i < cs_32; i++){
            int small = getlist(cs_32_size,i);
            int total = 0;
            for (int j = cs_31-1; j >= 0; j--){
                int huge = getlist(cs_31_size,j);
                total = huge + small;
                if(total <= jump)
                    break;
            }
            res.push_back(total);
        }

        res.sort();

        cout << getlist(res,res.size()-1) << endl;


    }

}