#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <fstream>
#include "Character.h"
#include "Villager.h"
#include "farm.h"
#include "Player.h"
using namespace std;
//initializing variables that will be used throughout the code
bool sleep=false;
bool DwarvishDelight=false;
bool Cake=false;
bool Membership=false;
bool gameOver=false;
bool JojaCheck1=false;
bool JojaCheck2=false;
bool JojaCheck3=false;
bool BundleComplete=false;
bool seedscollected=false;
string playername;
Player player(playername, 100, 100, 150,0,0,0);
string Farmname;
Farm playerfarm(Farmname, 0,0,0);
int direction=0;
//initialized villagers
Villager Pierre("Pierre", "Town", ("Pierre: Hello! Welcome in! Take a look around I'm sure you'll find something useful!"), true);
Villager Dwarf("Dwarf", "Mines", ("Dwarf: H-h-hi! p-p-please buy my wears!") ,true);
Villager Morris("Morris", "Joja_Mart", ("Morris: Hello! Welcome to Joja Mart! I'm Morris, is there anything I can assit you with?"),true);
Villager Luis("Luis", "Farm", ("Luis: Hello There! Welcome to your home!\nLuis: You took a pretty nasty fall so you might've forgotten a few things...\nLuis: I'm just here to remind you of what your goals are!\nLuis: The community center is one bundle away from completion and you only have a week left!\nLuis: I as well as the rest of the townsfolk decided to let you do the honors of completing it.\nLuis: It's never too late to sell out to Joja but I think you know better.\nLuis: Anyway I wont keep you much longer, good luck!"), false);
//map print out
 void getMap(){ // should helpfully print out the map ive made in the map.txt file
    ifstream inFile("map.txt");
    string line;
    if(inFile.is_open()){
        while(getline(inFile, line)){
            cout << line << endl;
        }
        inFile.close();
    }else{cerr << "Error opening map file" << endl;}//i cant imagine it throwing any errors but just in case
 }
