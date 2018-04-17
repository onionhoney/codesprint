#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string array[100];
    int unique = 0;
    string id;
    string temp;
    
    int numID = 0;
    cin >> numID;
    cin.ignore(10000,'\n');
    
    for (int c = 0; c < numID; c++)
    {
        getline(cin, id);
        array[c] = id;
    }
    for (int c = 0; c < numID; c++)
    {
        temp = array[c];
        for (int i = 0; i < temp.size(); i++)
        {
            if (isalpha(temp[i]) && (islower(temp[i])))
            {
                temp[i] = toupper(temp[i]);
            }
        }
        array[c] = temp;
    }
    for (int c = 0; c < numID; c++)
    {
        temp = array[c];
        for (int i = 'A'; i <= 'Z'; i++)
        {
            for (int n = 0; n < temp.size(); n++)
            {
                char hold = temp[n];
                if (i == hold)
                {
                    unique++;
                    break;
                }
            }
        }
        if ((unique % 2) == 0)
            array[c] = "yes";
        else
            array[c] = "no";
        unique = 0;
    }
    
    for (int c = 0; c < numID; c++)
    {
        if (array[c] == "yes")
            cout << "INVITE TO PARTY" <<endl;
        else
            cout << "TRASH TALK THE USER"<<endl;
    }
}
