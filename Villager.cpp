#include <iostream>
#include <string>
#include <vector>
#include "Villager.h"
using namespace std;


        Villager::Villager(string d, string KI, bool KIC, bool DE, bool hS, string n, int hP,int MHP, int e, int eM, int g) : Character( n, hP, MHP, e, eM, g){

        };
        string Villager::getDialogue(){return "Not done";}
        bool Villager::hasShop(){return false;}
        bool Villager::dialogueExhausted(){return false;}
        string Villager::getKeyItem(){return "Not done";}


