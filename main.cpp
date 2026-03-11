#include "myClass.h"
#include <ctime>
#include <iostream>

int main()
{
  // std::cout << rand()<< std::endl;
  srand(time(0));
  char userInput;
  bool endGame = true;
  int difficulty = 3;

  Player player;
  Map world(player);
  Enemy enemy;

  enemy.findSpawn(world);
  world.gridPrint();
  player.playerStats(world);

  std::cout << std::endl;

  while (endGame)
  {
    do
    {
      std::cin >> userInput;
    } while (userInput != 'w' && userInput != 'a' && userInput != 's' && userInput != 'd');

    player.playerMove(userInput, world);
    enemy.movePathEnemy(player, world, difficulty);
    world.gridPrint();
    player.playerStats(world);
    if (player.getRelictCount() == world.getRelictCount())
    {
      if (difficulty > 1)
      {
        difficulty -= 1;
      }
      
      player.setRelictCount(-(player.getRelictCount()));
      world.newMap(player);
      enemy.findSpawn(world);
      world.gridPrint();
      player.playerStats(world);
    }
    if (player.getHealth() == 0)
    {
      std::cout << "GAME OVER GAME OVER!!!" << std::endl;
      endGame = false;
    }

    std::cout << std::endl;
  }

  return 0;
}