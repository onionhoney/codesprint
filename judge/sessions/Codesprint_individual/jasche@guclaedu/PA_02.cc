#include <string>
#include <iostream>
using namespace std;

int maxBeauty(int types, int max, int beauty[], int limit[]){
    int totalBeauty = 0;
    int i = 0;
    int count = 0;
    while(i < types){
        //int j = 0;
        while(limit[i] > 0){
            totalBeauty += beauty[i];
            limit[i]--, count++;
            if(count == max)
                return totalBeauty;
        }
        i++;
    }
    return totalBeauty;
}
int main(){
    cout << "tests: ";
    int numTests;
    cin >> numTests;
    if(numTests < 1 || numTests > 100){
        cout << "number of tests must be between 1 and 100" << endl;
        return 0;
    }
    cin.ignore();
    for(int i = 0; i < numTests; i++){
        cout << "first input: ";
        string firstInput;
        string stringTypes = "";
        string stringMax = "";
        int numTypes;
        int numMax;
        bool types = true;
        getline(cin, firstInput);
        int count = 0;
        
        while(firstInput[count] != '\0'){
            if(isdigit(firstInput[count]) && types){
                stringTypes += firstInput[count];
                count++;
            }
            else if(firstInput[count] == ' ' && types){
                types = false;
                count++;
            }
            else if(isdigit(firstInput[count]) && !types){
                stringMax += firstInput[count];
                count++;
            }
            else{
                cout << "invalid input" << endl;
                return 0;
            }
            
        }
        numTypes = stoi(stringTypes);
        numMax = stoi(stringMax);
        if(numTypes < 1 || numTypes > 1000){
            cout << "number of types must be between 1 and 1000" << endl;
            return 0;
        }
        if(numMax < 1 || numMax > 50000){
            cout << "number of max flowers must be between 1 and 50000" << endl;
            return 0;
        }
        
        int numBeauty[numTypes];
        int numLimit[numTypes];
        for(int j = 0; j < numTypes; j++){
            cout << "second input: ";
            string secondInput;
            string stringBeauty = "";
            string stringLimit = "";
            types = true;
            getline(cin, secondInput);
            count = 0;
            while(secondInput[count] != 0){
                if(isdigit(secondInput[count]) && types){
                    stringBeauty += secondInput[count];
                    count++;
                }
                else if(secondInput[count] == ' ' && types){
                    types = false;
                    count++;
                }
                else if(isdigit(secondInput[count]) && !types){
                    stringLimit += secondInput[count];
                    count++;
                }
                else{
                    cout << "invalid input" << endl;
                    return 0;
                }
            }
            numBeauty[j] = stoi(stringBeauty);
            numLimit[j] = stoi(stringLimit);
            if(numLimit[j] > 1000){
                cout << "limit must be less than 1000" << endl;
                return 0;
            }
        }
        cout << maxBeauty(numTypes, numMax, numBeauty, numLimit) << endl;
    }
}
