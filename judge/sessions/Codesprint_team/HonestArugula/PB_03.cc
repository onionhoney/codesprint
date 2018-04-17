
#include <iostream>
#include <algorithm>

using namespace std;

int helper1(bool maze[][1000],int r,int c,int rows,int cols) {
    int tot = 0;
    // upper left
    tot += (r > 0) && (c > 0) && maze[r-1][c-1];
    // up
    tot += (r > 0) && maze[r-1][c];
//    cout << "up" << tot << endl;
    // uppper right
    tot += (r > 0) && (c < cols-1) && maze[r-1][c+1];
    //  cout << "ur" << tot << endl;
    // right
    tot += (c < cols-1) && maze[r][c+1];
//    cout << "r" << tot << endl;
    // lower right
    tot += (r < rows - 1) && (c < cols-1) && maze[r+1][c+1];
    //  cout << "lr" << tot << endl;
    // down
    tot += (r < rows - 1) && maze[r+1][c];
    //cout << "d" << tot << endl;
    // lower left
    tot += (r  < rows - 1) && (c  > 0) && maze[r+1][c-1];
    // cout << "ll" << tot << endl;
    // left
    tot +=(c > 0) && maze[r][c-1];

    return tot;
}

void helper(int &total,bool maze[][1000],int n_rows,int n_cols){
    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_cols; j++){

            if(!maze[i][j])
                total += helper1(maze,i,j,n_rows,n_cols);
        }
    }
}

int main()
{
    int numtests;
    cin >> numtests;
    for(int i = 0; i < numtests; i++){
        int n_rows; int n_cols;
        cin >> n_rows >> n_cols;
        int n_t;
        cin >> n_t;
        bool maze[1000][1000] = {0};
        for(int j = 0; j < n_t; j++){
            int x; int y;
            cin >> x >> y;
            maze[x-1][y-1] = true;
        }
        //cout << "----" << endl;
        /*
        for(int j = 0; j < n_rows; j++){
            for(int i = 0; i < n_cols; i++)
                cout << maze[i][j];
            cout << endl;
            }*/
        //  cout << "-----" << endl;

        int total = 0;
        helper(total,maze,n_rows,n_cols);
        cout << total << endl;
    }

    return 0;
}
