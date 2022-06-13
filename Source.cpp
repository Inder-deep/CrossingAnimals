#include "Header.h"
#include "Villager.h"
#include "Capitalists.h"
#include "Stocks.h"
#include "Player.h"

string dayToString(int day);

int main()
{
    //Sets the seed for the random number generator which is used for the fish and cabbages
    srand((unsigned)time(NULL));

    //Initializes the key variables that are used in the game

    int moveOn; // Stops the game from moving into the afternoon phase until the player is ready
    string userName; //Temporarily stores the user's username
    int numActions = 0; //Counts how many actions the player has taken in a day
    int actionChoice; //Stores which action the user chooses to do
    int storeChoice; // Used for the cababge trading section
    int dayCount = 0; // Count of days
    int day = 0; // What day it is
    int type = 0; // Stores whether the user would like to buy or sell
    int yesterdayPrice = 100; // Initializes yesterday's cabbage price at the max

    // Introduces the player to the game and asks for their name
    cout << "Welcome to Crossing Animals!" << endl;
    cout << "Please enter your name: ";
    cin >> userName;

    // Creates the three objects for the player, the main store, and the cababge trader
    Player* user = new Player(userName);
    Capitalists* storeMan = new Capitalists("Nom Krook");
    Stocks* stockMan = new Stocks("Katrina");

    cout << "Welcome S" << user->getName() << endl;
    cout << "Enjoy our wonderful pier where you can fish to your heart's content" << endl;
    cout << "If you find yourself with some money burning a hole in your pocket, head on down to Krook's Pantry and buy yourself a golden ticket." << endl;
    cout << "If you'd like to partake in some cabbage trading check out the stands." << endl;
    cout << "We hope you'll enjoy your time at Krook's Island!" << endl;

    // This loop continues to run until the player buys a golden ticket
    while (user->checkHave(GoldenTicket) == false)
    {
        // Each time the loop runs it counts up the day and dayCount
        moveOn = 0;
        day++;
        dayCount++;

        //If the day goes to 8, then it resets it to 1 because that is sunday
        if (day > 7)
        {
            day = 1;
            user->resetStocks();
        }

        while (moveOn != 1)
        {
            numActions = 0;
            yesterdayPrice = stockMan->showPrice(); // Temporaily stores yesterday's cabbage price before generating a new one
            stockMan->getNewPrice(); // Generates a new cabbage price
            cout << "------- MORNING PHASE -------" << endl;
            cout << "Current day: " << dayToString(day) << endl; // day to string function converts the day number to a day string

            if (user->checkHave(FishChart)) {
                // Shows the possible fish based off of the current fishing rod
                cout << "------- Fishing Chart -------" << endl;
                if (user->checkHave(FishingRod3000)) {
                    //float fishChances[5] = { 0.10, 0.15, 0.3, 0.30, 0.15};
                    cout << "Fish available: " << endl;
                    cout << "Goldfish (10%): 10 chimes" << endl;
                    cout << "Bass (15%): 20 chimes" << endl;
                    cout << "Marlin (30%): 50 chimes" << endl;
                    cout << "King Salmon (30%): 100 chimes " << endl;
                    cout << "Coelacanth (15%): 200 Chimes" << endl;
                }
                else {
                    //float fishChances[5] = { 0.25, 0.4, 0.3, 0.05, 0};
                    cout << "Fish available: " << endl;
                    cout << "Goldfish (25%): 10 chimes" << endl;
                    cout << "Bass (40%): 20 chimes" << endl;
                    cout << "Marlin (30%): 50 chimes" << endl;
                    cout << "King Salmon (5%): 100 chimes " << endl;
                }
            }
            else {
                cout << "No Fishing Chart to check..." << endl;
            }
            if (user->checkHave(StocksTracker)) {
                //Tells the user if they can buy or sell cabbages today, and what they cost
                cout << "------- Cabbage Tracker -------" << endl;
                if (day == Sunday) {
                    cout << "You can buy cababges today." << endl;
                    cout << "They cost " << stockMan->showPrice() << " chimes each." << endl;
                }
                else {
                    cout << "You can sell cabbages today.";
                    cout << "They sell for " << stockMan->showPrice() << " chimes each." << endl;
                }
            }
            else {
                cout << "No Cabbage Tracker to check..." << endl;
            }

            cout << "Enter 1 to move on: " << endl;
            cin >> moveOn;
        }
        while (numActions < 2)
        {
            // Prompts the user one what they would like to do and calls the appropriate method
            cout << "------- AFTERNOON PHASE------" << endl;
            cout << "Please choose what to do:\n1: Go Fishing\n2: Go to the Krook's Pantry\n3: Go to the Cand's Stands\n" << endl;
            cin >> actionChoice;

            switch (actionChoice)
            {
                case 1:
                {
                    user->fish();
                    numActions++;
                    break;
                }
                case 2:
                {
                    cout << "Your current money: " << user->getMoney() << endl;
                    cout << "What would you like to do:" << endl;
                    cout << "1 - Purchase Something" << endl;
                    cout << "2 - Sell Fish" << endl;
                    cin >> type;
                    storeMan->transact(*user, type);
                    numActions++;
                    break;
                }
                case 3:
                {
                    // If its a Sunday then they can buy cabbages
                    if (day == 1)
                    {
                        cout << "Your current money: " << user->getMoney() << endl;
                        numActions++;
                        cout << "Current cabbage price: " << stockMan->showPrice() << endl;
                        cout << "1 to purchase, 2 to go back: " << endl;
                        cin >> storeChoice;
                        if (storeChoice == 1)      
                        {
                            stockMan->buyStock(*user);
                        }
                        else if (storeChoice == 2)
                        {
                            cout << stockMan->getName() << ": You came to the store and didn't want to buy anthing...?" << endl;
                            cout << stockMan->getName() << ": Whatever hatches your chickens I guess..." << endl;
                        }
                    }
                    // If its not a Sunday, then they can sell
                    else
                    {
                        numActions++;
                        cout << "Current price to sell cabbages: " << stockMan->showPrice() << endl;
                        cout << "1 to sell, 2 to go back: " << endl;
                        cin >> storeChoice;
                        if (storeChoice == 1)
                        {
                            //Sell item
                            stockMan->sellStock(*user);
                        }
                        else if (storeChoice == 2)
                        {
                            cout << stockMan->getName() << ": You came to the store and didn't want to sell anthing...?" << endl;
                            cout << stockMan->getName() << ": Whatever rolls your dough I guess..." << endl;
                        }
                    }

                }

            }

        }





        
    }
    cout << "Congratulations!" << endl;
    cout << "You have successfully escaped Krook's Island in "<< dayCount << " days" << endl;
    return 0;
}

string dayToString(int day) {
    //Switch case to match the day number with the actual day
    switch (day) {
    case Sunday:
        return "Sunday";
    case Monday:
        return "Monday";
    case Tuesday:
        return "Tuesday";
    case Wednesday:
        return "Wednesday";
    case Thursday:
        return "Thursday";
    case Friday:
        return "Friday";
    case Saturday:
        return "Saturday";
    default:
        return "Error";
    }
}