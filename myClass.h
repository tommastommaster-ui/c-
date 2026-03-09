#ifndef MYCLASS_H
#define MYCLASS_H

class Player;
class Enemy; //forward declaration

class Map{
    public:
        char gridArray [5][5];
        int relictCount;
        Map();  
        void gridPrint();
        void handlePlayer(Player &p);
        void handleMap(Player &p);
        void handleEnemy(Enemy &e);
        int endGame = 0;
};

class Player{
    public:
        int health = 5;
        int startX = 0;
        int startY = 0;
        int relictPlayerCount = 0;
        void playerMove(char c, Map &m);
        void playerStats(Map &m);
};

class Enemy{
    public:
    int startX = 5;
    int startY = 5;
    bool despawn = false;
    char underEnemy;
    void findPlace(Map &m);
    void enemyMove(Player &p, Map &m);
};



#endif