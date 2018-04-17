#include <iostream>
using namespace std;

int main() {
	int tests = 0;
	cin >> tests; //first line for number of tests
	for (int i = 0; i < tests; i++)	{
		int m = 0;
		int n = 0;
		int toothpaste = 0;
		int numberCandy = 0;

		cin >> m >> n; //second line for matrix dimensions
		char boardMatrix[m][n] = {{}}; //array matrix for board map
		cin >> toothpaste; //third line for number of toothpaste
		//int locations[toothpaste] = {}; //dictionary for toothpaste locations

		for (int l = 0; l < toothpaste; l++){
		    int x = 0;
		    int y = 0;
			cin >> x >> y; //iterate over each following line for location of toothpaste
			//locations += {x:y} //place coordinates of each mine in dictionary
			
			for (int j = 1; j < m+1; j++) {
				for (int k = 1; k < n+1; k++) {
					if ( m == x && n == y) { // if coordinates are a dictionary entry,
						boardMatrix[m][n] = 'X'; // mark as an X
					}
					else {
						if(boardMatrix[m-1][n-1] == 'X') {
							boardMatrix[m][n]++;
							numberCandy++;
						}
						if(boardMatrix[m][n-1] == 'X') {
							boardMatrix[m][n]++;
							numberCandy++;
						}
						if(boardMatrix[m+1][n-1] == 'X') {
							boardMatrix[m][n]++;
							numberCandy++;
						}
						if(boardMatrix[m-1][n] == 'X') {
							boardMatrix[m][n]++;
							numberCandy++;
						}
						if(boardMatrix[m+1][n] == 'X') {
							boardMatrix[m][n]++;
							numberCandy++;
						}
						if(boardMatrix[m-1][n+1] == 'X') {
							boardMatrix[m][n]++;
							numberCandy++;
						}
						if(boardMatrix[m][n+1] == 'X') {
							boardMatrix[m][n]++;
							numberCandy++;
						}
						if(boardMatrix[m+1][n+1] == 'X') {
							boardMatrix[m][n]++;
							numberCandy++;
						}
					}
				}
			}
		}
	cout << numberCandy;
	}
}
