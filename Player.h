#pragma once
#include "Header.h"
#include "Villager.h"
class Player :
    public Villager
{


    //                         T1    T2    T3   T4  T5
    //float fishChances[5] = { 0.25, 0.4, 0.3, 0.05, 0};
    //float fishChances[5] = { 0.10, 0.15, 0.3, 0.30, 0.15};
protected:
    int money;
    
    int fishingChart; // Fishing Chart, lets you know what fish are available
    int stonkTracker; // Stonk Tracker, tells you whether tomorrow's stock price will be higher or lower than today's
    int upFishRod; // Upgraded Fishing Rod, increases probabliity of getting better fish
    int goldTicket; // Golden Ticket, neccesary to win a trip to Iceland and beat the game

    // Keeps track of how many of each fish the player has
    int goldfishNum;
    int bassNum;
    int marlinNum;
    int salmonNum;
    int coelacanthNum;

    // Keeps track of how many cabbages the player has
    int stocks;
    public:
    Player();
    Player(string inName);

    void loseMoney(int amount);
    void gainMoney(int amount);

    bool checkHave(int itemCheck);

    void getItem(int itemNum);

    int getFish(int fishNum);
    void sellFish(int fishType, int amount, int cost);
    
    void fish();
    
    void gainStocks(int amount);
    void loseStocks(int amount);
    void resetStocks();
    int getStocks();

    string getName();
    int getMoney();
    
    ~Player();
};

