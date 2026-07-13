#include <iostream>
#include <string>
#include <vector>
#ifndef MAP_H
#define MAP_H
using namespace std;

enum class mapLocation{ //stores each location as a different number i think???
    Farm, West_Town, Mines, Forest, Community_Center, Beach, East_Town, Joja_Mart };

class Map {
private:
    string Location;
    mapLocation PositionEnum;//hopefully it will save the enum value instead of the string
public:
    Map(mapLocation);
    string getLocation();
    mapLocation getLocationEnum();
    void getMap();
    
};


#endif