#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
char buffer[105][105];
int sbuffer[105][105];
int r, c;

string ro;
void road(int pr, int pc) {
	if (pr + 1 <= r&&
		buffer[pr + 1][pc] == '#'&&
		!sbuffer[pr+1][pc]) {
		ro += 'D';
		sbuffer[pr + 1][pc] = 1;
		road(pr + 1, pc);
	}
	if (pr - 1 >= 1 && 
		buffer[pr - 1][pc] == '#'&&
		!sbuffer[pr-1][pc]) {
		ro += 'U';
		sbuffer[pr - 1][pc] = 1;
		road(pr - 1, pc);
	}
	if (pc - 1 >= 1 &&
		buffer[pr][pc - 1] == '#'&&
		!sbuffer[pr][pc-1]) {
		ro += 'L';
		sbuffer[pr][pc - 1] = 1;
		road(pr, pc - 1);
	}
	if (pc + 1 <= c&&
		buffer[pr][pc+1] == '#'&&
		!sbuffer[pr][pc+1]) {
		ro += 'R';
		sbuffer[pr][pc + 1] = 1;
		road(pr, pc + 1);
	}
}
int main() {
	int number;
	scanf("%d", &number);
	while (number--) {
		ro = "";
		memset(buffer, 0, sizeof(buffer));
		memset(sbuffer, 0, sizeof(sbuffer));
		scanf("%d %d",&r, &c) ;
		int pr, pc;
		scanf("%d %d", &pr, &pc);
		char temp[105];
		for (int a = 1; a <= r; a++) {
			scanf("%s", temp);
			for (int b = 1; b <= c; b++)
				buffer[a][b] = temp[b - 1];
		}
		road(pr, pc);
		cout << ro<<endl;
	}
	return 0;
}