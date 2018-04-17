#include <vector>
#include <iostream>

using namespace std;



typedef struct{
	int l;
	int r;
	char c;
}Line;
vector<Line> makeStack(int n);

char getChar(int index, vector<Line>& stack);
int main(int argc, char const *argv[]) {
	int t = 0;
	cin >> t;
	int n = 0;
	int is[4];
	for(int i = 0; i < t; i++){
		cin >> n;
		vector<Line> v = makeStack(n);
		cin >> is[0] >> is[1] >> is[2] >> is[3];
		for(int j = 0; j < 4; j++){
			cout << getChar(is[j], v) << " ";
		}
		cout << endl;
	}
	return 0;
}

vector<Line> makeStack(int n){
	std::vector<Line> v;
	Line as;
	as.l = 0;
	as.r = 1000000;
	as.c = 'a';
	v.push_back(as);
	for(int i = 0; i < n; i++){
		Line line;
		cin >> line.l >> line.r >> line.c;
		v.push_back(line);
	}
	return v;
}

char getChar(int index, vector<Line>& stack){
	int top = stack.size() - 1;
	while(index < stack[top].l || index > stack[top].r){
		top--;
	}
	return stack[top].c;
}
