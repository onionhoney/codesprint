#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <ctype.h>
#include <unordered_set>
using namespace std;

bool shouldInvite(string s) {
  if (s.length() % 2 != 0)
    return false;
  unordered_set<char> letters;
  string newS = "";
  for (int i = 0; i < s.length(); i++) {
    newS += tolower(s[i]);
  }
  int i = 0;
  for (i = 0; i < newS.length(); i++) {
    letters.insert(newS[i]);
  }
  return (newS.length() == letters.size());
}

int main(){
  int numTest = 0;
  string s;
  vector<bool> output;
  cin >> numTest;
  for (int i = 0; i < numTest; i++) {
    cin >> s;
    output.push_back(shouldInvite(s));
    shouldInvite(s) ? cout << "INVITE TO THE PARTY" : cout << "TRASH TALK THE USER";
    cout << endl;
  }

  

}
 
