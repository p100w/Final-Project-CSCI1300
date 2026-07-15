#include <iostream>
#include <string>
#include <vector>
#include "userActions.h"
#include "Character.h"
using namespace std;

void getUserActionArea(Map actionMap, int uI, Character& player){ // not making a class because im not storing this data
int energyUsed;
int energy=player.getEnergy();
int clearedArea=0;
int TilledArea=0;
int cropsPlanted=0;
int cropsHave=0;
int cropsToWater;
int cropsWatered=0;

    switch(actionMap.getLocationEnum()){
            case (mapLocation::Farm):{
                switch(uI){
                        case 1:{
                            cout << "exiting game" << endl;
                            break;
                        }
                        case 2:{
                            cout << "Opening inventory" << endl;
                            //some function here that opens inventory of player
                        }
                        case 3:{
                            cout << "Getting map..." << endl;
                            actionMap.getMap();
                            break;
                        }
                        case 4:{
                            cout << "Entering home..." << endl;
                            //subarea directory output here

                        }
                        case 5:{
                            cout << "Opening Sale bin..." << endl;
                            //subarea directory output here

                        }
                        case 6:{
                            cout << "Clearing debris takes 4 energy per space." << endl;
                            cout << "Please input how much energy you would like to spend clearing debris :";
                            cin >> energyUsed;
                            if(energyUsed> energy){
                                cout << "Unable to use that amount of energy." << endl;
                            }else{
                                clearedArea=(energyUsed/4);
                                cout << "Cleared " << clearedArea << "Spaces." << endl;
                                player.setEnergy((energy-energyUsed));
                                //need new type for the farm to mark how many spaces cleared
                            }
                            break;
                        }
                        case 7:{
                            cout << "Tilling land will take 2 energy per space." << endl;
                            cout << "Please input how much energy you would like to spend tilling land: ";
                            cin >> energyUsed;
                            if(clearedArea<0){
                                cout << "Unable to till land that hasent been cleared" << endl;
                            }else{if(energyUsed>energy){
                                cout << "Unable to use that amount of energy>" << endl;
                            }else{
                                TilledArea=(energyUsed/2);
                                cout << "Tilled " << TilledArea << " Spaces" << endl;
                                player.setEnergy((energy-energyUsed));
                                //need new type for the farm to mark how many spaces tilled
                                }
                            }
                        break;
                        }
                        case 8:{
                            cout << "Planting crops takes 0 energy per space." << endl;
                            cout << "Please input how many crops you would like to plant:";
                            cin >> cropsPlanted;
                            if(cropsPlanted>TilledArea){
                                cout << "Unable to plant that many crops, tilled area not great enough." << endl;
                            }else if(cropsPlanted>cropsHave){//rewrite this later using inventory checks
                                cout << "You have insufficient seeds to plant this number of crops";
                            }else {cout << "Planted " << cropsPlanted << "crops" << endl;}
                            break;
                        }
                        case 9:{
                            cropsToWater=cropsPlanted-cropsWatered;
                            cout << "Watering crops take 2 energy per space." << endl;
                            cout << "Please input how much energy you would like spend watering crops?" << " You have " << cropsToWater << "crops to water" << endl;
                            cin >> energyUsed;

                            if((energyUsed/2)>cropsToWater){
                                cout << "Unable to water that many crops, not enough crops." << endl;
                            }else if(energyUsed>energy){
                                cout << "Unable to use that amount of energy" << endl;
                            }else {
                                cropsWatered=energyUsed/2;
                                cout << "Watered" << cropsWatered << "Crops" << endl;
                                player.setEnergy((energy-energyUsed));
                            }
                            break;
                        }
                        case 10:{
                            //call a function that brings the movement directory.
                        }

                }
            }
            case (mapLocation::West_Town):{
                switch(uI){
                        case 1:{
                            cout << "exiting game" << endl;
                            break;
                        }
                        case 2:{
                            cout << "Opening inventory" << endl;
                            //some function here that opens inventory of player
                        }
                        case 3:{
                            cout << "Getting map..." << endl;
                            actionMap.getMap();
                            break;
                        }
                        case 4:{

                        }
                        case 5:{

                        }
                        case 6:{

                        }
                        case 7:{

                        }
            }
        }
            case (mapLocation::Mines):{
                switch(uI){
                        case 1:{
                            cout << "exiting game" << endl;
                            break;
                        }
                        case 2:{
                            cout << "Opening inventory" << endl;
                            //some function here that opens inventory of player
                        }
                        case 3:{
                            cout << "Getting map..." << endl;
                            actionMap.getMap();
                            break;
                        }
                        case 4:{

                        }
                        case 5:{

                        }
                        case 6:{

                        }
                        case 7:{

                        }
                        
            }
            case (mapLocation::Forest):{
                switch(uI){
                        case 1:{
                            cout << "exiting game" << endl;
                            break;
                        }
                        case 2:{
                            cout << "Opening inventory" << endl;
                            //some function here that opens inventory of player
                        }
                        case 3:{
                            cout << "Getting map..." << endl;
                            actionMap.getMap();
                            break;
                        }
                        case 4:{

                        }
                        case 5:{

                        }
                        case 6:{

                        }
                        case 7:{

                        }
            }
        }
            case(mapLocation::Community_Center):{
                switch(uI){
                        case 1:{
                            cout << "exiting game" << endl;
                            break;
                        }
                        case 2:{
                            cout << "Opening inventory" << endl;
                            //some function here that opens inventory of player
                        }
                        case 3:{
                            cout << "Getting map..." << endl;
                            actionMap.getMap();
                            break;
                        }
                        case 4:{

                        }
                        case 5:{

                        }
            }
        }
            case(mapLocation::Beach):{
                switch(uI){
                        case 1:{
                            cout << "exiting game" << endl;
                            break;
                        }
                        case 2:{
                            cout << "Opening inventory" << endl;
                            //some function here that opens inventory of player
                        }
                        case 3:{
                            cout << "Getting map..." << endl;
                            actionMap.getMap();
                            break;
                        }
                        case 4:{

                        }
                        case 5:{

                        }
                        case 6:{

                        }
                        case 7:{

                        }
            }
        }
            case(mapLocation::East_Town):{
                switch(uI){
                        case 1:{
                            cout << "exiting game" << endl;
                            break;
                        }
                        case 2:{
                            cout << "Opening inventory" << endl;
                            //some function here that opens inventory of player
                        }
                        case 3:{
                            cout << "Getting map..." << endl;
                            actionMap.getMap();
                            break;
                        }
                        case 4:{

                        }
                        case 5:{

                        }
                        case 6:{

                        }
                        case 7:{

                        }
            }
            }
            case(mapLocation::Joja_Mart):{
                switch(uI){
                        case 1:{
                            cout << "exiting game" << endl;
                            break;
                        }
                        case 2:{
                            cout << "Opening inventory" << endl;
                            //some function here that opens inventory of player
                        }
                        case 3:{
                            cout << "Getting map..." << endl;
                            actionMap.getMap();
                            break;
                        }
                        case 4:{

                        }
                        case 5:{

                        }
                        case 6:{

                        }
            }
        }    
    }
}
}
