
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string follow(char map[][101], int ir, int ic, int nrows, int ncols)
{
    string path;
    bool visited[101][101] = {0};
    visited[ir][ic] = true;
    while (true) {
        // cout << ir << ' ' << ic << ' ' << map[ir][ic] << endl;
        if (ir > 1 && !visited[ir-1][ic] && map[ir-1][ic] == '#') {
            // U
            path += 'U';
            ir--;
        } else if (ir < nrows && !visited[ir+1][ic] && map[ir+1][ic] == '#') {
            // D
            path += 'D';
            ir++;
        } else if (ic > 1 && !visited[ir][ic-1] && map[ir][ic-1] == '#') {
            // L
            path += 'L';
            ic--;
        } else if (ic < ncols && !visited[ir][ic+1] && map[ir][ic+1] == '#') {
            // R
            path += 'R';
            ic++;
        } else {
            break;
        }
        visited[ir][ic] = true;
    }

    return path;
}

int main()
{
    int numtests;
    cin >> numtests;

    for (int i = 0; i < numtests; i++) {
        int m, n, a, b;
        cin >> m >> n >> a >> b;

        char map[101][101];
        for (int r = 1; r <= m; r++) {
            for (int c = 1; c <= n; c++) {
                char s;
                cin >> s;
                while (isspace(s))
                    cin >> s;

                map[r][c] = s;
            }
        }
        // for (int r = 1; r <= m; r++) {
        //     for (int c = 1; c <= n; c++) {
        //         cout << map[r][c];
        //     }
        //     cout << endl;
        // }
        cout << follow(map, a, b, m, n) << endl;
    }

    return 0;
}
