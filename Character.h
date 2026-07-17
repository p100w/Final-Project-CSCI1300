#include <iostream>
#include <string>
#include <vector>
#ifndef CHARACTER_H
#define CHARACTER_H

using namespace std;

class Character {
private:
    string name;
    string Location;

public:
    Character(string n, string L);
    string getName();
    string getLocation();
    void setLocation(string L);
    void setName(string n);
    
};
#endif 