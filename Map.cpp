#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include <fstream>
using namespace std;

mapLocation position = mapLocation::Farm;

Map::Map(mapLocation l){//im not sure i should even have a constructor for the map
    position =l;
}

string Map::getLocation(){ // finds the place where the character is hopefully
    switch(position){
        case mapLocation::Farm :
        Location="Farm";
        return Location;
        break;
        case mapLocation::West_Town :
        Location="West Town";
        return Location;
        break;
        case mapLocation::Mines :
        Location="Mines";
        return Location;
        break;
        case mapLocation::Forest :
        Location="Forest";
        return Location;
        break;
        case mapLocation::Community_Center :
        Location="Community Center";
        return Location;
        break;
        case mapLocation::Beach :
        Location="Beach";
        return Location;
        break;
        case mapLocation::East_Town :
        Location="East Town";
        return Location;
        break;
        case mapLocation::Joja_Mart :
        Location="Joja Mart";
        return Location;
        break;
    }return Location;
}

 

 void Map::getMap(){ // should helpfully print out the map ive made in the map.txt file
    ifstream inFile("map.txt");
    string line;
    if(inFile.is_open()){
        while(getline(inFile, line)){
            cout << line << endl;
        }
        inFile.close();
    }else{cerr << "Error opening map file" << endl;}//i cant imagine it throwing any errors but just in case
 }
    
