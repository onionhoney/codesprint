#include <vector>
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class flower{
public:
    flower(int num_type, int num_sig);
    int x;
    int y;
};

flower::flower(int num_type, int num_sig)
{
    x = num_type;
    y = num_sig;

}




int ways_to_climb(int n)
{
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    if (n == 3)
        return 4;
    
    return ways_to_climb(n-1)+ways_to_climb(n-2)+2*ways_to_climb(n-3);
    
    
}


int testpoint(int x,int y, int row, int col, char** grid)
{
    if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y] == '*'){
        return 0;
    }
//    for (int i = 0; i < mine_set.size(); i++)
//    {
//        if (mine_set[i].x==x && mine_set[i].y==y){
//            return 0;
//        }
//    }
    return 1;
}

int testmine(flower mine_i, int row, int col, char** grid)
{
    int res = 0;
    res+=testpoint(mine_i.x-1, mine_i.y-1, row, col, grid);
    res+=testpoint(mine_i.x-1, mine_i.y+1, row, col, grid);
    res+=testpoint(mine_i.x-1, mine_i.y, row, col, grid);
    res+=testpoint(mine_i.x, mine_i.y-1, row, col, grid);
    res+=testpoint(mine_i.x, mine_i.y+1, row, col, grid);
    res+=testpoint(mine_i.x+1, mine_i.y, row, col, grid);
    res+=testpoint(mine_i.x+1, mine_i.y-1, row, col, grid);
    res+=testpoint(mine_i.x+1, mine_i.y+1, row, col, grid);
    return res;

}


int main(int argc, const char * argv[]) {
    int num_round;
    
    cin >>num_round;
    
    for (int i = 0; i < num_round; i++)
    {
        int row, col;
        cin >> row;
        cin >> col;
        int mine;
        cin >> mine;
        
        char** grid = new char*[row];
        for (int m = 0; m < row; m++)
            grid[m] = new char[col];
        
        for (int p = 0; p < row; p++)
            for (int q = 0; q < col; q++)
                grid[p][q] = ' ';
        
        vector<flower> mine_set;
        for (int m=0; m < mine; m++)
        {
            int x,y;
            cin>>x;
            cin>>y;
            flower mine_i(x-1,y-1);
            mine_set.push_back(mine_i);
            grid[x-1][y-1]='*';
        }
        
        int ret=0;
        for (int n = 0; n < mine; n++)
        {
            ret+=testmine(mine_set[n], row, col, grid);
        }
        
        cout << ret << endl;
    }
    
    
    return 0;
}