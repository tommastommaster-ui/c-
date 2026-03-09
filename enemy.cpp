#include <iostream>
#include "myClass.h"

void Enemy::findPlace(Map &m)
{
    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j < 5; ++j)
        {
            if(m.gridArray[i][j] == '_')
            {
                startX = i;
                startY = j;
                
            }
        }
    }
    underEnemy = m.gridArray[startX][startY]; 
    m.gridArray[startX][startY] = 'E';
};

void Enemy::enemyMove(Player &p, Map &m)
{   
    //underEnemy = m.gridArray[startX][startY];
    //m.gridArray[startX][startY] = 'E';
    
    int oldX = startX;
    int oldY = startY;


    if(startX < p.startX)
    {
        ++startX;
    }
    else if (startX > p.startX)
    {
        --startX;
    }
    else if(startY < p.startY)
    {
        ++startY;
    }
    else if(startY > p.startY)
    {
        --startY;
    }
    
    if(startX == p.startX && startY == p.startY)
    {
        //despawn = true;
        //m.gridArray[startX][startY] = underEnemy;
        m.gridArray[oldX][oldY] = underEnemy;
        underEnemy = m.gridArray[startX][startY];
        m.gridArray[startX][startY] = 'E';  
        p.health = 0;
        return;
    }

    m.gridArray[oldX][oldY] = underEnemy;
    underEnemy = m.gridArray[startX][startY];
    m.gridArray[startX][startY] = 'E';




};