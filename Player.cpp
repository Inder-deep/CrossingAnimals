#pragma once
#include "Player.h"

//Constructor with initialized name
Player::Player(string inName) {

    name = inName;
    money = 0;


    fishingChart = 0;
    stonkTracker = 0;
    upFishRod = 0;
    goldTicket = 0;

    goldfishNum = 0;
    bassNum = 0;
    marlinNum = 0;
    salmonNum = 0;
    coelacanthNum = 0;

    stocks = 0;
}

//Method that checks if the player has any of the item passed in as argument
bool Player::checkHave(int itemCheck)
{
    switch (itemCheck)
    {
    case FishChart:
        // Checks if the Player has the Fish Chart
        if (fishingChart > 0) {
            return true;
        }
        else {
            return false;
        }
        break;
    case StocksTracker:
      // Checks if the Player has the Stocks Tracker
        if (stonkTracker > 0) {
            return true;
        }
        else {
            return false;
        }
        break;
    case FishingRod3000:
        // Checks if the Player has the upgraded Fishing Rod
        if (upFishRod > 0) {
            return true;
        }
        else {
            return false;
        }
        break;
    case GoldenTicket:
        // Checks if the Player has the Golden Ticket
        if (goldTicket > 0) {
            return true;
        }
        else {
            return false;
        }
        break;
    case Goldfish:
        // Checks if player has any goldfish
        if (goldfishNum > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case Bass:
        // Checks if player has any bass
        if (bassNum > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case Marlin:
        // Checks if player has any marlin
        if (marlinNum > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case KingSalmon:
        // Checks if player has any king salmon
        if (salmonNum > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    case Coelacanth:
    // Checks if player has any coelacanth
        if (coelacanthNum > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        break;
    default:
        return false;
    }


    
}

void Player::getItem(int itemNum) {
    switch (itemNum)
    {
    case FishChart:
        fishingChart++;
        break;
    case StocksTracker:
        stonkTracker++;
        break;
    case FishingRod3000:
        upFishRod++;
        break;
    case GoldenTicket:
        goldTicket++;
        break;
    }
}

int Player::getFish(int fishNum) {
    switch (fishNum) {
    case Goldfish:
        return goldfishNum;
        break;
    case Bass:
        return bassNum;
        break;
    case Marlin:
        return marlinNum;
        break;
    case KingSalmon:
        return salmonNum;
        break;
    case Coelacanth:
        return coelacanthNum;
        break;
    }
}

void Player::sellFish(int fishType, int amount, int cost) {
    switch (fishType){
        case Goldfish:
            // Checks if player has any goldfish
            if (goldfishNum < amount)
            {
                cout << "You don't have that many fish!" << endl;
            }
            else
            {
                cout << "You sold " << amount << " Goldfish for " << cost << " chimes." << endl;
                goldfishNum -= amount;
            }
            break;
        case Bass:
            // Checks if player has any bass
            if (bassNum < amount)
            {
                cout << "You don't have that many fish!" << endl;
            }
            else
            {
                cout << "You sold " << amount << " Bass for " << cost << " chimes." << endl;
                bassNum -= amount;
            }
            break;
        case Marlin:
            // Checks if player has any marlin
            if (marlinNum < amount)
            {
                cout << "You don't have that many fish!" << endl;
            }
            else
            {
                cout << "You sold " << amount << " Marlin for " << cost << " chimes." << endl;
                marlinNum -= amount;
            }
            break;
        case KingSalmon:
            // Checks if player has any king salmon
            if (salmonNum < amount)
            {
                cout << "You don't have that many fish!" << endl;
            }
            else
            {
                cout << "You sold " << amount << " Salmon for " << cost << " chimes." << endl;
                salmonNum -= amount;
            }
            break;
        case Coelacanth:
            // Checks if player has any coelacanth
            if (coelacanthNum < amount)
            {
                cout << "You don't have that many fish!" << endl;
            }
            else
            {
                cout << "You sold " << amount << " Coelacanth for " << cost << " chimes." << endl;
                coelacanthNum -= amount;
            }
            break;
        default:
            cout << "Error!" << endl;
}
}

//Method that is called when the player goes fishing
void Player::fish()
{
    // Finds a new random number between 0 and 1
    float randomFish = (float) rand() / RAND_MAX;

    //Checking values when player has upgraded fishing rod
    if (this->checkHave(FishingRod3000))
    {
        if (randomFish <= 0.10)
        {
            cout << "You caught a goldfish!" << endl;

            goldfishNum++;
        }
        else if (randomFish <= 0.25)
        {
            cout << "You caught a bass!" << endl;
            bassNum++;
        }
        else if (randomFish <= 0.55)
        {
            cout << "You caught a marlin!" << endl;
            marlinNum++;
        }
        else if (randomFish <= 0.85)
        {
            cout << "You caught a king salmon!" << endl;
            salmonNum++;
        }
        else
        {
            cout << "You caught a coelcanth!" << endl;
            coelacanthNum++;
        }
    }
    //Checking values when player has base fishing rod
    else
    {
        if (randomFish <= 0.25)
        {
            cout << "You caught a goldfish!" << endl;
            goldfishNum++;
        }
        else if (randomFish <= 0.65)
        {
            cout << "You caught a bass!" << endl;
            bassNum++;
        }
        else if (randomFish <= 0.95)
        {
            cout << "You caught a marlin!" << endl;
            marlinNum++;
        }
        else
        {
            cout << "You caught a king salmon!" << endl;
            salmonNum++;
        }
    }
}

//Method that is called every sunday that resets the player's amount of stocks
void Player::resetStocks()
{
    cout << "Your cabbages went bad!!" << endl;
    stocks = 0;
}

//Method returns money
int Player::getMoney()
{
    return money;
}

//Method returns name
string Player::getName() {
    return "Player " + name;
}

void Player::loseMoney(int amount)
{
    money -= amount;
}

void Player::gainMoney(int amount)
{
    money += amount;
}

void Player::gainStocks(int amount)
{
    stocks += amount;
}

void Player::loseStocks(int amount)
{
    stocks -= amount;
}

int Player::getStocks()
{
    return stocks;

}

Player::~Player()
{

}