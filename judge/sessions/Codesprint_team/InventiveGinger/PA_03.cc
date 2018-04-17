#include <iostream>
#include <string>


using namespace std;
bool isValid(string);
int main(int argc, char const *argv[]) {
	bool doubled[26];
	int t = 0;
	cin >> t;
	for(int i = 0; i < t; i++){
		string name;
		cin >> name;
		if (isValid(name)) {
			cout << "INVITE TO PARTY" << endl;
		} else {
			cout << "TRASH TALK THE USER" << endl;
		}
	}
	return 0;
}

bool isValid(string username){
	bool doubled[26];
	for(int i = 0; i < 26; i++){
		doubled[i] = false;
	}
	int uniqueChars = 0;
	for(int i = 0; i < username.length(); i++){
		if ('A' <= username[i] && username[i] <= 'Z' ) {
			doubled[username[i] - 'A'] = true;
		} else if ('a' <= username[i] && username[i] <= 'z'){
			doubled[username[i] - 'a'] = true;
		}
	}
	for(int i = 0; i < 26; i++){
		if (doubled[i]) {
			uniqueChars++;
		}
	}
	return !(uniqueChars % 2);
}
