#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x;
    int input;
    vector<unsigned long long int> fib_vec;
    cin >> x;
    
    for (int i = 0; i < x; i++){
        unsigned long long int prev = 0;
        unsigned long long int current = 1;
        unsigned long long int temp = 0;
        cin >> input;
        if (input == 1){
            fib_vec.push_back(1);
        }
        else{
            for (int i = 1; i < input; i++){
                temp = prev + current;
                prev = current;
                current = temp;
            }
            fib_vec.push_back(temp%100000007);
        }
    }
    
    for (int i = 0; i < fib_vec.size(); i++){
        cout << fib_vec[i] << endl;
    }
    
    
    return 0;
}
