#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool results[n];    // true for good
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        bool occur[26];
        for (int j = 0; j < 26; j++)
            occur[j] = false;
        int l = (int) str.length();
        bool good = true;
        for (int j = 0; j < l; j++) {
            char ch = tolower(str[j]);
            if (!occur[ch - 'a']) {
                occur[ch - 'a'] = true;
                good = !good;
            }
        }
        results[i] = good;
    }
    
    for (int i = 0; i < n; i++)
        if (results[i])
            cout << "INVITE TO PARTY\n";
        else
            cout << "TRASH TALK THE USER\n";
}
