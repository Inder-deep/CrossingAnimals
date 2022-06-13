#include "Stocks.h"

//Base constructor for the class
Stocks::Stocks(string inName)
{
    name = inName;
    price = 0;
}

int Stocks::getNewPrice()
{
    // Randomizes a new number and returns it 
    srand(time(0));
    price = 10 * (rand() % 10 + 1);
    return price;
}

void Stocks::buyStock(Player& Buyer)
{
    //Method used for the user to buy stocks
    int purchased = 0;
    int numCabbages = 0;
    int cost = 0;

    //While loop that goes until user purchases stocks
    while (purchased == 0)
    {
        //User inputs number of cabbages
        cout << "How many cabbages would you like to purchase: " << endl;
        cin >> numCabbages;

        //Calculates cost 
        cost = numCabbages * price;

        //Checks if the user has enough money
        if (Buyer.getMoney() < (cost))
        {
           cout << "Not enough money!" << endl;
        }
        //If they have enough money, then it is purchased
        else 
        {
            Buyer.loseMoney(cost);
            //Buyer.money = Buyer.money - cost;
            // money = money + cost;
            Buyer.gainStocks(numCabbages);
            //Buyer.stocks = Buyer.stocks + numCabbages;
            cout << "You purchased " << numCabbages << " cabbages for " << cost << " chimes." << endl;
            purchased = 1;
        }
    }
}

//Method used for player to sell their stocks
void Stocks::sellStock(Player& Seller)
{

    int sold = 0;
    int numCabbages = 0;
    int cost = 0;

    //While loop that goes until the user sells any stocks
    while (sold == 0)
    {
        //User inputs number of cabbages
        cout << "You have " << Seller.getStocks() << " cabbages" << endl;
        cout << "How many cabbages would you like to sell: " << endl;
        cin >> numCabbages;
        
        //Calculates cost 
        cost = numCabbages * price;

        //Checks if user actually has that many cabbages to sell
        if (Seller.getStocks() < (numCabbages))
        {
           cout << "Not enough cabbages! " << endl;
        }
        else 
        {
            Seller.gainMoney(cost);
            // Seller.money = Seller.money + cost;
            // money = money - cost;
            Seller.loseStocks(numCabbages);
            //Seller.stocks = Seller.stocks - numCabbages;
            cout << "You sold " << numCabbages << " cabbages for " << price << " chimes each, totaling to " << cost << endl;
            sold = 1;
        }
    }
}

//Returns the price attribute
int Stocks::showPrice()
{
    return price;
}

Stocks::~Stocks()
{

}