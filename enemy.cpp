#include <iostream>
#include "myClass.h"

void Enemy::findPathEnemy(Map &m)
{
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if(m.getInfo(i, j) == '_')
            {
                startX = i;
                startY = j;
            }
        }
    }

    underEnemy = m.getInfo(startX, startY);
    m.setInfo(startX, startY, 'E'); 
};

void Enemy::enemyMove(Player &p, Map &m, int difficulty)
{   

    int oldX = startX;
    int oldY = startY;
    
 
    if(startX != p.getX())
    {
        
        if(rand()%difficulty==0)
        {
            if(startX < p.getX())
            {
                ++startX;
            }
            else if(startX > p.getX())
            {
                --startX;
            }
        }

    }
    else 
    {
        if(rand()%difficulty==0)
        {
            if(startY < p.getY())
            {
                ++startY;
            }
            else if(startY > p.getY())
            {
                --startY;
            }
        }

    }

    if(m.getInfo(startX, startY) == 'X')
    {

        p.setHealth(0);
        m.setInfo(oldX, oldY, underEnemy);
        m.setInfo(startX, startY, 'E');
        return;
    }

    //move Enemy
    m.setInfo(oldX, oldY, underEnemy);
    underEnemy = m.getInfo(startX, startY);
    m.setInfo(startX, startY, 'E');
    
    
};