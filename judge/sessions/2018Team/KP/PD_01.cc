#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class DistrictMap{

public:
    bool* chosen;
    int numDist;

    DistrictMap(int f){
        numDist = f;
        chosen = new bool[f];
    }

    ~DistrictMap(){
        delete [] chosen;
    }
};

void loadStringToBoolArr(string rep, bool* arr, int size){
    for (int i=0; i< size; i++){
        arr[i] = (rep[i]=='1');
    }
}

int countOnes(string s){
    int size=s.size(), count =0;
    for (int i=0;i<size;i++){
        if (s[i]== '1')
            count++;
    }
    return count;
}

void fillDistrictMapArr(DistrictMap* arr[], string partial, int& count,const int& k){
    //cout << "recursive call: " << partial << endl;
    int n = arr[0]->numDist;
    if(partial.size() == n){
        if(countOnes(partial)==k){
            loadStringToBoolArr(partial, arr[count]->chosen, n);
            count++;
        }
        return;
    }
    fillDistrictMapArr(arr, partial + '0', count,k);
    if (partial.size()==0 || partial[partial.size()-1] != '1')
        fillDistrictMapArr(arr, partial + '1', count,k);
}

int fillDistrictMapArr(DistrictMap* arr[], const int& k){
    int count =0;
    fillDistrictMapArr(arr,"",count,k);
    return count;
}

void loadOnArray(string targets, int targetsArr[]){
    string current;
    int startPos=0;
    int count=0;
    int i=0;
    for (;i<targets.size();i++){
        if(targets[i]==' ') {
            current = targets.substr(startPos, i - startPos);
            startPos = i+1;
            targetsArr[count] = stoi(current);
            count++;
        }
    }
    targetsArr[count] = stoi(targets.substr(startPos, i - startPos));
}

int main() {
    int nums;
    cin >>nums;
    for (int i=0; i<nums;i++){
        int n, k;
        cin >> n;
        cin >> k;
        cin.ignore (10,'\n');
        string populations;
        getline(cin, populations);
        int* populationsArr = new int[n];
        loadOnArray(populations, populationsArr);
        long int megaMaxSize = pow(2,n);
        DistrictMap** arr = new DistrictMap*[megaMaxSize];
        for (int j=0; j< megaMaxSize; j++){
            arr[j] = new DistrictMap(n);
        }
        long int megaSize = fillDistrictMapArr(arr, k);
        cout << "n, k, populations, megaSize: " << n<< ", "<< k<<", "<<populations<<", "<<megaSize<<endl;

        int maxPop=0;
        DistrictMap* solution;
        for (int j=0; j< megaSize; j++){
            int current = 0;
            for (int k=0; k<n; k++)
                if(arr[j]->chosen[k])
                    current+=populationsArr[k];
            if(current>maxPop){
                solution = arr[j];
                maxPop=current;
            }
        }

        bool first = true;
        for (int j=0;j<n;j++){
            if(solution->chosen[j]){
                if(!first)
                    cout << " ";
                first = false;
                cout << j+1;
            }
        }
        cout << endl;

        delete [] populationsArr;
        for (int j=0;j<megaMaxSize; j++)
            delete arr[j];
        delete [] arr;

    }
}