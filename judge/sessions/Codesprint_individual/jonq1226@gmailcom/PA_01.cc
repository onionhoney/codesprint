//
//  main.cpp
//  lahacks
//
//  Created by Jonathan Quach on 1/28/17.
//  Copyright © 2017 QuachLabs. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;



struct flower{
    int m_beauty;
    int m_wilingToMake;
};

vector<flower> myFlowers;

int max_beauty(vector<flower> myVec){

    int currBeauty = 0;
    
    int j = 0;
 
    
    

    return 50;
}


int main(int argc, const char * argv[]) {
    // insert code here...
  
    int numberOfTypesOfFlowers;
    int amtOfFlowersCanDraw;
    int test_cases;
    cin >> test_cases;
    for (int i = 0; i < test_cases;i++){
        cin>>numberOfTypesOfFlowers;
        
        
        cin>>amtOfFlowersCanDraw;
        
        
        vector<flower> myFlowers(amtOfFlowersCanDraw);
        
        
        for (int j = 0 ; j < amtOfFlowersCanDraw; j++){
            int beautyOfEachFlower;
            int numberOfSameFlowerWillingToMake;
            cin>>beautyOfEachFlower;
            
            cin>>numberOfSameFlowerWillingToMake;
            
            
            myFlowers[i].m_beauty = beautyOfEachFlower;
            myFlowers[i].m_wilingToMake = numberOfSameFlowerWillingToMake;
            break;
        }
        
        
        
        /*
        for (int i = 0;i < amtOfFlowersCanDraw;i++){
            int beautyOfEachFlower;
            cin>>beautyOfEachFlower;
            int numberOfSameFlowerWillingToMake;
            cin>>numberOfSameFlowerWillingToMake;
            
            myFlowers[i].m_beauty = beautyOfEachFlower;
            myFlowers[i].m_wilingToMake = numberOfSameFlowerWillingToMake;
        
        }*/
    }
   
    
    
    
    
    
    
    //std::cout << "Hello, World!\n";
    cout<<max_beauty(myFlowers);
    return 0;
}
