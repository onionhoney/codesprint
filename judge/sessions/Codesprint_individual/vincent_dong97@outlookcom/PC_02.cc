#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;  // # of testcase;
    cin >> t;
    vector<string> results;
    for (int i = 0; i < t; i++) {
        int m, n, a, b;
        cin >> m >> n >> a >> b;
        string tmp;
        char map[m + 1][n + 1];
        for (int j = 1; j <= m; j++) {
            cin >> tmp;
            for (int k = 1; k<= n; k++)
                map[j][k] = tmp[k-1];
        }
        int x = a, y = b;   // current
        bool visited[m + 1][n + 1];
        memset(visited, false, sizeof(visited));
        string route ="";
        bool flag;
        do {
            flag = true;
            visited[x][y] = true;
            if (x > 1 && map[x - 1][y] == '#' && !visited[x - 1][y]) {
                route += 'U';
                x--;
            } else if (x < m && map[x + 1][y] == '#' && !visited[x + 1][y]) {
                route += 'D';
                x++;
            } else if (y > 1 && map[x][y - 1] == '#' && !visited[x][y - 1]) {
                route += 'L';
                y--;
            } else if (y < n && map[x][y + 1] == '#' && !visited[x][y + 1]) {
                route += 'R';
                y++;
            } else flag = false;
        } while (flag);
        
        results.push_back(route);
    }
    
    for (int i = 0; i < t; i++)
        cout << results[i] << endl;
}