//shop stuff
void getShopDwarf(bool dD){
    cout << "You have " << player.getGold() << " Gold" << endl;
    if(dD==true){
        cout << "Dwarf: I'm sorry I only had that one item..." << endl;
    }else{
        int select;
        string choice;
        cout << "---Item for Purchase---\n 1. Dwarvish Delight (100 Gold)\n 2. Leave" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cin >> select;
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input, please input a valid number" << endl;
            return;}
        if(select==1){
            cout << "Dwarf: You want to buy this...?" << endl;
            cin >> choice;
            if((choice=="Yes" || choice=="yes"|| choice=="y" || choice=="Y" )&& player.getGold()>=100){
                DwarvishDelight=true;
                player.setGold(-100);
                cout << "Dwarf: Thank you so much! My family will be so happy to hear this!" << endl;
            }else if(choice=="No"||choice=="no"||choice=="n"||choice=="N"){
                cout << "Dwarf: Oh well bye then..." << endl;
            }else if(player.getGold()<100){
                cout << "Invalid funds." << endl;
            }else{cout << "Invalid input, please enter a valid response." << endl;}
        }else if(select==2){cout << "Dwarf: Oh well bye then..." << endl;
        }else{cout<< "Invalid input, please enter a valid number." << endl;}   
    }
}
void getShopMorris(){
    cout << "You have " << player.getGold() << " Gold" << endl;
    if(Membership==true){
        string choice;
        int select;
        cout << "Morris: Would you like to see the Joja Membership town renovation form? (Yes or No)" << endl;
        cin >> choice;
        if(choice=="Yes" || choice=="yes"|| choice=="y" || choice=="Y"){
            cout << "1. Bulldoze Community Center (Costs 1000 Gold)\n2. Blow up the mines for profit (Costs 1500 Gold)\n3. Ruin the oceans with pollution (Costs 2000 Gold)\n4. Leave" << endl;
            cout << "-----------------------------------------------------------" << endl;
            cin >> select;
            if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input, please input a valid number" << endl;
            }
            switch(select){
                    case 1:{
                        if(player.getGold()>=1000 && JojaCheck1==false){
                            player.setGold(-1000);
                            cout << "Morris: Great! Our engineers will get on that within the next few months! Thank you!" << endl;
                            JojaCheck1=true;
                        }else if(JojaCheck1==true){
                            cout << "Morris: You've already made that contribution thank you!" << endl;
                        }else{cout << "Insufficient funds" << endl;}
                    }break;
                    case 2:{
                        if(player.getGold()>=1500 && JojaCheck2==false){
                            player.setGold(-1500);
                            cout << "Morris: Great! Our Demolitionists will get on that within the next few months! Thank you!" << endl;
                            JojaCheck2=true;
                        }else if(JojaCheck2==true){
                            cout << "Morris: You've already made that contribution thank you!" << endl;
                        }else{cout << "Insufficient funds" << endl;}
                    }break;
                    case 3:{
                        if(player.getGold()>=2000 && JojaCheck3==false){
                            player.setGold(-2000);
                            cout << "Morris: Great! Our scientists will get on that within the next few months! Thank you!" << endl;
                            JojaCheck3=true;
                        }else if(JojaCheck3==true){
                            cout << "Morris: You've already made that contribution thank you!" << endl;
                        }else{cout << "Insufficient funds" << endl;}
                    }break;
                    case 4:{
                        cout << "Morris: Oh well thank you for stopping by!" << endl;
                    }break;
                    default: cout << "Invalid input, please enter a valid response." << endl; break;
            }
        }else if(choice=="No"||choice=="no"||choice=="n"||choice=="N"){
            cout << "Morris: Ah well thats too bad. Come back if you change your mind." << endl;
        }else{cout << "Invalid input, please enter a valid response." << endl;}
    }else{
        string choice;
        cout << "Morris: Hello Welcome to Joja Mart! Are you interested in our Membership Card?\n It costs 500 Gold! (Yes or No)"<<endl;
        cin >> choice;
        if(choice=="Yes" || choice=="yes"|| choice=="y" || choice=="Y"){
            if(player.getGold()>=500){
                cout << "Morris: Wonderful!" << endl;
                cout << "*Morris Hands you a patented Joja Membership Card*" << endl;
                Membership=true;
                player.setGold(-500);
            }else{cout << "Invalid Funds" << endl;}
        }else if(choice=="No"||choice=="no"||choice=="n"||choice=="N"){
            cout << "Morris: Oh well thank you for stopping by anyway!" << endl;
        }else{cout <<"Invalid input, please enter a valid response." << endl;}
    }
}
void getShopPierre(){
    string choice;
    int select;
    int seednumber;
    cout << "You have " << player.getGold() << " Gold" << endl;
    cout << "Pierre: Looking to browse my wares? (Yes or No)" << endl;
    cin >> choice;
    if(choice=="Yes" || choice=="yes"|| choice=="y" || choice=="Y"){
        cout << "Pierre: What would you like to buy?" << endl;
        cout << "---General Store---" << endl;
        cout << "1. Seeds (5 Gold per)" << endl;
        cout << "2. Cake (200 Gold)" << endl;
        cout << "3. Leave" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cin >> select;
        switch(select){
            case 1: {
                cout << "Pierre: How many Seeds would you like? (5 Gold per)" << endl;
                cin >> seednumber;
                if(seednumber<=0){cout << "Invalid amount of seeds." << endl; return;}
                if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input, please input a valid number" << endl;
            return;}
            if((seednumber*5)>player.getGold()){
                    cout << "Invalid funds." << endl;
                }else if((seednumber*5)<=player.getGold()){
                    cout << "Purchased " << seednumber << " seeds" << endl;
                    player.setGold(-(seednumber*5));
                    player.setSeeds(seednumber);
                }else {cout << "Invalid input, please enter a valid response." << endl;}
            }break;
            case 2:{if(player.getGold()>=200){
                cout << "Pierre: Are you sure you want to buy this Cake? (200 Gold)" << endl;
                cin >> choice;
                if(choice=="Yes" || choice=="yes"|| choice=="y" || choice=="Y"){
                    cout << "Pierre: Excellent! Heres your Cake!" << endl;
                    cout << "*Pierre hands you the white cake with orange frosting*" << endl; 
                    Cake=true;
                    player.setGold(-200);
                }else if(choice=="No"||choice=="no"||choice=="n"||choice=="N"){
                    cout << "Pierre: That's fair, it is pricey for a Cake I do admit..." << endl;
                }else{cout << "Invalid input, please enter a valid response." << endl;}
            }else {cout << "Insufficient funds." << endl;}
        }break;
            case 3:{cout << "Pierre: Oh alrighty then..." << endl;}break;
            default:{cout << "Invalid input, please enter a valid response." << endl;}break;

        }
    }else if(choice=="No"||choice=="no"||choice=="n"||choice=="N"){
        cout << "Pierre: Oh well get out of my store then!" << endl;
    }else{cout << "Invalid input, please enter a valid response." << endl;}
}

