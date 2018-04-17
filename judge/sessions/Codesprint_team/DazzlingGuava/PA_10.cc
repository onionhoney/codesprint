#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <ctype.h>
#include <unordered_set>
using namespace std;

bool shouldInvite(string s) {
  string newS = "";
  for (int i = 0; i < s.length(); i++) {
    if (isalpha(s[i]))
	newS += tolower(s[i]);
  }
  unordered_set<char> letters;
  for (int i = 0; i < newS.length(); i++) {
    letters.insert(newS[i]);
  }
  return (newS.length() == letters.size() && letters.size() % 2 == 0);
}

int main(){
  int numTest = 0;
  string s;
  vector<bool> output;
  cin >> numTest;
  for (int i = 0; i < numTest; i++) {
    cin >> s;
    output.push_back(shouldInvite(s));
    shouldInvite(s) ? cout << "INVITE TO PARTY" : cout << "TRASH TALK THE USER";
    cout << endl;
  }

}
 