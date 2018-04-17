#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <ctype.h>
using namespace std;

void eachTestcase ( string str);
string tolowerOnly (string original);

int main() {
    vector<string> strVector;
    string x;
    
    int testcase = 0;
    cin >> testcase;
    
    while (cin >> x)
    {
        strVector.push_back(x);
    }
    
    cout<<testcase<<endl;
    for(int i=0; i < strVector.size(); i++){
        
        string result = tolowerOnly(strVector[i]);
        eachTestcase ( result);
    }
    
}

void eachTestcase ( string str)
{
    bool appear[26] = {0};
    int total = 0;
    for(int i = 0; i < str.size(); i++) {
        
        appear[str[i]-'a'] = true;
    }
    for (int i = 0; i<26; i++)
    {
        if(appear[i]==true)
            total ++;
    }
    if(total %2 ==0)
        cout<<"INVITE TO PARTY"<<endl;
    else
        cout<<"TRASH TALK THE USER"<<endl;
    //cout<<total<<endl;
}



string tolowerOnly (string original)
{
    string temp = "";
    for(int i = 0; i < original.length(); i++)
    {
        char tempChar = original[i];
        if ((65<=tempChar && tempChar<=90) || (97<=tempChar && tempChar<=122)  )
        {
            char newchar = tolower(tempChar);
            temp= temp + newchar ;
        }
    }
    return temp;
}