//movement stuff
void MovementDirectory(){
    getMap();
    if(player.getLocation()=="Farm"){
    cout << "You are currently on the " << player.getLocation() << endl;
    cout << "Which direction would you like to go?\n 0. Stay, 1. Mines(-10 energy), 2. Town(-10 energy)\n"; 
    cin >> direction;
    if(cin.fail()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid Input, please input a valid number" << endl;
    return;}
    switch(direction){
        case 0:{
            cout << "You decided to stay on the " << player.getLocation() << endl;
        }break;
        case 1:{
            cout << "Heading to the Mines..." << endl;
            player.setLocation("Mines");
            player.setEnergy(-10);
        }break;
        case 2:{
            cout << "Heading to the Town..." << endl;
            player.setLocation("Town");
            player.setEnergy(-10);
        }break;
        default:{
            cout << "Invalid input, please enter a valid number." << endl;
            
        }break;
    }
    }else if(player.getLocation()=="Mines"){
        cout << "You are currently in " << player.getLocation() << endl;
        cout << "Which direction would you like to go?\n 0. Stay, 1. Farm(-10 energy), 2. Joja_Mart(-10 energy)\n"; 
    cin >> direction;
     if(cin.fail()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid Input, please input a valid number" << endl;
    return;}
    switch(direction){
        case 0:{
            cout << "You decided to stay in the " << player.getLocation() << endl;
        }break;
        case 1:{
            cout << "Heading to the Farm..." << endl;
            player.setLocation("Farm");
            player.setEnergy(-10);
        }break;
        case 2:{
            cout << "Heading to Joja_Mart..." << endl;
            player.setLocation("Joja_Mart");
            player.setEnergy(-10);
        }break;
        default:{
            cout << "Invalid input, please enter a valid number." << endl;
        }break;
    }
    }else if(player.getLocation()=="Town"){
            cout << "You are currently in the " << player.getLocation() << endl;
            cout << "Which direction would you like to go?\n 0.Stay, 1. Farm(-10 energy), 2. Joja_Mart(-10 energy)\n"; 
            cin >> direction;
             if(cin.fail()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid Input, please input a valid number" << endl;
    return;}
    switch(direction){
        case 0:{
            cout << "You decided to stay in the " << player.getLocation() << endl;
        }break;
        case 1:{
            cout << "Heading to the Farm..." << endl;
            player.setLocation("Farm");
            player.setEnergy(-10);
        }break;
        case 2:{
            cout << "Heading to Joja_Mart..." << endl;
            player.setLocation("Joja_Mart");
            player.setEnergy(-10);
        }break;
        default:{
            cout << "Invalid input, please enter a valid number." << endl;
            
        }break;
    }
    }else if(player.getLocation()=="Joja_Mart"){
            cout << "You are currently in " << player.getLocation() << endl;
            cout << "Which direction would you like to go?\n 0. Stay, 1. Mines(-10 energy), 2. Town(-10 energy)\n"; 
            cin >> direction;
             if(cin.fail()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid Input, please input a valid number" << endl;
    return;}
        switch(direction){
        case 0:{
            cout << "You decided to stay in " << player.getLocation() << endl;
        }break;
        case 1:{
            cout << "Heading to the Mines..." << endl;
            player.setLocation("Mines");
            player.setEnergy(-10);
        }break;
        case 2:{
            cout << "Heading to the Town..." << endl;
            player.setLocation("Town");
            player.setEnergy(-10);
        }break;
        default:{
            cout << "Invalid input, please enter a valid number." << endl;
        }break;
    }
}
}
//farm stuff
void FarmMenu(){
    cout << "Please Pick an action!" << endl;
    cout << "1. Move to a new location" << endl;
    cout << "2. Plant Crops (Costs 4 Energy per crop.)" << endl;
    cout << "3. Water Crops (Costs 2 Energy per crop.)" << endl;
    cout << "4. Harvest Crops (Costs 2 Energy per crop.)" << endl;
    cout << "5. Sell Crops (Gives 30 Gold per crop.)" << endl;
    cout << "6. Talk to Luis" << endl;
    cout << "7. Check inventory" << endl;
    cout << "8. Sleep (End Day)" << endl;
    cout << "-----------------------------------------------------------" << endl;
}
void FarmActions(int pA){
    switch(pA){
    case 1:
        {MovementDirectory();}
        break;
    case 2:{
        if(player.getEnergy()<player.getSeeds()*4){
            cout << "You do not have enough energy." << endl;
            break;
        }
        if(player.getSeeds()<=0){
            cout << "You do not have any seeds for this action." << endl;
        }else{
            cout << "Planting " << player.getSeeds() << " seeds." << endl;
            playerfarm.setCropsPlanted(player.getSeeds());//sets the crops planted value to how many seeds the player has
            player.setEnergy(-4*player.getSeeds());
            player.setSeeds(-playerfarm.getCropsPlanted());//removes seeds from inventory and counts them as planted
        }break;
        }
    case 3:{
        if(player.getEnergy()<playerfarm.getCropsPlanted()*2){
            cout << "You do not have enough energy." << endl;
            break;
        }
        if(playerfarm.getCropsPlanted()<=0){
            cout << "You do not have any crops to water." << endl;
        }else{
            cout << "Watering " << playerfarm.getCropsPlanted() << " crops." << endl;
            playerfarm.setCropsWatered(playerfarm.getCropsPlanted());//adds cropsplanted to cropswatered
            player.setEnergy(-2*playerfarm.getCropsWatered());//subtracts energy from the player
            playerfarm.setCropsPlanted(-(playerfarm.getCropsWatered()));//removes value of watered crops from cropsplanted
        }break;
        }
    case 4:{
            if(player.getEnergy()<playerfarm.getCropsWatered()*2){
            cout << "You do not have enough energy." << endl;
            break;
        }
            if(playerfarm.getCropsWatered()<=0){
                cout << "You do not have any crops grown." << endl;
            }else{
                cout << "Harvesting " << playerfarm.getCropsWatered() << " crops." << endl;
                playerfarm.setCropsGrown(playerfarm.getCropsWatered());
                playerfarm.setCropsWatered(-playerfarm.getCropsGrown());
                cout << "Yield: " << playerfarm.getCropsGrown() << " crops" << endl;
                player.setCrops(playerfarm.getCropsGrown());
            }
        }break;
    case 5:{ if(player.getCrops()<=0){
            cout << "You have no crops to sell." << endl;
        }else{
            cout << "Selling " << player.getCrops() << " crops. Each sells for 30 gold." << endl;
            player.setGold((player.getCrops()*30));
            cout << "Gained " << player.getCrops()*30 << " gold." << endl;
            player.setCrops(-player.getCrops());
        }
        }break;
    case 6:{
        cout << Luis.getDialogue() << endl;
        if(seedscollected==false){
        cout << "Luis: Oh! And here are some seeds to help you get back to it!" << endl;
        player.setSeeds(20);
        cout << "+20 seeds." << endl;
        seedscollected=true;}
        }break;
    case 7:{
            cout << "-----Getting Inventory-----" << endl;
            cout <<"You have " << player.getEnergy() << "/" << player.getEnergyMax() << "energy!" << endl;
            cout <<"You have " << player.getGold() << " gold!" << endl;
            cout <<"You have " << player.getSeeds() << " seeds!" << endl;
            cout <<"You have " << player.getCrops() << " crops!" << endl;
            cout <<"You have " << player.getRocks() << " rocks!" << endl;
            if(Cake==true){cout << "You have a Cake!" << endl; }else{cout <<"You have no Cake." << endl;}
            if(DwarvishDelight==true){cout << "You have a Dwarvish Delight!" << endl;}else{cout <<"You have no Dwarvish Delights." << endl;}
            if(Membership==true){cout << "You have a Membership Card!" << endl;}else{cout << "You have no Membership Card." << endl;}
            cout << "-----------------------" << endl;
    }break;
    case 8:{
        cout << "Heading to bed..." << endl;
        sleep=true;
    }break;
    default:{
            cout << "Invalid input, please enter a valid number." << endl;
        }
    }
}
//mines stuff
void MinesMenu(){
    cout << "Please Pick an action!" << endl;
    cout << "1. Move to a new location" << endl;
    cout << "2. Go mining (Costs 100 energy.)" << endl;
    cout << "3. Talk to Dwarf" << endl;
    cout << "4. Open Inventory" << endl;
    cout << "-----------------------------------------------------------" << endl;
}
void MinesActions(int pA){
    switch(pA){
        case 1:{
            MovementDirectory();
            }break;
        case 2:{
            if(player.getEnergy()<100){
            cout << "You do not have enough energy." << endl;
            break;
        }
            cout << "Mining..." << endl;
            int randomNum = rand() % 101 + 20;
            player.setRocks(randomNum);
            player.setEnergy(-100);
            cout << "You gained " << randomNum << " rocks." << endl;
            }break;
        case 3:{
            cout << Dwarf.getDialogue() << endl;
            getShopDwarf(DwarvishDelight);

            }break;
        case 4:{
                cout << "-----Getting Inventory-----" << endl;
                cout <<"You have " << player.getEnergy() << "/" << player.getEnergyMax() << "energy!" << endl;
                cout <<"You have " << player.getGold() << " gold!" << endl;
                cout <<"You have " << player.getSeeds() << " seeds!" << endl;
                cout <<"You have " << player.getCrops() << " crops!" << endl;
                cout <<"You have " << player.getRocks() << " rocks!" << endl;
                if(Cake==true){cout << "You have a Cake!" << endl; }else{cout <<"You have no Cake." << endl;}
                if(DwarvishDelight==true){cout << "You have a Dwarvish Delight!" << endl;}else{cout <<"You have no Dwarvish Delights." << endl;}
                if(Membership==true){cout << "You have a Membership Card!" << endl;}else{cout << "You have no Membership Card." << endl;}
                cout << "-----------------------" << endl;
        }break;
        default:{
            cout << "Invalid input, please enter a valid number." << endl;
            }break;
    }
}


