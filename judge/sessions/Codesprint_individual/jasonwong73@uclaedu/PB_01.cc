#include <algorithm>
#include <string>
#include <iostream>
using namespace std;



int main(){
    int cases;
    cin>>cases;

    for(int c = 0 ; c < cases ; c++){
        int m;
        int n;
        cin>>m;
        cin>>n;

        int lines;
        cin>>lines;
        
        int horiz = 0;
        int vert = 0;
        for(int i = 0 ; i < lines ; i++){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;

            if(x1 == 0 || x2 == 2){
                horiz++;
            }else{
                vert++;
            }

        }
        vert++;
        horiz++;

        cout<< (vert * horiz)<<endl;

    }

    cout<<endl;

}
