#ifndef TOWN_HPP
#define TOWN_HPP
#include "Game.hpp"
#include "Entities.hpp"
#include "Items.hpp"
#include "Spells.hpp"
#include <iostream>


void potionShop(Player& player)
{
    std::vector<Item> shopkeepersItems;
    for(int i = 0; i < 3)
    {
        
    }
    for(int i = 0; i < 3)
    {
        
    }

}
void weaponShop(Player& player)
{
    std::vector<Item> shopkeepersItems;
    for(int i = 0; i < 3)
    {
        
    }
    for(int i = 0; i < 3)
    {
        
    }
}
void armorShop(Player& player)
{
    int counter;
    std::vector<Item> shopkeepersItems;
    for(int i = 0; i < 2)
    {
        shopkeepersItems.push_back(GetArmorSecondLevel);
    }
    for(int i = 0; i < 4)
    {
        shopkeepersItems.push_back(GetArmorFirstLevel);
    }
    while(true)
    {   
        counter = 1;
        std::cout << "Witaj w sklepie ze zbrojami!" << std::endl;
        std::cout << "Oferta sprzedawcy!" << std::endl;
        std::cout << "" << std::endl;
        for(Item item : shopkeepersItems)
        {
            std::cout << "|#" << counter << " " << item.name << std::endl;
            counter++
            std::cout << "|Pancerz: " << item.armor << " Sila:  " << item.strenght << " Wytrzymalosc:  " << item.stamina << std::endl;
            std::cout << "|Zrecznosc: " << item.agility << " Inteligencja:  " << item.intelligence << " Koszt: " << item.cost << std::endl;
        }
    }
    
}
void regions(Player& player)
{

}
void Town(Player& player)
{
    bool townContinue = true;
    int townChoice;
    std::cout << "***** Dotarles do miasta! *****" << std::endl;
    std::cout << "1 - Sklep z bronia 2 - Sklep z zbroja 3 - Sklep z miksturami 4 - Zadania 5 - Regiony " << std::endl;
    while(townContinue)
    {
        switch(townChoice)
        {
            case 1:
                weaponShop(player);
            break;
            case 2:
                armorShop(player);
            break;
            case 3:
                potionShop(player);
            break;
            case 4:
                
            break;
            case 5:
            regions(player);
            break;
            default:
                std::cout << "Nie prawidlowa opcja!" << std::endl;
            break;
        }
    }

}
#endif 