#include <iostream>
#include <string>
#include <vector>
#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

class Character {
private:
    string name;
    int healthPoints;
    int gold;
    int maxHP;
    int energy;
    int energyMax;

public:
    Character(string n, int hP, int MHP, int e, int eM, int g);
    string getName();
    void setName(string n);
    int getGold();
    int getHealthPoints();
    int getmaxHP();
    int getEnergy();
    void setEnergy(int e);
    int getEnergyMax();

};
#endif 