void JojaMenu(){
    cout << "Please Pick an action!" << endl;
    cout << "1. Move to a new location" << endl;
    cout << "2. Talk to Morris" << endl;
    cout << "3. Open Inventory" << endl;
    cout << "-----------------------------------------------------------" << endl;
}
void JojaActions(int pA){
    switch(pA){
        case 1:{
                MovementDirectory();
        }break;
        case 2:{
                cout << Morris.getDialogue() << endl;
                getShopMorris();
        }break;
        case 3:{
                cout << "-----Getting Inventory-----" << endl;
                cout <<"You have " << player.getEnergy() << "/" << player.getEnergyMax() << "energy!" << endl;
                cout <<"You have " << player.getGold() << " gold!" << endl;
                cout <<"You have " << player.getSeeds() << " seeds!" << endl;
                cout <<"You have " << player.getCrops() << " crops!" << endl;
                cout <<"You have " << player.getRocks() << " rocks!" << endl;
                if(Cake==true){cout << "You have a Cake!" << endl; }else{cout <<"You have no Cake." << endl;}
                if(DwarvishDelight==true){cout << "You have a Dwarvish Delight!" << endl;}else{cout <<"You have no Dwarvish Delights." << endl;}
                if(Membership==true){cout << "You have a Membership Card!" << endl;}else{cout << "You have no Membership Card." << endl;}
                cout << "-----------------------" << endl;
        }break;
        default:{
            cout << "Invalid input, please enter a valid number." << endl;
        }break;
    }
}
void TownMenu(){
    cout << "Please Pick an action!" << endl;
    cout << "1. Move to a new location" << endl;
    cout << "2. Go into community Center" << endl;
    cout << "3. Go into Pierre's General Store" << endl;
    cout << "4. Open Inventory" << endl;
    cout << "-----------------------------------------------------------" << endl;
}

