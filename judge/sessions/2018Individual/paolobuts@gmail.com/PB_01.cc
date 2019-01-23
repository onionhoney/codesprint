#include <iostream>
#include <string>
using namespace std;
int main() {
    int nums;
    cin >>nums;
    cin.ignore(10,'\n');
    for (int i=0;i<nums;i++){ // traverse file
        for (int j=0;j<3;j++){ // traverse test case
            string current;
            getline(cin, current);
            for (int k=0;k<199;k++) // traverse line
                if(current[k]=='1'){
                    cout << (k)/2;
                    if(j!=2)
                        cout<< ' ';
                    break;
                }
        }
        cout << endl;
    }
}