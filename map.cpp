#include <iostream>
#include "myClass.h"
#include <ctime>

Map::Map()
{
    Map::relictCount = 0;
    //nested for loop
    do{
        for(int i = 0; i<5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(i ==0 && j==0)
                {
                    continue;
                }
                int randomNum = rand() % 10; //0-9
                if(randomNum >= 0 && randomNum <= 3)
                {
                    //leere Felder
                    gridArray[i][j] = '_';
                }
                else if(randomNum > 3 && randomNum <=7)
                {
                    gridArray[i][j] = 'D';
                }
                else if(randomNum > 7 && randomNum <= 8)
                {
                    gridArray[i][j] = 'F';
                }
                else if(randomNum == 9)
                {
                    gridArray[i][j] = 'R';
                    ++Map::relictCount;
                }
            }
        }
    } while(Map::relictCount == 0);
    
    gridArray[0][0] = 'X';

}
//das ist richtig und es generiert die map;



void Map::gridPrint() const
{
    for(int b = 0; b<5; b++)
    {
        for(int c = 0; c < 5; c++)
        {
            std::cout << gridArray[b][c] << " ";
        }
        std::cout << "\n";
        
    }
    std::cout << std::endl;
}
//bis hier ist es okay

//returniert die relicts





void Map::handleMap(Player &p)
{
    int x = p.getX();
    int y = p.getY();

    
    if(gridArray[x][y] == 'X')
    {
        gridArray[x][y] = '.';
    }
    
}

void Map::handlePlayer(Player &p)
{
    int x = p.getX();
    int y = p.getY();


    if(gridArray[x][y] == 'D')
    {
        int randomHealth = rand() % 5;
        if(randomHealth == 0)
        {
            p.setHealth(p.getHealth() -1);
        }
    }
    else if(gridArray[x][y] == 'F')
    {
        p.setHealth(p.getHealth() -1);
    }
    else if(gridArray[x][y] == 'R')
    {
        p.setRelictCount(1);
    }
    gridArray[x][y] = 'X';
}

int Map::getRelictCount() const
{
    return relictCount;
}

char Map::getInfo(int x, int y) const{
    return gridArray[x][y]; 
}

void Map::setInfo(int x, int y, char c)
{
    gridArray[x][y] = c;    
}

void Map::newMap(Player &p)
{
    Map::relictCount = 0;
    //nested for loop
    do{
        for(int i = 0; i<5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(i ==p.getX() && j==p.getY())
                {
                    continue;
                }
                int randomNum = rand() % 10; //0-9
                if(randomNum >= 0 && randomNum <= 3)
                {
                    //leere Felder
                    gridArray[i][j] = '_';
                }
                else if(randomNum > 3 && randomNum <=7)
                {
                    gridArray[i][j] = 'D';
                }
                else if(randomNum > 7 && randomNum <= 8)
                {
                    gridArray[i][j] = 'F';
                }
                else if(randomNum == 9)
                {
                    gridArray[i][j] = 'R';
                    ++Map::relictCount;
                }
            }
        }
    } while(Map::relictCount == 0);

}