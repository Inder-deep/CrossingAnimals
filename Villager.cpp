#include "Villager.h"

//Base villager constructor
Villager::Villager()
{
    name = "Pietro";
}

//Villager constructor with initialized name
Villager::Villager(string userName)
{
    name = userName;
}

//Method returns name
string Villager::getName()
{
    return name;
}

//Method that sets name of the villager
void Villager::setName(string userName)
{
    name = userName;
}

Villager::~Villager()
{

}