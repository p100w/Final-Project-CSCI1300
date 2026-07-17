#include <iostream>
#include <string>
#include <vector>
#ifndef FARM_H
#define FARM_H

using namespace std;

class Farm {
private:
    string farmname;
    int cropsPlanted;
    int cropsWatered;
    int cropsGrown;
public:
    Farm(string fN, int cP, int cW, int cG);
    int getCropsPlanted();
    int getCropsWatered();
    int getCropsGrown();
    string getFarmName();

    void setFarmName(string fN);
    void setCropsPlanted(int cP);
    void setCropsWatered(int cW);
    void setCropsGrown(int cW);

};
#endif 