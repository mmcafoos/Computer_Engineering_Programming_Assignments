#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <sstream>

class Player
{
    public:
    Player(int health, int hunger, int thirst, /*int score*/
            int x, int y);
    
    int getX() const;
    int getY() const;
    
    void setX(int newX);
    void setY(int newY);
    
    int getHealth() const;
    int getHunger() const;
    int getThirst() const;
    //int getScore() const;
    
    void setHealth(int hp);
    void setHunger(int h);
    void setThirst(int t);
    //void setScore(int s);
    
    void newTurn();
    
    std::string printStats();
    
    bool isAlive() const;
    
    static const  int DEFAULT_HEALTH = 5;
    static const  int DEFAULT_HUNGER = 15;
    static const  int DEFAULT_THIRST = 15;
    //static const  int DEFAULT_SCORE = 0;
    
    private:
    int health;
    int hunger;
    int thirst;
    //int score;
    int x;
    int y;
    
};

#endif
