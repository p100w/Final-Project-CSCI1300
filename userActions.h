#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#include "Character.h"
#ifndef ACTIONS_H
#define ACTIONS_H
using namespace std;

void getUserActionArea(Map actionMap, int uI, Character& player); // not making a class because im not storing this data
void getUserActionSubArea();
   

#endif