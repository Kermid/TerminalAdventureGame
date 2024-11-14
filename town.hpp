#ifndef TOWN_HPP
#define TOWN_HPP
#include "FirstLevel.hpp"
#include "Entities.hpp"
#include "Items.hpp"
#include "Inn.hpp"
#include "Spells.hpp"
#include <iostream>
#include <vector>

void Sell(Player& player,std::vector<Item>& listOfItems)
{
    bool sellContinue = true;
    int counter;
    int sellingStop;
    while(sellContinue)
    {
        std::cout << "****** TWOJ EKWIPUNEK ******" << std::endl;
        counter = 1;
        for(Item item : player.Inventory)
        {   
            std::cout << "|#" << counter << " " << item.name << std::endl;
            counter++;
        }
        std::cout << "|Zloto: " << player.gold << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        std::cout << "1 - Sprzedaj 2 - Zakoncz sprzedawanie" << std::endl;
        std::cout << "-------------------------------------" << std::endl;
        std::cin >> sellingStop;
        if(sellingStop == 2)
        {
            break;
        }
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Ktory przedmiot chcesz sprzedac?" << std::endl;

        int choiceItem;
        std::cin >> choiceItem;

        if (choiceItem > 0 && choiceItem <= player.Inventory.size())
        {

            player.gold += player.Inventory[choiceItem - 1].cost - 1;
            player.Inventory.erase(player.Inventory.begin() + (choiceItem - 1));

        }
        else
        {
            std::cout << "Niepoprawny numer przedmiotu." << std::endl;
        }
    }
    
}
void Buy(Player& player,std::vector<Item>& shopItemList)
{
    bool buyContinue = true;
    int counter = 1;
    int buyingStop;
    int choiceItem;
    while(buyContinue)
    {
        counter = 1;
        std::cout << "Witaj w sklepie ze zbrojami!" << std::endl;
        std::cout << "Oferta sprzedawcy!" << std::endl;
        std::cout << "" << std::endl;

        for(Item item : shopItemList)
        {
            std::cout << "|#" << counter << " " << item.name << std::endl;
            counter++;
            std::cout << "-----------------------------------------" << std::endl;
            std::cout << "|Pancerz: " << item.armor << " Sila:  " << item.strenght << " Wytrzymalosc:  " << item.stamina << std::endl;
            std::cout << "|Zrecznosc: " << item.agility << " Inteligencja:  " << item.intelligence << " Koszt: " << item.cost << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
        }

        std::cout << "|Zloto: " << player.gold << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "1 - Kup 2 - Zakoncz kupowanie" << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        std::cin >> buyingStop;

        if(buyingStop == 2)
        {
            break;
        }
        std::cout << "Ktory przedmiot chcesz kupic?" << std::endl;

        
        std::cin >> choiceItem;
        
        if (choiceItem > 0 && choiceItem <= shopItemList.size())
        {

            player.gold -= shopItemList[choiceItem - 1].cost;
            player.Inventory.push_back(shopItemList[choiceItem - 1]);
            shopItemList.erase(shopItemList.begin() + (choiceItem - 1));
            

        }
        else
        {
            std::cout << "Niepoprawny numer przedmiotu." << std::endl;
        }
    }
}
void BuyPotion(Player& player,std::vector<Item>& shopItemList)
{
    bool buyContinue = true;
    int counter = 1;
    int buyingStop;
    int choiceItem;
    while(buyContinue)
    {
        counter = 1;
        std::cout << "Witaj w sklepie ze zbrojami!" << std::endl;
        std::cout << "Oferta sprzedawcy!" << std::endl;
        std::cout << "" << std::endl;

        for(Item item : shopItemList)
        {
            std::cout << "-----------------------------------------" << std::endl;
            std::cout << "|#" << counter << " " << item.name << std::endl;
            counter++;
            std::cout << "| Koszt: " << item.cost << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
        }

        std::cout << "|Zloto: " << player.gold << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        std::cout << "1 - Kup 2 - Zakoncz kupowanie" << std::endl;
        std::cout << "-----------------------------------------" << std::endl;
        std::cin >> buyingStop;

        if(buyingStop == 2)
        {
            break;
        }
        std::cout << "Ktory przedmiot chcesz kupic?" << std::endl;

        
        std::cin >> choiceItem;
        
        if (choiceItem > 0 && choiceItem <= shopItemList.size())
        {

            player.gold -= shopItemList[choiceItem - 1].cost;
            player.Inventory.push_back(shopItemList[choiceItem - 1]);
            shopItemList.erase(shopItemList.begin() + (choiceItem - 1));
            

        }
        else
        {
            std::cout << "Niepoprawny numer przedmiotu." << std::endl;
        }
    }
}
void potionShop(Player& player)
{
    std::vector<Item> shopkeepersItems;
    int Choice;
    int counter;
    for(int i = 0; i < 3;i++)
    {
        shopkeepersItems.push_back(getHealthPotion());
    }
    for(int i = 0; i < 3;i++)
    {
        shopkeepersItems.push_back(getManaPotion());
    }
     while(true)
    {   
        counter = 1;
        std::cout << "Witaj w sklepie z bronia!" << std::endl;
        std::cout << "Oferta sprzedawcy!" << std::endl;
        std::cout << "" << std::endl;
        for(Item item : shopkeepersItems)
        {
            std::cout << "|#" << counter << " " << item.name << std::endl;
            counter++;
        }
        std::cout << "----------------------------------------"<< std::endl;
        std::cout << "1 - Kup 2 - Sprzedaj 3 - Wyjdz ze Sklepu" << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        std::cin >> Choice;

        if(std::cin.fail()) 
        {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Nieprawidlowa opcja! Wprowadz liczbe od 1 do 3." << std::endl;
            continue; 
        }
        
        if(Choice == 3)
        {   
            break;
        }

        switch (Choice)
        {
        case 1:
            BuyPotion(player,shopkeepersItems);
        break;
        case 2:
            Sell(player,player.Inventory);
        break;
        default:
        std::cout << "Nieprawidlowa opcja!" << std::endl;
            break;
        }
    }
}
void weaponShop(Player& player)
{
    int counter;
    int Choice;
    std::vector<Item> shopkeepersItems;

    for(int i = 0; i < 2;i++)
    {
        shopkeepersItems.push_back(GetWeaponSecondLevel());
    }

    for(int i = 0; i < 2;i++)
    {
        shopkeepersItems.push_back(GetWeaponFirstLevel());
    }

    while(true)
    {   
        counter = 1;
        std::cout << "Witaj w sklepie z bronia!" << std::endl;
        std::cout << "Oferta sprzedawcy!" << std::endl;
        std::cout << "" << std::endl;
        for(Item item : shopkeepersItems)
        {
            std::cout << "|#" << counter << " " << item.name << std::endl;
            counter++;
            std::cout << "-----------------------------------------" << std::endl;
            std::cout << "|Obrazenia: " << item.damage << " Sila:  " << item.strenght << " Wytrzymalosc:  " << item.stamina << std::endl;
            std::cout << "|Zrecznosc: " << item.agility << " Inteligencja:  " << item.intelligence << " Koszt: " << item.cost << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
        }
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "1 - Kup 2 - Sprzedaj 3 - Wyjdz ze Sklepu" << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        std::cin >> Choice;

        if(std::cin.fail()) 
        {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Nieprawidlowa opcja! Wprowadz liczbe od 1 do 3." << std::endl;
            continue; 
        }
        
        if(Choice == 3)
        {   
            break;
        }

        switch (Choice)
        {
        case 1:
            Buy(player,shopkeepersItems);
        break;
        case 2:
            Sell(player,player.Inventory);
        break;
        default:
        std::cout << "Nieprawidlowa opcja!" << std::endl;
            break;
        }
    }
}
void armorShop(Player& player)
{
    int counter;
    int Choice;
    std::vector<Item> shopkeepersItems;

    for(int i = 0; i < 2;i++)
    {
        shopkeepersItems.push_back(GetArmorSecondLevel());
    }

    for(int i = 0; i < 3;i++)
    {
        shopkeepersItems.push_back(GetArmorFirstLevel());
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
            counter++;
            std::cout << "-----------------------------------------" << std::endl;
            std::cout << "|Pancerz: " << item.armor << " Sila:  " << item.strenght << " Wytrzymalosc:  " << item.stamina << std::endl;
            std::cout << "|Zrecznosc: " << item.agility << " Inteligencja:  " << item.intelligence << " Koszt: " << item.cost << std::endl;
            std::cout << "-----------------------------------------" << std::endl;
        }
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "1 - Kup 2 - Sprzedaj 3 - Wyjdz ze Sklepu" << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        std::cin >> Choice;

        if(std::cin.fail()) 
        {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            std::cout << "Nieprawidlowa opcja! Wprowadz liczbe od 1 do 3." << std::endl;
            continue; 
        }
        
        if(Choice == 3)
        {   
            break;
        }

        switch (Choice)
        {
        case 1:
            Buy(player,shopkeepersItems);
        break;
        case 2:
            Sell(player,player.Inventory);
        break;
        default:
        std::cout << "Nieprawidlowa opcja!" << std::endl;
            break;
        }
    }
    
}
void Town(Player& player)
{
    bool townContinue = true;
    int townChoice;
    std::cin >> townChoice;
    while(townContinue)
    {
        
        std::cout << "***** Miasto Bagienna przystan! *****" << std::endl;
        std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "1 - Sklep z bronia 2 - Sklep z zbroja 3 - Sklep z miksturami 4 - Karczma 5 - Wyjdz z miasta  6 - Sprawdz ekwipunek" << std::endl;
        std::cout << "-----------------------------------------------------------------------------------------------------------" << std::endl;
        std::cin >> townChoice;
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
                Inn(player);
            break;
            case 5:
                townContinue = false;
            break;
            case 6:
                CheckInventory(player);
            break;
            case 7:
            break;
            default:
                std::cout << "Nieprawidlowa opcja!" << std::endl;
            break;
        }
    }

}
#endif 