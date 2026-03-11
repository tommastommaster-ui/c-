#include "myClass.h"
#include <iostream>
#include <ctime>



void Player::playerMove(char c, Map &m)
{
    int newX = startX;
    int newY = startY;

    switch (c)
    {
    case 'w':
        if (newX > 0)
        {
            newX -= 1;
        }
        break;
    case 's':
        if (newX < 4)
        {
            newX += 1;
        }
        break;
    case 'd':
        if (newY < 4)
        {
            newY += 1;
        }
        break;
    case 'a':
        if (newY > 0)
        {
            newY -= 1;
        }
        break;
    default:
        break;
    }

    if(newY >= 0 && newY < 5 || newX >= 0 && newX < 5)
    {
        m.handleRoute(*this); //this ist ein pointer auf das aktuelle objekt 
        //*this ist ein referenz auf das objekt
        startX = newX;
        startY = newY;
        m.handlePlayer(*this);
    }


}

// stats
void Player::playerStats(const Map &m)
{
    std::cout << "Health: " << health << "  " << "Position: " << startX << "/" << startY << " Relcis: " << relictPlayerCount << "/" << m.getRelictCount() << std::endl;
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

int Player::getHealth() const
{
    return health;
}