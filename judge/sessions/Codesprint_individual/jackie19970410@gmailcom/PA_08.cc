//
//  main.cpp
//  Codesprint
//
//  Created by JackieYJC on 1/28/17.
//  Copyright © 2017 Jiachen Yang. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;


class Flower
{
public:
    Flower()
    {
        beautylvl = 0;
        number = 0;
    }
    void setbeauty(int bt)
    {
        beautylvl = bt;
    }
    void setnumber(int nb)
    {
        number = nb;
    }
    int getbeauty(){
        return beautylvl;
    }
    int getnumber(){
        return number;
    }
private:
    int beautylvl;
    int number;
    
};

int main() {
    int nbtestcase = 0;
    int nbflower = 0;
    int battery = 0;
    
    string answer = "";
    //cout << "0\n";
    cin >> nbtestcase;
    //cout << "1\n";
    for (int i = 0; i < nbtestcase; i++) {
        Flower* bouquet;
        int input = 0;
        //cout << "2\n";
        cin >> input;
        nbflower = int(input);
        cin >> input;
        battery = int(input);
        bouquet = new Flower[nbflower];
        for (int j = 0; j < nbflower; j++) {
            cin >> input;
            //cout << "2\n";
            bouquet[j].setbeauty(input);
            cin >> input;
            bouquet[j].setnumber(input);
        }
//        for (int j = 0; j < nbflower; j++) {
//            cout << "\n";
//            cout << bouquet[j].getbeauty();
//            cout << " ";
//            cout << bouquet[j].getnumber();
//            cout << "\n";
//        }
        int batterycount = battery;
        int j = 0;
        int beautycount = 0;
        while (batterycount !=0 && j < nbflower ) {
            batterycount -= bouquet[j].getnumber();
            //cout << bouquet[j].getnumber();
            if (batterycount < 0) {
                beautycount += (bouquet[j].getnumber() - (0 - batterycount))*bouquet[j].getbeauty();
                batterycount = 0;
            }
            else{
                beautycount += bouquet[j].getnumber()*bouquet[j].getbeauty();
            }
            j++;
        }
        // cout << beautycount;
        answer = answer + to_string(beautycount);
        answer += "\n";
    }
    // read in and store
    cout << answer;
    
    //return 0;
}