void TownActions(int pA){
    switch(pA){
        case 1:{
                MovementDirectory();
        }break;
        case 2:{
            string answer;
            cout << "---The Final Bundle awaits you---" << endl;
            cout << "    ---Materials Required---   " << endl;
            cout << "50 Crops. 150 Rocks.\n1 Dwarvish Delight. 1 Membership Card. 1 Cake." << endl;
            cout << "You currently have...\n" << player.getCrops() << "/50 Crops. " << player.getRocks() << "/150 Rocks." << endl; 
            if(DwarvishDelight==true){cout << "1 Dwarvish Delight!";}else {cout << "0 Dwarvish Delights.";};cout <<" "; if(Cake==true){cout << "1 Cake!";}else {cout << "0 Cakes.";}; cout << " "; if(Membership==true){cout << "1 Membership Card!";}else {cout << "0 Membership Cards.";};
            if(DwarvishDelight==true && Membership==true && Cake==true && player.getCrops()>=50 && player.getRocks()>=150){
                cout << "Would you like to complete the community center? (Yes or No)" << endl;
                cin >> answer;
                if(answer=="yes" || answer=="Yes" || answer=="Y" || answer=="y"){
                    //end the game with completed community center.
                    BundleComplete=true;
                    cout << "You won! (And didn't cave to the pressure of global corporations)" << endl;
                    break;
                }else{ cout << "Maybe next time..." << endl;}
            }else{cout << "You do not have the items required to complete this bundle." << endl;};
        }break;
        case 3:{
            cout << Pierre.getDialogue() << endl;
            getShopPierre();
        }break;
        case 4:{
                cout <<"You have " << player.getEnergy() << "/" << player.getEnergyMax() << "energy!" << endl;
                cout <<"You have " << player.getGold() << " gold!" << endl;
                cout <<"You have " << player.getSeeds() << " seeds!" << endl;
                cout <<"You have " << player.getCrops() << " crops!" << endl;
                cout <<"You have " << player.getRocks() << " rocks!" << endl;
                if(Cake==true){cout << "You have a Cake!" << endl; }else{cout <<"You have no Cake." << endl;}
                if(DwarvishDelight==true){cout << "You have a Dwarvish Delight!" << endl;}else{cout <<"You have no Dwarvish Delights." << endl;}
                if(Membership==true){cout << "You have a Membership Card!" << endl;}else{cout << "You have no Membership Card." << endl;}
                cout << "-----------------------" << endl;
        }break;
        default:{
            cout << "Invalid input, please enter a valid number." << endl;
        }
        break;
    }
}



