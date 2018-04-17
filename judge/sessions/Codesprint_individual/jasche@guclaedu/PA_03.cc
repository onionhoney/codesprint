#include <string>
#include <iostream>
using namespace std;

int maxBeauty(int types, int max, int beauty[], int limit[]){
    int totalBeauty = 0;
    int i = 0;
    int count = 0;
    while(i < types){
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
    int numTests;
    cin >> numTests;
    cin.ignore();
    for(int i = 0; i < numTests; i++){
        //cout << "first input: ";
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
                return 0;
            }
            
        }
        numTypes = stoi(stringTypes);
        numMax = stoi(stringMax);

        int numBeauty[numTypes];
        int numLimit[numTypes];
        for(int j = 0; j < numTypes; j++){
            //cout << "second input: ";
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
                    return 0;
                }
            }
            numBeauty[j] = stoi(stringBeauty);
            numLimit[j] = stoi(stringLimit);
        }
        cout << maxBeauty(numTypes, numMax, numBeauty, numLimit) << endl;
    }
}
