#include <iostream>
using namespace std;

long fib(int n){
    long pre = 0;
    long next = 1;
    long tmp = 0;
    for(int i = 0; i < n-1; i++){
        tmp = next;
        next = (pre + next)%100000007;
        pre = tmp;

    }
    return next;
}
int main(){
    int n_sam;
    cin >> n_sam;

    for (int i = 0; i < n_sam; i++){
        int n;
        cin >> n;
        cout << fib(n) << endl;

    }

}