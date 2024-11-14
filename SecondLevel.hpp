#ifndef SECONDLEVEL_HPP
#define SECONDLEVEL_HPP
#include "Entities.hpp"
#include "Locations.hpp"

int SecondLevelLeft(Player player);
int SecondLevelCentre(Player& player);
int SecondLevelRight(Player& player);
int SecondLevel(Player& player)
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
            outcome = GenerateLocationRandomFight(locationLeft,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return SecondLevelLeft(player);
            }
            else if(outcome == 0)
            {
                 std::cout << "ZGINALES!Koniec gry." << std::endl;
            }
            continueFirst = false;
        break;
        case 2:
            outcome = GenerateLocationRandomFight(locationCentre,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return SecondLevelCentre(player);
            }
            else if(outcome == 0)
            {
                 std::cout << "ZGINALES!Koniec gry." << std::endl;
            }
            continueFirst = false;
        break;
        case 3:
            outcome = GenerateLocationRandomFight(locationRight,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return SecondLevelRight(player);
            }
            else if(outcome == 0)
            {
                 std::cout << "ZGINALES!Koniec gry." << std::endl;
            }
            continueFirst = false;
        case 4:
            CheckInventory(player);
        break;
        default:
            std::cout << "Nieprawidlowy wybor" << std::endl;
        break;
        }
    }
    return 0;
}
int SecondLevelLeft(Player& player)
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
            outcome = GenerateLocationRandomFight(locationLeft,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 2:
            outcome = GenerateLocationRandomFight(locationCentre,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 3:
            outcome = GenerateLocationRandomFight(locationRight,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            else if(outcome == 0)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 4:
            CheckInventory(player);
        break;
        default:
            std::cout << "Nieprawidlowy wybor" << std::endl;
        break;
        }
    }
    return 0;
}
inline int SecondLevelLeft(Player player)
{
    return 0;
}
int SecondLevelCentre(Player &player)
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
            outcome = GenerateLocationRandomFight(locationLeft,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 2:
            outcome = GenerateLocationRandomFight(locationCentre,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 3:
            outcome = GenerateLocationRandomFight(locationRight,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            else if(outcome == 0)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 4:
            CheckInventory(player);
        break;
        default:
            std::cout << "Nieprawidlowy wybor" << std::endl;
        break;
        }
    }
    return 0;
}
int SecondLevelRight(Player& player)
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
            outcome = GenerateLocationRandomFight(locationLeft,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 2:
            outcome = GenerateLocationRandomFight(locationCentre,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 3:
            outcome = GenerateLocationRandomFight(locationRight,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            else if(outcome == 0)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 4:
            CheckInventory(player);
        break;
        default:
            std::cout << "Nieprawidlowy wybor" << std::endl;
        break;
        }
    }
    return 0;
}

#endif


