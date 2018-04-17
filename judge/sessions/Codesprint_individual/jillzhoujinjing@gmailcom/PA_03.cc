//
//  main.cpp
//  Problem A
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
    int *totalBeauty = new int[noTest];
    
    for(int i = 0; i<noTest;i++)
    {
        totalBeauty[i] = 0;
        string line;
        getline(cin,line);
        int typeFlower= 0;
        int maxTotal = 0;
        sortLine(line, typeFlower, maxTotal);
        for(int j=0; j < typeFlower; j++){
            string flowerLine;
            getline(cin,flowerLine);
            int beauty = 0;
            int maxFlower = 0;
            sortLine(flowerLine, beauty, maxFlower);
            if (maxTotal >= maxFlower)
            {
                totalBeauty[i] += beauty*maxFlower;
                maxTotal -= maxFlower;
            }
            else
            {
                totalBeauty[i] += beauty * maxTotal;
                maxTotal = 0;
            }
        }
    }
    for( int i = 0; i <noTest; i++)
        cout << totalBeauty[i] << endl;
    
    delete [] totalBeauty;
}














