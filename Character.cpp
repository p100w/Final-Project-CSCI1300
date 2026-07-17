#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
using namespace std;

    Character::Character(string n, string L){
       name=n; Location=L;
    }
    string Character::getName(){return name;}
    string Character::getLocation(){return Location;}
    void Character::setLocation(string L){
        Location = L;
    }
    void Character::setName(string n){
        name=n;
    }
 