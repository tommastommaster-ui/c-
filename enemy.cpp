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
    //spawnX = startX;
    //spawnY = startY;
    underEnemy = m.getInfo(startX, startY);
    m.setInfo(startX, startY, 'E'); 
};

void Enemy::enemyMove(Player &p, Map &m)
{   
    //underEnemy = m.gridArray[startX][startY];
    //m.gridArray[startX][startY] = 'E';



    int oldX = startX;
    int oldY = startY;
    
 
    if(startX != p.getX())
    {
        
        if(startX < p.getX()&& rand()%2==0)
        {
            ++startX;
        }
        else if(startX > p.getX())
        {
            --startX;
        }
    }
    else 
    {
        if(startY < p.getY()&& rand()%2==0)
        {
            ++startY;
        }
        else if(startY > p.getY())
        {
            --startY;
        }
    }




    if(m.getInfo(startX, startY) == 'X')
    {
        //int h = p.getHealth();
        p.setHealth(0);
        m.setInfo(oldX, oldY, underEnemy);
        m.setInfo(startX, startY, 'E');
        //underEnemy = m.getInfo(spawnX, spawnY);
        //startX = spawnX;
        //startY = spawnY;
        return;
    }

    //move Enemy
    m.setInfo(oldX, oldY, underEnemy);
    underEnemy = m.getInfo(startX, startY);
    m.setInfo(startX, startY, 'E');
    
    //char tmp = m.getInfo(startX, startY);  
    
};