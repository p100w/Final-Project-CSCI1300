#include <iostream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;


    Player::Player(string n, int e, int eM, int g, int s, int C, int r):Character(n,"Farm"){
        energy=e, energyMax=eM, gold=g; seeds=s; crops=C;
    }
    int Player::getGold(){return gold;}
    int Player::getEnergy(){return energy;}
    int Player::getEnergyMax(){return energyMax;}
    int Player::getSeeds(){return seeds;}
    int Player::getCrops(){return crops;}
    int Player::getRocks(){return rocks;}

    void Player::setEnergy(int e){energy+=e;}
    void Player::setSeeds(int s){seeds+=s;}
    void Player::setCrops(int C){crops+=C;}
    void Player::setGold(int g){gold+=g;}
    void Player::setRocks(int r){rocks+=r;}
    void Player::setsetEnergy(int e){energy=e;}