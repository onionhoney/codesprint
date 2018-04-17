/*
#include <iostream>

using namespace std;


struct flower {
    int beauty;
    int type;
};

int main(int argc, const char * argv[]) {
    int numtestCases = 0;
   // cout << "Enter the # of test cases\n";
    cin >> numtestCases;
    for (int i = 0; i < numtestCases; i++) {
        int numTypeFlowers, numFlowers = 0;
        cin >> numTypeFlowers >> numFlowers;
        flower array [numTypeFlowers];
        for (int z = 0; z < numTypeFlowers; z++) {
            int bea, ty;
            cin >> bea >> ty;;
            array[z].beauty=bea;
            array[z].type=ty;
        }
        int sum = 0;
        int count = 0;
        for (int i = 0; i < numTypeFlowers; i++) {
            if ((array[i].type + count) > numFlowers)
            {
                for (int k = 0; k < numFlowers - count; k++)
                    sum += array[i].beauty;
                break;
            }
            
            for (int j = array[i].type; j > 0; j--){
                sum += array[i].beauty;
                count++;
            }
        }
        cout << sum << "\n";
    }
}
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool contains (vector<char>characters, char c) {
    for (int j = 0; j < characters.size(); j++) {
        if (c == characters[j])
            return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    
    int t = 0;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        string username;
        cin >> username;
        for (int j = 0; j < username.length(); j++)
            tolower(username[j]);
        
        vector<char>characters;
        
        int unique = 0;
        
        for (int j = 0; j < username.length(); j++) {
            if (!contains(characters, username[j])) {
                unique++;
            }
        }
        
        if (unique % 2 == 0)
            cout << "INVITE TO PARTY";
        else
            cout << "TRASH TALK THE USER";
        cout << "\n";
    }

}



