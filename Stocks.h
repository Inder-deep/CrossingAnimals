#pragma once
#include "Capitalists.h"
#include "Player.h"
#include "Header.h"
class Stocks :
    public Capitalists
{
protected:
    int price;

    public:
    Stocks(string inName);
    ~Stocks();

    void buyStock(Player& Buyer);
    void sellStock(Player& Seller);
    int getNewPrice();
    int showPrice();
};

