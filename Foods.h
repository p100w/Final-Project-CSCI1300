#include <iostream>
#include <string>
#include <vector>
#ifndef FOODS_H
#define FOODS_H
using namespace std;

class Food {
private:
    string Name;
    int energyRestored;
    bool buff;
    string buffName;
    string itemDescription;

public:
    Food(string n, int eR, bool b, string bN, string iD);
    string getName();
    string getBuffName();
    string getItemDescription();
    int getEnergyRestored();
};
#endif