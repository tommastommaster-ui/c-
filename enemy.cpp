#include <iostream>
#include "myClass.h"

void Enemy::findSpawn(Map &m)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (m.getInfo(i, j) == '_')
            {
                posX = i;
                posY = j;
            }

        }
    }

    underEnemy = m.getInfo(posX, posY);
    m.setInfo(posX, posY, 'E');
};


void Enemy::movePathEnemy(Player &p, Map &m, int difficulty)
{

    int oldX = posX;
    int oldY = posY;

    if (posX != p.getX())
    {

        if (rand() % difficulty == 0)
        {
            if (posX < p.getX())
            {
                ++posX;
            }
            else if (posX > p.getX())
            {
                --posX;
            }
        }
    }
    else
    {
        if (rand() % difficulty == 0)
        {
            if (posY < p.getY())
            {
                ++posY;
            }
            else if (posY > p.getY())
            {
                --posY;
            }
        }
    }

    if (m.getInfo(posX, posY) == 'X')
    {
        p.setHealth(0);
        m.setInfo(oldX, oldY, underEnemy);
        m.setInfo(posX, posY, 'E');
        return;
    }

    // move Enemy
    m.setInfo(oldX, oldY, underEnemy);
    underEnemy = m.getInfo(posX, posY);
    m.setInfo(posX, posY, 'E');


};