#include <iostream>
using namespace std;

bool map[100][100];

string nextPath(int row, int col, int rows, int cols) {

    if (row + 1 < rows && map[row+1][col])
        return "D";
    if (row - 1 >= 0 && map[row-1][col])
        return "U";
    if (col + 1 < cols && map[row][col+1])
        return "R";
    if (col - 1 >= 0 && map[row][col-1])
        return "L";
    return "";
}

int main() {
    int numTestCases;
    cin >> numTestCases;
    for (int i = 0; i < numTestCases; i++) {
        // each test case
        int rows, cols, a, b, posR, posC;
        cin >> rows;
        cin >> cols;
        cin >> a; // starting row
        cin >> b; // starting col
        posR = a - 1;
        posC = b - 1;
        for (int r = 0; r < 100; r++) {
            for (int c = 0; c < 100; c++) {
                map[r][c] = false;
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                char x;
                cin >> x;
                map[r][c] = (x == '#');
            }
            cin.ignore(1, '\n');
        }
        string next = nextPath(posR, posC, rows, cols);
        string route = "";
        while (next != "") {
            route += next;
            map[posR][posC] = false;
            if (next == "D")
                posR++;
            if (next=="U")
                posR--;
            if (next == "R")
                posC++;
            if (next=="L")
                posC--;
            next = nextPath(posR, posC, rows, cols);
        }
        cout << route << endl;
    }
}
