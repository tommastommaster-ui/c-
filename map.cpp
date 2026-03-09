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

void Map::gridPrint()
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

void Map::handleMap(Player &p)
{
    if(gridArray[p.startX][p.startY] == 'X')
    {
        gridArray[p.startX][p.startY] = '.';
    }
    
}

void Map::handlePlayer(Player &p)
{
    if(gridArray[p.startX][p.startY] == 'D')
    {
        int randomHealth = rand() % 5;
        if(randomHealth == 0)
        {
            p.health-=1;
        }
    }
    else if(gridArray[p.startX][p.startY] == 'F')
    {
        p.health +=1;
    }
    else if(gridArray[p.startX][p.startY] == 'R')
    {
        p.relictPlayerCount +=1;
    }
    gridArray[p.startX][p.startY] = 'X';
}

