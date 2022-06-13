#pragma once
#include "Header.h"

class Villager
{
    protected:
    string name;
    int money; 

    public:
    Villager();
    Villager(string userName);

    string getName();
    void setName(string userName);

    ~Villager();

};

