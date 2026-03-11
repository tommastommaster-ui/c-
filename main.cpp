#include "myClass.h"
#include <ctime>
#include <iostream>

int main() {
  // std::cout << rand()<< std::endl;
  srand(time(0));
  char c;
  int endGame = 1;
  int difficulty = 3;

  Player player;
  Map world(player);
  Enemy enemy;

  enemy.findPathEnemy(world);
  world.gridPrint();
  player.playerStats(world);

  std::cout << std::endl;

  while (endGame == 1) {
    std::cin >> c;
    while (c != 'w' && c != 'a' && c != 's' && c != 'd') {
      std::cin >> c;
    }
    player.playerMove(c, world);
    enemy.enemyMove(player, world, difficulty);
    world.gridPrint();
    player.playerStats(world);
    if (player.getRelictCount() == world.getRelictCount()) {
      if (difficulty > 1) {
        difficulty -= 1;
      }
      player.setRelictCount(-(player.getRelictCount()));
      world.newMap(player);
      enemy.findPathEnemy(world);
      world.gridPrint();
      player.playerStats(world);
    } else if (player.getHealth() == 0) {
      std::cout << "GAME OVER GAME OVER!!!" << std::endl;
      endGame = 0;
    }

    std::cout << std::endl;
  }

  return 0;
}