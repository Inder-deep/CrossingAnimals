#include "Capitalists.h"

//Base constructor
Capitalists::Capitalists() {
    name = "Nom Took";
    money = 1000;
}

//Constructor with initialized name
Capitalists::Capitalists(string inName)
{
    name = inName;
    money = 1000;

}


Capitalists::~Capitalists()
{

}



void Capitalists::transact(Player& buyer, int type)
{
    int inNum = 0;
    int cost = 0;
    int active = 0;

    int item = 0;

    switch (type) {
    case 1:
        while (active == 0) {
                cout << name << ": What would you like to purchase?" << endl;
                cout << "1 - Fishing Chart (20 chimes each)" << endl;
                cout << "2 - Stocks Tracker (100 chimes each)" << endl;
                cout << "3 - Fishing Rod 3000 (300 chimes each)" << endl;
                cout << "4 - Golden Ticket (1000 chimes each)" << endl;
                cout << "5 - Exit" << endl;
                cin >> item;
                item = item + 10; //To match the offset from the DEFINES in the header
                switch (item) {
                case FishChart:
                    // The user can buy a fishing chart which tells them what fish will appear depending on which fishing rod they have
                    // It also tells the player how much each fish is worth
                    // It costs 20 chimes
                    cost = 20;
                    // If the player can't afford the fishing rod, it will tell them
                    if (buyer.getMoney() < (cost)) {
                        cout << name << ": Not enough money!" << endl;
                    }
                    else {
                        // If the player already owns a fishing chart then they can't buy another one
                        if (buyer.checkHave(item)) {
                            cout << name << ": You already have a fishing chart!";
                            break;
                        }
                        else {
                            // Subtracts the cost from the player, and adds the item to their inventory
                            buyer.loseMoney(cost);
                            buyer.getItem(FishChart);
                            cout << "You purchased a Fishing Chart for " << cost << " chimes." << endl;
                            active = 1;
                        }
                    }
                    break;
                case StocksTracker:
                    // Allows the user to buy a stocks tracker, which wil tell them if today's stock price is higher/lower than yesterday's
                    // Costs 100 chimes
                    cost = 100;
                    if (buyer.getMoney() < (cost)) {
                        cout << name << ": Not enough money!" << endl;
                    }
                    else {
                        // If the player already has a cabbage tracker, they can't buy another
                        if (buyer.checkHave(item)) {
                            cout << name << ": You already have a cabbage tracker!";
                            break;
                        }
                        else {
                            // Subtracts the cost from the player, and adds the item to their inventory
                            buyer.loseMoney(cost);
                            buyer.getItem(StocksTracker);
                            cout << "You purchased a Stocks Tracker for " << cost << " chimes." << endl;
                            active = 1;
                        }
                    }
                    break;
                case FishingRod3000:
                    // Allows the user to buy an upgraded fishing rod, which makes them more likely to catch better fish
                    // Costs 300 chimes
                    cost = 300;
                    if (buyer.getMoney() < (cost)) {
                        cout << name << ": Not enough money!" << endl;
                    }
                    else {
                        // If the player already has an upgraded fishign rod, they can't buy another
                        if (buyer.checkHave(item)){
                            cout << name << ": You already have an upgraded fishing rod!";
                            break;
                        }
                        else {
                            // Subtracts the cost from the player, and adds the item to their inventory
                            buyer.loseMoney(cost);
                            buyer.getItem(FishingRod3000);
                            cout << "You purchased a Fishing Rod 3000 for " << cost << " chimes." << endl;
                            active = 1;
                        }
                    }
                    break;
                case GoldenTicket:
                    // Allows the user to buy the ~~Golden Ticket~~ which wins them a trip to Iceland
                    // Costs 1000 chimes
                    cost = 1000;
                    if (buyer.getMoney() < (cost)) {
                        cout << name << ": Not enough money!" << endl;
                    }
                    else {
                        // The player should theoretically never get here, but in case they do this case accounts for it
                        if (buyer.checkHave(item)) {
                            cout << name << ": How did you even manage to get here?!";
                            break;
                        }
                        else {
                            // Subtracts the cost from the player, and adds the item to their inventory
                            buyer.loseMoney(cost);
                            buyer.getItem(GoldenTicket);
                            cout << name << ": You purchased a Golden Ticket for " << cost << " chimes." << endl;
                            cout << name << ": You can finally go to Iceland!" << endl;
                            cout << name << ": Go to the airport tomorrow morning to go on your trip!" << endl;
                            active = 1;
                        }
                    }
                    break;
                default:
                    // If the player comes into the store and leaves without buying anything this text will print out
                    cout << name << ": You came to the store and didn't want to buy anthing...?" << endl;
                    cout << name << ": Whatever hatches your chickens I guess..." << endl;
                    active = 1;
                    break;
                }
            }
    case 2:
        while (active == 0) {
            cout << name << ": What would you like to sell?" << endl;
            // Checks to see which fish the player currently has, then displays how many and the price
            if (buyer.checkHave(Goldfish)) {
                cout << "1. Goldfish (" << buyer.getFish(Goldfish) << ") - 10 Chimes Each" << endl;
            }
            if (buyer.checkHave(Bass)) {
                cout << "2. Bass (" << buyer.getFish(Bass) << ") - 20 Chimes Each" << endl;
            }
            if (buyer.checkHave(Marlin)) {
                cout << "3. Marlin (" << buyer.getFish(Marlin) << ") - 50 Chimes Each" << endl;
            }
            if (buyer.checkHave(KingSalmon)) {
                cout << "4. KingSalmon (" << buyer.getFish(KingSalmon) << ") - 100 Chimes Each" << endl;
            }
            if (buyer.checkHave(Coelacanth)) {
                cout << "5. Coelacanth (" << buyer.getFish(Coelacanth) << ") - 200 Chimes Each" << endl;
            }
            cin >> item;
            item = item + 14; //To match the offset from the DEFINES in the header
            switch (item) {
                // Each of these cases are identical except for the cost of each fish
            case Goldfish:
                // Prompts the user on how many fish they'd like to sell
                // Then adds money equal to the number of fish times the cost
                cout << name << ": How many would you like to sell?" << endl;
                cout << "You have: " << buyer.getFish(item) << endl;
                cin >> inNum;
                cost = 10 * inNum;
                buyer.gainMoney(cost);
                buyer.sellFish(item, inNum, cost);

                active = 1;
                break;
            case Bass:
                cout << name << ": How many would you like to sell?" << endl;
                cout << "You have: " << buyer.getFish(item) << endl;
                cin >> inNum;
                cost = 20 * inNum;
                buyer.gainMoney(cost);
                buyer.sellFish(item, inNum, cost);
                active = 1;
                break;
            case Marlin:
                cout << name << ": How many would you like to sell?" << endl;
                cout << "You have: " << buyer.getFish(item) << endl;
                cin >> inNum;
                cost = 50 * inNum;
                buyer.gainMoney(cost);
                buyer.sellFish(item, inNum, cost);
                active = 1;
                break;
            case KingSalmon:
                cout << name << ": How many would you like to sell?" << endl;
                cout << "You have: " << buyer.getFish(item) << endl;
                cin >> inNum;
                cost = 100 * inNum;
                buyer.gainMoney(cost);
                buyer.sellFish(item, inNum, cost);
                active = 1;
                break;
            case Coelacanth:
                cout << name << ": How many would you like to sell?" << endl;
                cout << "You have: " << buyer.getFish(item) << endl;
                cin >> inNum;
                cost = 200 * inNum;
                buyer.gainMoney(cost);
                buyer.sellFish(item, inNum, cost);
                active = 1;
                break;
            default:
                cout << name << ": You came to the store and didn't want to sell anthing...?" << endl;
                cout << name << ": Whatever floats your boats I guess..." << endl;
                active = 1;
                break;
            }
            
        }
    }
}
