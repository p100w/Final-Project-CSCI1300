#include <iostream>
#include <string>
#include <vector>
#include "Villager.h"
using namespace std;


        Villager::Villager(string n, string L,string d, bool hS):Character(n,L){
            Dialogue=d; hasShop=hS;
        };
        string Villager::getDialogue(){return Dialogue;};
        bool Villager::getShop(){return hasShop;}
