#ifndef MYCLASS_H
#define MYCLASS_H

class Player;
class Enemy; // forward declaration

class Map {
private:
  char gridArray[5][5];
  int relictCount;
  void generateMap(const Player &p);

public:
  // constructor
  Map(const Player &p); // muss nicht ver#ndert werden ist basicly einfach nur
                        // da um die welt zu genereiren!

  // getter
  int getRelictCount() const;
  char getInfo(int x, int y) const;

  // setter
  void setInfo(int x, int y, char c);

  // funktionen
  void gridPrint() const; // weil es die map nicht verändern soll
  void handlePlayer(Player &p);
  void handleRoute(const Player &p);
  void newMap(const Player &p);
};

class Player {
private:
  int health = 5;
  int startX = 0;
  int startY = 0;
  int relictPlayerCount = 0;

public:
  // getter
  int getX() const;
  int getY() const;
  int getRelictCount();
  int getHealth() const;

  // setter
  void setHealth(int h);
  void setRelictCount(int r);

  // funktionen
  void playerMove(char c, Map &m);
  void playerStats(const Map &m);
};

class Enemy {
private:
  int startX;
  int startY;
  char underEnemy;
  int difficulty = 3;

public:
  void findPathEnemy(Map &m);
  void enemyMove(Player &p, Map &m, int difficulty);
};
#endif