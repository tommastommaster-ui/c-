#ifndef MYCLASS_H
#define MYCLASS_H

class Player;
class Enemy; //forward declaration

class Map{
    private:
        char gridArray [5][5];
        int relictCount;         
    
    public:
        //constructor
        Map();  //muss nicht ver#ndert werden ist basicly einfach nur da um die welt zu genereiren!
        
        //getter
        int getRelictCount() const;
        char getInfo(int x, int y) const;

        //setter
        void setInfo(int x, int y, char c);

        //funktionen
        void gridPrint() const; //weil es die map nicht verändern soll
        void handlePlayer(Player &p);
        void handleMap(Player &p);
        void newMap(Player &p);
        
        ///IRGENWELCHE FUNKTIONEN;
        //char getInfo(int x, int y) const; //girArray ist privat deswegen muss gefragt werden was hier drauf ist 
        //void setInfo(int x, int y, char c); // zum überarbeiten vom Feldern;

        //void handleMap(Player &p);
        //void handleEnemy(Enemy &e);
        //int endGame = 0;
};

class Player{
    private:
        int health = 5;
        int startX = 0;
        int startY = 0;
        int relictPlayerCount = 0;

    public:
        //getter
        int getX() const;
        int getY() const;
        int getRelictCount();
        int getHealth();

        //setter
        void setHealth(int h);
        void setRelictCount(int r);

        //funktionen
        void playerMove(char c, Map &m);
        void playerStats(Map &m);
};

class Enemy{
    private:
        int startX;
        int startY;
        char underEnemy;
        char tmp;
        //int spawnX;
        //int spawnY;
    public:
        void findPathEnemy(Map &m);
        void enemyMove(Player &p, Map &m);
        //char getUnderEnemy();
};




class EnemyOld{
    
    public:
    int startX = 5;
    int startY = 5;
    bool despawn = false;
    char underEnemy;
    void findPlace(Map &m);
    void enemyMove(Player &p, Map &m);
};



#endif