#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

int getlist(list<int> &list_tmp,int n){
    auto it1 = next(list_tmp.begin(), n);
    return *it1;
}

void readlist(list<int> &intList){
    list<int>::const_iterator iterator;
    for (iterator = intList.begin(); iterator != intList.end(); ++iterator) {
        std::cout << *iterator << ' ';
    }

    cout << endl;
}

bool contains(list<int> &intList, int var){
    return (std::find(intList.begin(), intList.end(), var) != intList.end());
}

int min(int a, int b){
    return a>b?b:a;
}

int C_x_2(int x){
    return x*(x-1)/2;
}
int main(){

    int n_sample;
    cin >> n_sample;

    for(int sample = 0; sample < n_sample; sample++) {

        int num_pin;
        int num_team;
        int type_pin;

        cin >> num_pin;
        cin >> num_team;
        cin >> type_pin;

        list<int> player;
        list<int> pin_stren;

        for(int i = 0; i < num_team; i++){
            int tmp;
            cin >> tmp;
            player.push_back(tmp);
        }

        for(int i = 0; i < type_pin; i++){
            int tmp;
            cin >> tmp;
            pin_stren.push_back(tmp);
        }

        player.sort();
        pin_stren.sort();

        int max_level = 0;

        for(int i = 0; i < num_pin; i++){
            int max_player = getlist(player, player.size()-1);
            int max_ping = getlist(pin_stren, pin_stren.size()-1);

            if(max_player == 0 || max_ping == 0){
                break;
            }

            if(max_player >= max_ping){
                max_level += max_player;
                auto iter_play = player.end();
                (iter_play)--;
                (*iter_play)--;

                auto iter_stren = pin_stren.begin();
                while(*iter_stren == 0 && iter_stren != pin_stren.end()) iter_stren++;
                (*iter_stren)--;

            }
            else if(max_player < max_ping){
                max_level += max_ping;
                auto iter_sten = pin_stren.end();
                iter_sten--;
                (*iter_sten)--;

                auto iter_play = player.begin();
                while(*iter_play == 0 && iter_play != player.end()) iter_play++;
                (*iter_play)--;


            }
//            else if(max_player == max_ping){
//                auto iter_stren = pin_stren.begin();
//                while(*iter_stren == 0) iter_stren++;
//                int min_ping = *iter_stren;
//
//                auto iter_play = player.begin();
//                while(*iter_play == 0) iter_play++;
//                int min_play = *iter_play;
//
//
//
//            }

//            readlist(player);
//            readlist(pin_stren);

//            cout << max_level << endl;
//
            player.sort();
            pin_stren.sort();

        }

        cout << max_level << endl;

    }

}