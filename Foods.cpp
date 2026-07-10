#include <iostream>
#include <string>
#include <vector>
#include "Foods.h"
using namespace std;

    Food::Food(string n, int eR, bool b, string bN, string iD){
        Name=n; energyRestored=eR; buff=b, buffName=bN; itemDescription=iD;
    }
    string Food::getName(){return Name;}
    int Food::getEnergyRestored(){return energyRestored;}
    string Food::getBuffName(){return buffName;}
    string Food::getItemDescription(){return itemDescription;}
