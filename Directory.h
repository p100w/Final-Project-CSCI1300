#include <iostream>
#include <string>
#include <vector>
#include "Map.h"
#ifndef DIRECTORY_H
#define DIRECTORY_H
using namespace std;

class Directory {
private:
    string GlobalDirectory;
    string AreaDirectory;
    //string SubAreaDirectory; unsure if ill need this
    

public:
    void getGlobalDirectory();
    void getAreaDirectory(Map areamap); // takes in a Map class object named map

    //void getSubAreaDirectory();
};
#endif