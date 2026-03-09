#include "myClass.h"
#include <iostream>
#include <ctime>

void Player::playerMove(char c, Map &m)
{

    switch (c)
    {
    case 'w':
        if(startX > 0)
        {
            //Map::gridArray[startX][startY] = '.'
            //hier muss ich x und y weitergeben das sie zu . wurden nachdem
            //der spieler drauf war
            //function:map_überarbeiten
            m.handleMap(*this);
            startX -= 1;
            m.handlePlayer(*this);
            //check einbauen was auf der fp ist.
        }
        break;
    case 's':
        if(startX < 4)
        {
            m.handleMap(*this);
            startX += 1;
            m.handlePlayer(*this);
        }
        break;
    case 'd':
        if(startY < 4)
        {
            m.handleMap(*this);
            startY += 1;
            m.handlePlayer(*this);
        }
        break;
    case 'a':
        if(startY > 0)
        {
            m.handleMap(*this);
            startY -= 1;
            m.handlePlayer(*this);
        }
        break;
    default:
        break;
    }
    //std::cout<<"Position: " << startX << "/" << startY;
}

//stats
void Player::playerStats(Map &m)
{
    std::cout << "Health: " << health << "  " << "Position: "<< startX << "/" << startY << " Relcis: " << relictPlayerCount << "/"<< m.getRelictCount()<<std::endl;
    
}

void Player::setHealth(int h)
{
    health = h;
}

int Player::getX() const
{
    return startX;
}
int Player::getY() const
{
    return startY;
}

void Player::setRelictCount(int r)
{
    relictPlayerCount += r;
}

int Player::getRelictCount()
{
    return relictPlayerCount;
}

int Player::getHealth()
{
    return health;
}