#include "lands.h"

Land* getRandomLand()
{
    LandTypes selection = (LandTypes)(rand() % MAX_NUM_LANDS);
    
    //May have overdid it on number of classes
    switch(selection){
        case LAKE:
            return new Lake;
        break;
        case FOREST:
            return new Forest;
        break;
        case DESERT:
            return new Desert;
        break;
        case HILL:
            return new Hill;
        break;
        case VILLAGE:
            return new Village;
        break;
        case FARM: 
            return new Farm;
        break;
        default:
            return nullptr;
        break;
    }
}

std::string Lake::getShortDescription(){ //Basic descritpion 
    return "lake";
}

std::string Lake::getLongDescription()
{
    return "You arrive at a large lake filled with hopefully fresh water.";
}

std::string Lake::visit(Player& p)
{
    std::string description = "You drink from the lake, let's hope it's sanitary.";
    p.setThirst(Player::DEFAULT_THIRST);
    return description;
}
//---------------------------------------------------------------------------------------
std::string Forest::getShortDescription() 
{
    return "forest";
}

std::string Forest::getLongDescription()
{
    return "You arrive in the woods. Watch out for horror villains.";
}

std::string Forest::visit(Player& p)
{
    std::string description = "You forage for berries/nuts but find nothing. Sucks bruh.";
    
    int chance = rand() % 100;
    
    // Chance to find berries.
    if(chance > 75)
    {
        description = "You forage for berries/nuts and found some!";
        p.setHunger(p.getHunger() + 1);
        return description;
    }
    
    // Chance to get mauled by bear.
    if(chance < 15 && chance > 10)
    {
        description = "A wild Pokemon appears to tackle you";
        p.setHealth(p.getHealth() - 1);
    }
    
    // Chance to get double double mauled.
    if(chance < 10)
    {
        description = "A hunter accidently shoots you. Hopefully it's just a graze";
        int newHealth = (int)p.getHealth() - 2;
        newHealth = newHealth < 0 ? 0 : newHealth;
        p.setHealth(newHealth);
    }
    
    return description;
}
//--------------------------------------------------------------------------------------------
std::string Desert::getShortDescription() 
{
    return "desert";
}

std::string Desert::getLongDescription()
{
    return "You arrive in the desert. It's a desert. It's dry. It sucks.";
}

std::string Desert::visit(Player& p)
{
    std::string description = "The heat of the desert makes you dehydrated.";
    if(p.getThirst() > 0)
    {
        p.setThirst(p.getThirst() - 1);
    }
    
    return description;
}
//--------------------------------------------------------------------------------------------
std::string Village::getShortDescription() 
{
    return "Village";
}

std::string Village::getLongDescription()
{
    return "You arrive in a Village with a fair amount of people and buildings.";
}

std::string Village::visit(Player& p)
{
    std::string description = "You roam around in search for some useful things, but the place offers nothing.";
    
    int chance = rand() % 100;
    
    // Chance to for doc to heal you.
    if(chance < 65 && chance > 50)
    {
        description = "A sketchy man on the street injects you with something. Your health increases.";
        p.setHealth(Player::DEFAULT_HEALTH);
        return description;
    }
    
    if(chance < 50 && chance > 30)
    {
        description = "You find a Final Fantasy inn to rest how. How lucky.";
        p.setHunger(p.getHunger() + 2);
        p.setThirst(p.getThirst() + 2);
        return description;
    }
    
    return description;
}
//-------------------------------------------------------------------------------------------
std::string Hill::getShortDescription(){
    return "hill";
}

std::string Hill::getLongDescription()
{
    return "You find a hill. YOur grandparents use to walk over it to go to school. It magically goes upwards both ways.";
}

std::string Hill::visit(Player& p)
{
    std::string description = "You ride a goat through the hill. Nice.";
    
    int chance = rand() % 100;
    
    // Chance to for doc to heal you.
    if(chance > 30)
    {
        description = "You roll down the hill. Try to keep your food in.";
        p.setHealth(p.getHealth() - 1);
        return description;
    }
    
    return description;
}
//----------------------------------------------------------------------------------------------------------------
std::string Farm::getShortDescription() // Farm's short, long, visit constructor
{
    return "farm";
}

std::string Farm::getLongDescription()
{
    return "You arrive near a farm. The land is full of plants and animals. Plentiful to replenish.";
}

std::string Farm::visit(Player& p)
{
    std::string description = "You meet the farmer and ask for supplies.";
    
    int chance = rand() % 100;
    
    // Chance to for doc to heal you.
    if(chance > 60)
    {
        description = "The farmer tells you to get lost";
        p.setHealth(p.getHealth() - 2);
        return description;
    }
    
    if(chance <= 40)
    {
        description = "The farmer is nice enough to give you some supplies.";
        p.setHunger(p.getHunger() + 1);
        p.setThirst(p.getThirst() + 1);
        return description;
    }
    
    return description;
}
