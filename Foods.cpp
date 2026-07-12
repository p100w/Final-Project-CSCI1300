#include <iostream>
#include <string>
#include <vector>
#include "Foods.h"
using namespace std;



    Food::Food(string n, int eR, bool b, string bN, string iD, int p){
        Name=n; energyRestored=eR; buff=b, buffName=bN; itemDescription=iD; price=p;
    }
    string Food::getName(){return Name;}
    int Food::getEnergyRestored(){return energyRestored;}
    string Food::getBuffName(){return buffName;}
    string Food::getItemDescription(){return itemDescription;}
    int Food::getprice(){return price;}

Food sap("Sap", -2, true, "Slowness", "Its sticky... and inedible", 0);
Food coffee("Coffee", 15, true, "Speed", "Cup o' Joe", 50);
Food FishSoup("Fish Soup", 30, true, "Fishy", "The ocean is just like this, but a little bigger...", 50);
Food DwarvishDelight("Dwarvish Delight", 50, true, "Miners!", "Its like if a turkish delight was a rock", 200);
Food Slop("Slop", 25, false, "", "Corporate slop yummy...", 100);
Food Mushroom("Mushroom", 50, false, "", "Are you sure its okay to eat?", 0);    


void Food::addfood(Food c){//vector that holds all the food, ill call this when people try to buy item from stores
consumables.push_back(sap); consumables.push_back(coffee); consumables.push_back(FishSoup); consumables.push_back(DwarvishDelight);  consumables.push_back(Slop); consumables.push_back(Mushroom);
}

