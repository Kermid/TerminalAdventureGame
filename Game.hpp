#ifndef GAME_HPP
#define GAME_HPP
#include "Entities.hpp"
#include "Items.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>


void Fight(Player& player,std::vector<Enemy>& listOfEnemies);
void FirstLevel(Player& player,Character& enemy)
{
    int choice;
    std::vector<Enemy> listOfEnemies;

    std::cout << "Wkraczasz do ponurych bagien, gdzie ziemia jest miekka i lepka, a kazdy krok wpada w glebokie bloto." << std::endl;
    std::cout << "Woda stoi w kaluzach, a gesta mgla spowija wszystko wokol, ograniczajac widocznosc." << std::endl;
    std::cout << "W powietrzu czuc zapach gnijacych roslin, a ciche odglosy bulgoczacej wody budza niepokoj." << std::endl;
    std::cout << "Musisz uwazac, bo w bagnach wszystko wydaje sie niebezpieczne, a droga przed toba jest zdradliwa." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Masz przed soba trzy siezki" << std::endl;
    std::cout << "1 - Lewo" << std::endl;
    std::cout << "2 - Prosto" << std::endl;
    std::cout << "3 - Prawo" << std::endl;
    
    std::cin >> choice;
    switch(choice)
    {
        case 1:
            std::cout << "Wybrales pierwsza droge" << std::endl;
                Fight(player,listOfEnemies);
        break;
        case 2:
            std::cout << "Wybrales druga droge" << std::endl;
        break;
        case 3:
            std::cout << "Wybrales trzecia droge" << std::endl;
        break;
    }
}
void Chest(Item item)
{
    std::cout << "Udalo ci sie znalesc skrzynie" << std::endl;
}
void Attack(Player& player,Enemy& enemy)
{
    enemy.health -= (1 + player.strenght) - enemy.armor;
    std::cout << "Zadajesz " << (1 + player.strenght) - enemy.armor << " obrazen przeciwnikowi"<< std::endl;
    std::cout << "Zdrowie przeciwnika wynosi teraz: " << enemy.health << std::endl;
}
void Fight(Player& player, std::vector<Enemy>& listOfEnemies)
{
    int random = RandomNum();
    SpawnEnemy(random,listOfEnemies);
    if(listOfEnemies.size() >= 1)
    {
        std::cout << "Przed toba pojawila sie grupa " << listOfEnemies[0].name << "ow"<< std::endl;
    }
    else if(listOfEnemies.size() < 1)
    {
        std::cout << "Przed toba pojawila sie " << listOfEnemies[0].name << std::endl;
    }
    
    
    while (!listOfEnemies.empty())
    {
        Enemy& enemy = ChooseEnemy(listOfEnemies);
        Attack(player,enemy);
        
    }
    
}

#endif