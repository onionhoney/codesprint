#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class StopMap{
public:
    bool* stops;
    int floors;

    StopMap(int f){
        floors = f;
        stops = new bool[f];
    }

    ~StopMap(){
        delete [] stops;
    }
};

void loadStringToBoolArr(string rep, bool* arr, int size){
    for (int i=0; i< size; i++){
        arr[i] = (rep[i]=='1');
    }
}

void fillStopMapArr(StopMap* arr[], int count, string partial){
    int f = arr[0]->floors;
    if(f == partial.size()){
        loadStringToBoolArr(partial, arr[count]->stops, f);
        count++;
        return;
    }
    fillStopMapArr(arr, count, partial + '0');
    fillStopMapArr(arr, count, partial + '1');

}

void fillStopMapArr(StopMap* arr[]){
    fillStopMapArr(arr,0,"");
}

void loadOnArray(string targets, int targetsArr[]){
    //cout << "targets: " << targets << endl;
    string current;
    int startPos=0;
    int count=0;
    int i=0;
    for (;i<targets.size();i++){
        if(targets[i]==' ') {
            current = targets.substr(startPos, i - startPos);
            startPos = i+1;
            //cout << "current : " << current << endl;
            targetsArr[count] = stoi(current);
            count++;
        }
    }
    //cout << "start: " << startPos << endl;
    //cout << "final string: " << targets.substr(startPos, i - startPos) << endl;
    targetsArr[count] = stoi(targets.substr(startPos, i - startPos));
}

int time(int a, int b, int c, int f, int p, int* targetsArr, bool stopsAtf[]){
    int maxTime=0;
    for (int i=0; i<p; i++){
        int currTime;
        if(stopsAtf[targetsArr[i]]){ // check this
            currTime = a*targetsArr[i];
            for (int j=i-1; j>=0; j--)
                if(stopsAtf[j])
                    currTime+=b;
            if(c*(targetsArr[i]) < currTime)
                currTime = c*(targetsArr[i]);
        }else{
            currTime=c*(targetsArr[i]);
        }
        if(currTime>maxTime)
            maxTime=currTime;
    }
    return maxTime;
}

int main() {
    int nums;
    cin >>nums;
    for (int i=0; i<nums;i++){
        int a,b,c,f,p; // begin input
        cin >> a;
        cin >> b;
        cin >> c;
        cin >> f;
        cin >> p;
        cin.ignore(10,'\n');
        string targets;
        getline(cin,targets); // end input
        int* targetsArr = new int[p];// parse targets
        loadOnArray(targets,targetsArr);
        for (int j=0; j<p; j++)
            targetsArr[j]--;

        long int megaSize = pow(2,f);

        StopMap** stopMapArr = new StopMap*[megaSize];
        for (int j = 0 ; j < megaSize; j++){
            stopMapArr[j] = new StopMap(f);
        }

        fillStopMapArr(stopMapArr);

        int minTime = 1 << 30;
        for (int j=0; j<pow(2,f); j++){
            int currTime=time(a,b,c,f,p,targetsArr,stopMapArr[j]->stops);
            if(currTime<minTime)
                minTime = currTime;
        }

        cout << minTime << endl;

        for (int j = 0 ; j < megaSize; j++){
            delete stopMapArr[j];
        }
        delete [] stopMapArr;
        delete [] targetsArr;

    }
}