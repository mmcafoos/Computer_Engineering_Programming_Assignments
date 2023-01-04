#include <iostream>
#include <algorithm>
#include "lands.h"
#include "player.h"

enum PlayerChoice {NORTH, SOUTH, EAST, WEST, QUIT};

/*was trying to have the world be built outside of main function, not working that well
const  int MAP_SIZE = 10;
*/
void clearTerminal()
{
    for(int i = 0; i < 50; i++)
    {
        std::cout << std::endl;
    }
}

bool getPlayerInput(PlayerChoice &playerChoice)
{
    // 0 = North, 1 = South, 2 = East, 3 = West
    std::string input;
    std::cout << "Which direction will you go?" << std::endl;
    std::cout << "Enter N, S, E, W, or Q" << std::endl;
    std::cin >> input;
    
    transform(input.begin(), input.end(), input.begin(), ::tolower);    
    
    if(input == "n")                                            
    {
        playerChoice = NORTH;
    } else if(input == "s")
    {
        playerChoice = SOUTH;
    } else if(input == "e")
    {
        playerChoice = EAST;
    } else if(input == "w")
    {
        playerChoice = WEST;
    } else if(input == "q")
    {
        playerChoice = QUIT;
    } else
    {
        std::cout << "Invalid input." << std::endl;
        return false;
    }
    return true;
}
/*
void buildWorld(){
    for(int i = 0; i < WORLD_SIZE; i++){
        for(int j = 0; j < WORLD_SIZE; j++){
            world[i][j] = getRandomLand();
        }
    }
} Failed function
*/
int main()
{
    const  int MAP_SIZE = 10;
    Player player(Player::DEFAULT_HEALTH, Player::DEFAULT_HUNGER, Player::DEFAULT_THIRST, MAP_SIZE/2, MAP_SIZE/2);
    
    // Build a 10x10 map
    Land* map[MAP_SIZE][MAP_SIZE];
    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j < MAP_SIZE; j++)
        {
            map[i][j] = getRandomLand();
        }
    }
    
    std::cout << "You awaken in a " <<                                 
        map[player.getX()][player.getY()]->getShortDescription() <<
        " with no memory of how you got there. It's like you have anmesia or something" << std::endl;
    
    while(player.isAlive())
    {
        
        player.newTurn();
        
        // Provides the player with a description of their surroundings
        int x = player.getX();
        int y = player.getY();
        
        std::cout << map[x][y]->getLongDescription() << std::endl << std::endl; 
        std::cout << map[x][y]->visit(player) << std::endl << std::endl;       
        
        std::cout << player.printStats() << std::endl << std::endl;             // Prints out the player's stats.
        
        
        //I have no clue if my wrapound funciton is working right
        std::cout << "To the north you see a " << map[x][(y + 1 + 10) % 10]->getShortDescription() << std::endl; // Using Module % to wrap around the map.

        std::cout << "To the south you see a " << map[x][(y - 1 + 10) % 10]->getShortDescription() << std::endl;
    
        std::cout << "To the east you see a " << map[(x + 1 + 10) % 10][y]->getShortDescription() << std::endl;
 
        std::cout << "To the west you see a " << map[(x - 1 + 10) % 10][y]->getShortDescription() << std::endl;
        
        PlayerChoice playerChoice;
        
        while(!getPlayerInput(playerChoice));
        
        switch(playerChoice)
        {
            case NORTH:
                player.setY((player.getY() + 1 + 20) % 20); // Using module % fixed the bus error.
                break;
            case SOUTH:
                player.setY((player.getY() - 1 + 20) % 20); // Each one moves the character in the direction it specifies.
                break;
            case EAST:
                player.setX((player.getX() + 1 + 20) % 20);
                break;
            case WEST:
                player.setX((player.getX() - 1 + 20) % 20);
                break;
            case QUIT:
                player.setHealth(0);
                break;
            default:
                std::cout << "Invalid input found: " << playerChoice << std::endl;
        }
        
        clearTerminal();    
    }
    
    std::cout << "You died! You did your best in surviving. Better luck next time!" << std::endl;
    
    return 0;
}
