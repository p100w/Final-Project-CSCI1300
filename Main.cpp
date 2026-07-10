#include <iostream>
#include <string>
#include <vector>
#include "Character.h"
#include "Villager.h"
#include "Foods.h"
using namespace std;


int main(){
    int i=0;
    while(i!=4){
        cout << "Main Menu!\n" << "Please enter a command\n";
        cout << "Option 1: (select 1)\n" << "Option 2: (select 2)\n" << "Option 3: (select 3)\n";
        cout << "Exit Game (select 4)" << endl;
        cin >> i;
        switch(i){
        case 1:
        cout << "Option 1 under construction please come back later" << endl;
        break;
        case 2:
        cout << "Option 2 under construction please come back later" << endl;
        break;
        case 3:
        cout << "Option 3 under construction please come back later" << endl;
        break;
        case 4:
        break;
        default:
        cout << "Sorry case unknown please enter in a valid selection" << endl;
        i=0;
        break;
        }
    }cout << "Exiting Game Thank you!" << endl;
}