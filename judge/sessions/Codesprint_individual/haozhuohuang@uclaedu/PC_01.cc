//
//  main.cpp
//  test
//
//  Created by Haozhuo Huang on 28/01/2017.
//  Copyright © 2017 Haozhuo Huang. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string helper(string* maze,bool has_visited[][200],int& r, int& c,int num_row,int num_col){
    int s_r  = r - 1; int s_c = c-1;
    if(s_c > 0 && maze[s_r][s_c-1]=='#'&&!has_visited[s_r][s_c-1]){
        has_visited[s_r][s_c-1] = true;
        c--;
        return "L";
    }
    else if(s_c < num_col - 1 && maze[s_r][s_c+1] == '#'&&!has_visited[s_r][s_c+1]){
        has_visited[s_r][s_c + 1] = true;
        c++;
        return "R";
    }
    else if(s_r > 0 &&maze[s_r-1][s_c] == '#' &&!has_visited[s_r -1][s_c]){
        has_visited[s_r-1][s_c] = true;
        r--;
        return "U";
    }
    else if(s_r < num_row - 1 && maze[s_r+1][s_c] == '#'&&!has_visited[s_r+1][s_c]){
        has_visited[s_r+1][s_c] = true;
        r++;
        return "D";
    }
    else{
        r = 0; c = 0;
        return "";
    }
}

int main(){
    int test_case = 0;
    cin >> test_case;
    for(int i = 0; i < test_case; i++){
        string path = "";
        int num_row;
        int num_col;
        cin >> num_row >> num_col;
        bool has_visited[200][200];
        int r; int c;
        cin >> r >> c;
        has_visited[r][c] = true;
        string *maze = new string[num_row];

        for(int j = 0; j < num_row; j++){
            cin >> maze[j];
        }

        while(r && c){
            path += helper(maze,has_visited,r,c,num_row,num_col);
        }

        cout << path << endl;
    }
}
