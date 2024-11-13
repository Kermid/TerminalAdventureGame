#ifndef SECONDLEVEL_HPP
#define SECONDLEVEL_HPP
#include "Entities.hpp"
#include "Locations.hpp"

void SecondLeft(Player&player);
void SecondCentre(Player&player);
void SecondRight(Player&player);
void SecondLevel(Player& player)
{
    int choice;
    int outcome;
    bool continueFirst = true;
    std::vector<Enemy> listOfEnemies;

    Location locationLeft = generateForestArea();
    Location locationCentre = generateForestArea();
    Location locationRight= generateForestArea();

    while(continueFirst)
    {

    
        std::cout << "Masz przed soba trzy siezki" << std::endl;
        std::cout << "1 - Lewo  2 - Prosto  3 - Prawo 4 - Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;
    
        switch (choice)
        {
        case 1:
            GenerateLocationRandomFight(locationLeft,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            continueFirst = false;
        break;
        case 2:
            GenerateLocationRandomFight(locationCentre,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            continueFirst = false;
        break;
        case 3:
            GenerateLocationRandomFight(locationRight,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            continueFirst = false;
        case 4:
            CheckInventory(player);
        break;
        default:
            std::cout << "Nieprawidlowy wybor" << std::endl;
        break;
        }
    }

}
void SecondLeft(Player&player)
{

}
void SecondCentre(Player&player)
{

}
void SecondRight(Player&player)
{
    
}

#endif


