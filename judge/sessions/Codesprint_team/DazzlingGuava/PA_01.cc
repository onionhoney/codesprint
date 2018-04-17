#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool shouldInvite(string s) {
  if (s.length() % 2 != 0)
    return false;
  unordered_set<char> letters;
  int i = 0;
  for (i = 0; i < s.length(); i++) {
    letters.insert(s[i]);
  }
  return (s.length() == letters.size());
}

int main(){
  int numTest = 0;
  string s;
  cin >> numTest;
  for (int i = 0; i < numTest; i++) {
    cin >> s;
    (shouldInvite(s)) ? cout << "INVITE TO THE PARTY" : cout << "TRASH TALK THE USER";
    cout << endl;
  }

}
 
