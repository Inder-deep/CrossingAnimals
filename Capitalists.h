#pragma once
#include "Header.h"
#include "Villager.h"
#include "Player.h"


class Capitalists:
    public Villager
{
    // Attributes
protected:



    // Methods
    public:
    Capitalists();
    Capitalists(string inName);

    ~Capitalists();

    void transact(Player& buyer, int type);
        
};

