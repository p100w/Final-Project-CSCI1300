#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
using namespace std;

class Villager : public Character{
        private:
        string dialogue;
        string KeyItem;
        bool KeyItemCollected;
        bool DialogueExhausted;
        bool HasShop;

        public:
        Villager(string d, string KI, bool KIC, bool DE, bool hS, string n, int hP,int MHP, int e, int eM, int g);
        string getDialogue();
        bool hasShop();
        bool dialogueExhausted();
        string getKeyItem();


};