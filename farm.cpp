#include <iostream>
#include <string>
#include <vector>
#include "farm.h"
using namespace std;


    Farm::Farm(string fN, int cP, int cW, int cG){
        farmname=fN; cropsPlanted=cP; cropsWatered=cW; cropsGrown=cG;
    }
    int Farm::getCropsPlanted(){
        return cropsPlanted;
    }
    int Farm::getCropsWatered(){
        return cropsWatered;
    }
    int Farm::getCropsGrown(){
        return cropsGrown;
    }
    string Farm::getFarmName(){
        return farmname;
    }

    void Farm::setFarmName(string fN){
        farmname=fN;
    }

    void Farm::setCropsPlanted(int cP){
        cropsPlanted+=cP;
    }
    void Farm::setCropsWatered(int cW){
        cropsWatered+=cW;

    }
    void Farm::setCropsGrown(int cW){
        cropsGrown+=(cW);
    }
