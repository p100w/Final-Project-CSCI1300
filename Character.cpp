#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
using namespace std;


    Character::Character(string n, int hP, int MHP, int e, int eM, int g){
        gold=g; name=n; healthPoints=hP; maxHP=MHP, energy=e; energyMax=eM;
    }
    string Character::getName(){return name;}
    int Character::getGold(){return gold;}
    int Character::getHealthPoints(){return healthPoints;}
    int Character::getmaxHP(){return maxHP;}
    int Character::getEnergy(){return energy;}
    int Character::getEnergyMax(){return energyMax;}
