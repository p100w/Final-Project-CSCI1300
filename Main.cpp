#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Villager.h"
#include "Foods.h"
#include "Map.h"
#include "Directory.h"
using namespace std;


int main(){
    Map map(mapLocation::Farm);
    Directory directory;
    int i=0;
    while(i!=4 && i!=1){
        cout << "Main Menu!\n" << "Please enter a command\n";
        cout << "Option 1: Start Game\n" << "Option 2: (select 2)\n" << "Option 3: (select 3)\n";
        cout << "Exit Game (select 4)" << endl;
        cin >> i;
        switch(i){
        case 1:
            {cout << "Starting Game..." << endl;
            cout <<"Starting at farm..." << endl;
            cout << "Printing map..." << endl;
            
            map.getMap();
            cout << endl;
            cout << endl;
            cout << "You are currently at *" << map.getLocation() << "*" << endl;
            cout << endl;
            break;}
        case 2:
            cout << "Option 2 under construction please come back later" << endl;
            break;
        case 3:
            cout << "Option 3 under construction please come back later" << endl;
            break;
        case 4:
            cout << "Exiting Game Thank you!" << endl;
            break;
        default:
        cout << "Sorry case unknown please enter in a valid selection" << endl;
        i=0;
        break;
        }
    } if(i==1){
        cout << "Please input desired action for *" << map.getLocation() << "*" << endl;
        cout << endl;
        directory.getGlobalDirectory();
        directory.getAreaDirectory(map);
        //cin >> input;
    }
}