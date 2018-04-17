#include <iostream>
using namespace std;

bool checkPos(int row, int col, int corRow, int corCol)
{
    if(row > corRow && col > corCol && corCol>=0 && corRow>=0)
        return true;
    else
        return false;
}

int main(){
    int test;
    int row;
    int col;
    int mine;
    cin >> test;
    for(int t = 0; t < test; t++){
    int count = 0;
    
    cin >> row;
    cin >> col;
    cin >> mine;
    bool pos[1005][1005];
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            pos[i][j] = true;
    for(int i = 0; i < mine; i++){
        int minex;
        int miney;
        cin >> minex;
        cin >> miney;
        pos[minex-1][miney-1] = false;
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(pos[i][j] == false){
//                bool checkTop = true, checkBot = true, checkLeft = true, checkRight = true;
//                if(i == 0)
//                    checkTop = false;
//                if(i == row - 1)
//                    checkBot = false;
//                if(j == 0)
//                    checkLeft = false;
//                if(j == col - 1)
//                    checkRight = false;
//                if(checkTop)
//                    if(pos[i-1][j])
//                        count++;
//                if(checkTop && checkRight)
//                    if(pos[i-1][j+1])
//                        count++;
//                if(checkRight)
//                    if(pos[i][j+1])
//                        count++;
//                if(checkRight && checkBot)
//                    if(pos[i+1][i+1])
//                        count++;
//                if(checkBot)
//                    if(pos[i+1][j])
//                        count++;
//                if(checkBot && checkLeft)
//                    if(pos[i+1][j-1])
//                        count++;
//                if(checkLeft)
//                    if(pos[i][j-1])
//                        count++;
//                if(checkLeft && checkTop)
//                    if(pos[i-1][j-1])
//                        count++;
                if(checkPos(row,col,i-1,j-1))
                    if(pos[i-1][j-1])
                        count++;
                if(checkPos(row,col,i,j-1))
                    if(pos[i][j-1])
                        count++;
                if(checkPos(row,col,i,j+1))
                    if(pos[i][j+1])
                        count++;
                if(checkPos(row,col,i-1,j+1))
                    if(pos[i-1][j+1])
                        count++;
                if(checkPos(row,col,i-1,j))
                    if(pos[i-1][j])
                        count++;
                if(checkPos(row,col,i+1,j-1))
                    if(pos[i+1][j-1])
                        count++;
                if(checkPos(row,col,i+1,j+1))
                    if(pos[i+1][j+1])
                        count++;
                if(checkPos(row,col,i+1,j))
                    if(pos[i+1][j])
                        count++;
            }
        }
    }
    cout << count << endl;
    }
}


