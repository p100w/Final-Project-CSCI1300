#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Directory.h"
using namespace std;

void Directory::getGlobalDirectory(){
    cout << "---------------Global Directory----------------" << endl;
    cout << "1. Exit to main menu (all progress will be lost)" << endl;
    cout << "2. Check Inventory" << endl;
    cout << "3. Check Map" << endl;
}
void Directory::getAreaDirectory(Map areamap){
    
    switch(areamap.getLocationEnum()){
        case (mapLocation::Farm):{
            string line;
            ifstream inFile("FarmDirectory.txt");
            if(inFile.is_open()){
            while(getline(inFile, line)){
                cout << line << endl;
            }
            inFile.close();
            }else{cerr << "Error opening map file" << endl;}
        break;}
        case (mapLocation::West_Town):{
            string line;
            ifstream inFile("WestTownDirectory.txt");
            if(inFile.is_open()){
            while(getline(inFile, line)){
                cout << line << endl;
            }
            inFile.close();
            }else{cerr << "Error opening map file" << endl;}
        break;}
        case (mapLocation::Mines):{
            string line;
            ifstream inFile("MinesDirectory.txt");
            if(inFile.is_open()){
            while(getline(inFile, line)){
                cout << line << endl;
            }
            inFile.close();
            }else{cerr << "Error opening map file" << endl;}
        break;}
        case (mapLocation::Forest):{
            string line;
            ifstream inFile("ForestDirectory.txt");
            if(inFile.is_open()){
            while(getline(inFile, line)){
                cout << line << endl;
            }
            inFile.close();
            }else{cerr << "Error opening map file" << endl;}
        break;}
        case (mapLocation::Community_Center):{
            string line;
            ifstream inFile("CommunityCenterDirectory.txt");
            if(inFile.is_open()){
            while(getline(inFile, line)){
                cout << line << endl;
            }
            inFile.close();
            }else{cerr << "Error opening map file" << endl;}
        break;}
        case (mapLocation::Beach):{
            string line;
            ifstream inFile("BeachDirectory.txt");
            if(inFile.is_open()){
            while(getline(inFile, line)){
                cout << line << endl;
            }
            inFile.close();
            }else{cerr << "Error opening map file" << endl;}
        break;}
        case (mapLocation::East_Town):{
            string line;
            ifstream inFile("EastTownDirectory.txt");
            if(inFile.is_open()){
            while(getline(inFile, line)){
                cout << line << endl;
            }
            inFile.close();
            }else{cerr << "Error opening map file" << endl;}
        break;}
        case(mapLocation::Joja_Mart):{
            string line;
            ifstream inFile("JojaMartDirectory.txt");
            if(inFile.is_open()){
            while(getline(inFile, line)){
                cout << line << endl;
            }
            inFile.close();
            }else{cerr << "Error opening map file" << endl;}
        break;}
    }
}