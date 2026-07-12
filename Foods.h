#include <iostream>
#include <string>
#include <vector>
#ifndef FOODS_H
#define FOODS_H
using namespace std;

class Food {
private:
    vector<Food> consumables;
    string Name;
    int energyRestored;
    bool buff;
    string buffName;
    string itemDescription;
    int price;

public:
    Food(string n, int eR, bool b, string bN, string iD, int p);
    string getName();
    string getBuffName();
    string getItemDescription();
    int getEnergyRestored();
    void addfood(Food c);
    int getprice();
};
#endif