int main(){
    int playerAction;
    string playGame;

    cout << "Would you like to play a game? (Yes or No)" << endl;
    cin >> playGame;
    if(cin.fail()){
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid Input, please input a valid response" << endl;
    return 0;}
    if(playGame== "No" || playGame=="N" || playGame=="no" || playGame=="n"){
        cout << "Oh well bye then..." << endl;
    }else if(playGame=="Yes"||playGame=="Y"||playGame=="yes"||playGame=="y"){
        cout << "Please enter your name: ";
        cin >> playername;
        player.setName(playername);
        cout << "Please enter your Farm Name: ";
        cin.ignore(1000, '\n');//need the ignore so the user can actually input the getline i think
        getline(cin,Farmname);
        playerfarm.setFarmName(Farmname);
        cout << "Welcome to " << playerfarm.getFarmName() << "! " << player.getName() << "! " << endl;
        cout << "----------Game Start----------" << endl;
        //game loop starts here
            for(int daycount=0; daycount<7; daycount++){
                cout << "----------Day-" << daycount+1 << "----------" << endl;
                sleep=false;
                player.setLocation("Farm");
                player.setsetEnergy(player.getEnergyMax());
                for(int actions=0; actions<20; actions++){
                    cout << "-----------------------------------------------------------" << endl;
                    cout << "It is currently day " << daycount+1 << " out of 7." << endl;
                    cout << "You are currently at " << player.getLocation() << "!" << endl;
                    cout << "-----------------------------------------------------------" << endl;
                    cout << "You have " << 20-actions << " actions left!" << endl;
                    cout << "You have " << player.getEnergy() << " energy left!" << endl;
                    cout << "-----------------------------------------------------------" << endl;

                    if(player.getLocation()=="Farm"){
                        FarmMenu();
                        cin >> playerAction;
                        if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Input, please input a valid number" << endl;
                        continue;}
                        FarmActions(playerAction);
                    }else if(player.getLocation()=="Mines"){
                        MinesMenu();
                        cin >> playerAction;
                        if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Input, please input a valid number" << endl;
                        continue;}
                        MinesActions(playerAction);
                    }else if(player.getLocation()=="Town"){
                        TownMenu();
                        cin >> playerAction;
                        if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Input, please input a valid number" << endl;
                        continue;}
                        TownActions(playerAction);
                    }else if(player.getLocation()=="Joja_Mart"){
                        JojaMenu();
                        cin >> playerAction;
                        if(cin.fail()){
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid Input, please input a valid number" << endl;
                        continue;}
                        JojaActions(playerAction);
                    }
                    if(BundleComplete==true){
                        cout << "Well done completing the Community Center!" << endl;
                        cout << "The town is saved and all the townsfolk love you!" << endl;
                        cout << "Joja moved out after the Junimos kept sabotaging them." << endl;
                        cout << "I'm proud of you Grandson." << endl;
                        cout << "Game Over." << endl;
                        gameOver=true;
                        break;
                    }
                    if(JojaCheck1==true && JojaCheck2==true && JojaCheck3==true){
                        cout << "You've done well to appease your corporate overlords..." << endl;
                        cout << "Pelican Town has been completely brutalized and turned into pure filth." << endl;
                        cout << "Congrats on selling out..." << endl;
                        gameOver=true;
                        break;
                    }if(player.getEnergy()<=0){
                        cout << "You pass out from exhaustion..." << endl;
                        cout << "Someone brought you back to your farm while you were out." << endl;
                        cout << "Energy is reduced for the day due to exhaustion" << endl;
                        player.setLocation("Farm");
                        player.setsetEnergy(player.getEnergyMax()-25);
                        break;
                }if(sleep==true){break;}
            }
            cout << "The day has ended, you have been returned home for the night." << endl;
            }if(gameOver){
             cout << "Game test over" << endl;
            }else{ cout << "The week is over..." << endl;
                    cout << "The community Center is unfinished." << endl;
                    cout << "Joja Mart left pelican town do to low profit" << endl;
                    cout << "Game Over." << endl;
            }
        }else{cout << "Invalid Response Please try again" << endl;}
    cout << "Thank you for playing!" << endl;
    cin >> playerAction;
    }
    