#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#ifndef VILLAGER_H
#define VILLAGER_H
using namespace std;

class Villager : public Character{
        private:
        string Dialogue;
        bool hasShop;

        public:
        Villager(string n, string L,string d, bool hS);
        string getDialogue();
        bool getShop();

};
#endif 