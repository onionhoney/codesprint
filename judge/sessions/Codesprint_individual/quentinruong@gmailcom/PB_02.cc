
#include <iostream>
#include <string>
using namespace std;
/*
 2
 6 4
 3
 1 0 1 4
 0 2 6 2
 4 0 4 4
 2 3
 1
 0 1 3 1
 */

int main()
{
    int t = 0;//num test cases
    cin >> t;
    cin.ignore(1000, '\n');
    
    for (int b = 0; b < t; b++){
        int m = 0;
        int n = 0;
        string first = "";
        getline(cin, first);
        m = stoi(first.substr(0, 1));//horz
        n = stoi(first.substr(2, 1));//vert
    
        int k = 0;//number of lines
        cin >> k;
        cin.ignore(1000, '\n');
        
        if (n < m){
            int a = n;
            n = m;
            m = a;
        }
            
        
        
        int* line = new int [(k + 1) * 4];
        
        for (int i = 0; i < k; i++){//a line
            
            string temp = "";
            getline(cin,  temp);
            line[i * 4 + 0] = stoi(temp.substr(0, 1));
            line[i * 4 + 1] = stoi(temp.substr(2, 1));
            line[i * 4 + 2] = stoi(temp.substr(4, 1));
            line[i * 4 + 3] = stoi(temp.substr(6, 1));
        }
    
        int** map = new int*[n];//row by column; n x m; inclusive grid
        for (int f = 0; f < n; f++){
            map[f] = new int[m];
        }
        
        for(int f = 0; f < n; f++){
            for(int d = 0; d < m; d++)
                map[f][d] = 0;
        }
        
        
        for (int h = 0; h < k; h++){
            if (line[h * 4 + 0] == line[h * 4 + 2]){
                for (int u = 0; u < line[h * 4 + 3]; u++){
                    map[line[h * 4 + 0]][u] += 1;
                }
            }
            else if (line[h * 4 + 1] == line[h * 4 + 3]){
                for (int u = 0; u < line[h * 4 + 2]; u++){
                    map[u][line[h * 4 + 1]] += 1;
                }
            }
        }
        
            
        int mid = 0;
        for(int f = 0; f < n; f++){
            for(int d = 0; d < m; d++){
                if (map[f][d] > 1)
                    mid++;
            }
        }
        /*
        for(int f = 0; f < n; f++){
            for(int d = 0; d < m; d++){
                cout << map[f][d];
            }
            cout << endl;
        }*/
        
        cout << (k + mid + 1) <<  endl;
    
}

}


