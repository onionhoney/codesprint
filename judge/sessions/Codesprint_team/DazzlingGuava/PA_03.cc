#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
#include <unordered_set>
using namespace std;

bool shouldInvite(string s) {
  if (s.length() % 2 != 0)
    return false;
  unordered_set<char> letters;
  int i = 0;
  for (i = 0; i < s.length(); i++) {
    letters.insert(tolower(s[i]));
  }
  return (s.length() == letters.size());
}

int main(){
  int numTest = 0;
  string s;
  vector<bool> output;
  cin >> numTest;
  for (int i = 0; i < numTest; i++) {
    cin >> s;
    output.push_back(shouldInvite(s));
  }

  for (int i = 0; i < output.size(); i++) {
    (output[i]) ? cout << "INVITE TO THE PARTY" : cout << "TRASH TALK THE USER";
    cout << endl;
  }

}
 
