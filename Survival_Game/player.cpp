#include "player.h"

Player::Player(int health, int hunger, int thirst, /*int score*/
             int x, int y)
    {
        this->health = health;
        this->hunger = hunger;
        this->thirst = thirst;
        //this->score = score;
        this->x = x;
        this->y = y;
    }
    
     int Player::getX() const { return x; }
    
     int Player::getY() const { return y; }
    
    void Player::setX(int newX) { x = newX; }
    
    void Player::setY(int newY) { y = newY; }
    
     int Player::getHealth() const { return health; }
    
     int Player::getHunger() const { return hunger; }
    
     int Player::getThirst() const { return thirst; }
     
     //int Player::getScore() const { return score;}
    
    void Player::setHealth(int hp) { health = hp; }
    
    void Player::setHunger(int h) { hunger = h; }
    
    void Player::setThirst(int t) { thirst = t; }
    
    //void Player::setScore(int s) {score = s; }
    
    void Player::newTurn()
    {
        
        if(hunger <= 0)
        {
            hunger == 0;
        }
        else
        {
            hunger--;
        }
        
        if(thirst <= 0)
        {
            thirst == 0;
        }
        else
        {
            thirst--;
        }
        if(hunger == 0 || thirst == 0)
        {
            health--;
        }
        //score++;
        
    }
    
    std::string Player::printStats()
    {
        std::ostringstream ss;
        ss << "Health: " << health << " ";
        ss << "Hunger: " << hunger << " ";
        ss << "Thirst: " << thirst;
        return ss.str();
    }
    
    
    bool Player::isAlive() const { return health > 0; 
                                 
    }

