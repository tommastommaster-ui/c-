#include <iostream>
#include "myClass.h"
#include <ctime>


int main(){
    //std::cout << rand()<< std::endl;
    srand(time(0));
    char c; 
    int endGame = 0;
    

    Map world;
    Player player;
    Enemy enemy;

    world.gridPrint();
    player.playerStats(world);
    enemy.findPlace(world);
    //debug
    std::cout << enemy.startX << "/" << enemy.startY << std::endl;
    //debug
    std::cout << std::endl;

    while(endGame == 0)
    {
        std::cin >> c;
        while(c != 'w'&& c != 'a'&& c != 's'&& c != 'd')
        {
            std::cin >> c;
        }
        player.playerMove(c, world);
        
        
        //enemy.enemyMove(player, world);
        world.gridPrint();
        player.playerStats(world);
        //debug
        //std::cout << enemy.startX << "/" << enemy.startY << std::endl;
        //debug
        
        if(player.relictPlayerCount == world.relictCount)
        {
            world.gridPrint();
            player.playerStats(world);
            std::cout << "\nYou have WON the game!!!\n";
            return endGame = 1;
        }
        else if(player.health == 0)
        {
            world.gridPrint();
            player.playerStats(world);
            std::cout << "\nYou have LOST the game!!!\n";
            return endGame = 1;
        }
        std::cout << std::endl;
    }
    
    return 0;
}