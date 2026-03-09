#include <iostream>
#include "myClass.h"
#include <ctime>


int main(){
    //std::cout << rand()<< std::endl;
    srand(time(0));
    char c; 
    int endGame = 1;
    

    Map world;
    Player player;
    Enemy enemy;

    world.gridPrint();
    player.playerStats(world);
    //enemy.findPlace(world);
    //debug
    std::cout << enemy.startX << "/" << enemy.startY << std::endl;
    //debug
    std::cout << std::endl;

    while(endGame == 1)
    {
        std::cin >> c;
        while(c != 'w'&& c != 'a'&& c != 's'&& c != 'd')
        {
            std::cin >> c;
        }
        player.playerMove(c, world);
        world.gridPrint();
        player.playerStats(world);
        if(player.getRelictCount() == world.getRelictCount())
        {
            std::cout << "YOU HAVE WON THE GAME !!!"<< std::endl;
            endGame = 0;
        }
        else if(player.getHealth() == 0)
        {
            std::cout << "GAME OVER GAME OVER!!!" << std::endl;
            endGame = 0;
        }
        
        
        //enemy.enemyMove(player, world);

        //debug
        //std::cout << enemy.startX << "/" << enemy.startY << std::endl;
        //debug
        

        std::cout << std::endl;
    }
    
    return 0;
}