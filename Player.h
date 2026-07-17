#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#ifndef PLAYER_H
#define PLAYER_H

using namespace std;

class Player : public Character {
private:
    int gold;
    int energy;
    int energyMax;
    int seeds;
    int crops;
    int rocks;

public:
    Player(string n, int e, int eM, int g, int s, int C, int r);
    int getGold();
    int getEnergy();
    int getEnergyMax();
    int getSeeds();
    int getCrops();
    int getRocks();
    
    void setEnergy(int e);
    void setSeeds(int s);
    void setCrops(int c);
    void setGold(int g);
    void setRocks(int r);
    void setsetEnergy(int e);
};
#endif 