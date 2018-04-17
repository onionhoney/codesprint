//
//  main.cpp
//  Problem B
//
//  Created by Jill Zhou on 1/28/17.
//  Copyright © 2017 Jzhou. All rights reserved.
//

#include <iostream>
using namespace std;

void sortLine(string line, int& first, int& second)
{
    string tempOne, tempTwo;
    int sep = 0;
    for(int i = 0; i<line.size(); i++)
    {
        tempOne += line[i];
        sep++;
        if(line[i+1] == ' ')
            break;
    }
    for(int i = sep+1; i<line.size(); i++)
        tempTwo += line[i];
    switch (tempOne.size())
    {
        case 1:
            first = tempOne[0] - '0';
            break;
        case 2:
            first = (tempOne[0]-'0')*10 + tempOne[1] - '0';
            break;
        case 3:
            first = (tempOne[0]-'0')*100+(tempOne[1]-'0')*10 + tempOne[2] - '0';
            break;
        case 4:
            first = (tempOne[0]-'0')*1000+(tempOne[1]-'0')*100+(tempOne[2]-'0')*10 + tempOne[3] - '0';
            break;
        case 5:
            first = (tempOne[0]-'0')*10000+(tempOne[1]-'0')*1000+(tempOne[2]-'0')*100 + (tempOne[3] - '0')*10 + tempOne[4] - '0';
        default:
            break;
    }
    switch (tempTwo.size()) {
        case 1:
            second = tempTwo[0] - '0';
            break;
        case 2:
            second = (tempTwo[0]-'0')*10 + tempTwo[1] - '0';
            break;
        case 3:
            second = (tempTwo[0]-'0')*100+(tempTwo[1]-'0')*10 + tempTwo[2] - '0';
            break;
        case 4:
            second = (tempTwo[0]-'0')*1000+(tempTwo[1]-'0')*100+(tempTwo[2]-'0')*10 + tempTwo[3] - '0';
            break;
        case 5:
            second = (tempTwo[0]-'0')*10000+(tempTwo[1]-'0')*1000+(tempTwo[2]-'0')*100 + (tempTwo[3] - '0')*10 + tempTwo[4] - '0';
        default:
        break;    }
}


int main()
{
    int noTest = 0;
    cin >> noTest;
    cin.ignore(100,'\n');
    int *totalAreas = new int[noTest];
    
    for(int i = 0; i<noTest;i++)
    {
        string uselessline;
        getline(cin,uselessline);
        
        int noLines = 0;
        cin >> noLines;
        cin.ignore(1000,'\n');
        int horizontal = 0;
        int vertical = 0;
        for(int j=0; j<noLines ; j++){
            string line;
            getline(cin, line);
            if(line[0] == line[4])
                horizontal++;
            if(line[2] == line[6])
                vertical++;
        }
        totalAreas[i] = (horizontal+1) * (vertical+1);
    }
    
    for( int i = 0; i <noTest; i++){
        cout << totalAreas[i] << endl;
    }
    delete[] totalAreas;
}












