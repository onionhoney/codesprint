#include <string>
#include <iostream>
using namespace std;

int main(){
    int numTests;
    int horiz = 0;
    int vert = 0;
    cin >> numTests;
    cin.ignore();
    for(int i = 0; i < numTests; i++){
        //cout << "first input: ";
        string firstInput;
        string stringLength = "";
        string stringWidth = "";
        int numLength;
        int numWidth;
        bool types = true;
        getline(cin, firstInput);
        int count = 0;
        
        while(firstInput[count] != '\0'){
            if(isdigit(firstInput[count]) && types){
                stringLength += firstInput[count];
                count++;
            }
            else if(firstInput[count] == ' ' && types){
                types = false;
                count++;
            }
            else if(isdigit(firstInput[count]) && !types){
                stringWidth += firstInput[count];
                count++;
            }
            else{
                return 0;
            }
            
        }
        numLength = stoi(stringLength);
        numWidth = stoi(stringWidth);
        
        int lines;
        cin >> lines;
        cin.ignore();
        
        for(int j = 0; j < lines; j++){
            //cout << "second input: ";
            string secondInput;
            string x1 = "";
            string x2 = "";
            string y1 = "";
            string y2 = "";
            horiz = 0, vert = 0;
            bool set1 = true;
            bool set2 = true;
            bool set3 = true;
            getline(cin, secondInput);
            count = 0;
            while(secondInput[count] != '\0'){
                if(isdigit(secondInput[count]) && set1){
                    x1 += secondInput[count];
                    count++;
                }
                else if(secondInput[count] == ' ' && set1){
                    set1 = false;
                    count++;
                }
                else if(isdigit(secondInput[count]) && !set1 && set3){
                    y1 += secondInput[count];
                    count++;
                }
                else if(secondInput[count] == ' ' && !set1 && set3){
                    set3 = false;
                    count++;
                }
                else if(isdigit(secondInput[count]) && !set1 && set2){
                    x2 += secondInput[count];
                    count++;
                }
                else if(secondInput[count] == ' ' && !set1 && set2){
                    set2 = false;
                    count++;
                }
                else{
                    y2 += secondInput[count];
                    count++;
                }
            }
            if(stoi(x1) == stoi(x2))
                vert++;
            else
                horiz++;
        }
        cout << (horiz + 1) * (vert + 1);
    }
}
