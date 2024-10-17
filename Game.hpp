#ifndef GAME_HPP
#define GAME_HPP
#include "Entities.hpp"
#include "Items.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

void Chest(Item item);
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
            std::cout << "Wkraczasz na zapomniany cmentarz.Krzywe,omszale nagrobki wyrastaja z grzaskiego gruntu,"  << std::endl;
            std::cout << "a powykrecane drzewa splataja swoje galezie nad nimi, tworzac ponura kopule." << std::endl;
            std::cout << "Metna woda zbiera sie w kaluzach wokol grobow, a mgla unosi sie nisko nad ziemia." << std::endl;
            std::cout << "Cmentarz jest cichy, poza odleglym rechotem zab i szeletem traw, a powietrze jest ciezkie od zapachu zgnilizny i stechlizny." << std::endl;
            std::cout << "Miejsce zdaje sie zapomniane przez czas, budzac niepokoj i tajemnice." << std::endl;

                Fight(player,listOfEnemies);
        break;
        case 2:
            std::cout << "Wybrales druga droge" << std::endl;
            Weapon item = GetWeapon();
            Chest(item);
        break;
        case 3:
            std::cout << "Wybrales trzecia droge" << std::endl;
        break;
    }
}
void Chest(Weapon weapon)
{
    std::cout << "Udalo ci sie znalesc skrzynie" << std::endl;
    std::cout << "W srodku znajduje sie: " << weapon << std::endl;
    
}
void Chest(Armor armor)
{
    std::cout << "Udalo ci sie znalesc skrzynie" << std::endl;
    std::cout << "W srodku znajduje sie: " << armor << std::endl;
    
}
void Attack(Player& player,Enemy& enemy)
{
    int damage = (1 + player.strenght) - enemy.armor;
    if(damage < 0)
    {
        std::cout << "Obrazenia nie moga byc ujemne" << std::endl;
    }
    enemy.health -= damage;
    
    if(enemy.health < (1 + player.strenght) - enemy.armor)
    {
        std::cout << "Pokonales przeciwnika!" << std::endl;
    }
    else
    {
        std::cout << "Zadajesz " << (1 + player.strenght) - enemy.armor << " obrazen przeciwnikowi"<< std::endl;
        std::cout << "Zdrowie przeciwnika wynosi teraz: " << enemy.health << std::endl;
    }
    
}
void EnemyAttack(Player& player,Enemy& enemy)
{
    int damage = (1 + enemy.strenght) - player.armor;
    if(damage < 0)
    {
        std::cout << "Obrazenia nie moga byc ujemne" << std::endl;
    }
    player.health -= damage;
    std::cout << "Otrzymujesz " << damage << " obrazen"<< std::endl;
    std::cout << "Twoje zdrowie wynosi: " << player.health << std::endl;
}
void Fight(Player& player, std::vector<Enemy>& listOfEnemies)
{
    bool endFight = false;

    SpawnSkeletons(2,listOfEnemies);

    AnnounceEnemies(listOfEnemies);
    
    
    while (endFight == false)
    {
        Enemy& enemy = ChooseEnemy(listOfEnemies);
        Attack(player,enemy);
        if(enemy.health <= 0)
        {
            std::cout << enemy.name << " zostal pokonany!" << std::endl;

            listOfEnemies.erase(std::remove_if(listOfEnemies.begin(),listOfEnemies.end(),[&enemy](Enemy& e) {return e.EnemyId == enemy.EnemyId;}),listOfEnemies.end());
        }
        else
        {
            std::cout <<"Przeciwnik zyje.Walka trwa dalej!" << std::endl;
        }
        for(Enemy& enemy : listOfEnemies)
        {
            EnemyAttack(player,enemy);
        }
        //checking if list is empty or player has died
        if(listOfEnemies.empty() || player.health <= 0)
        {
            endFight = true;
        }
    }
    
}
void CalculatingTurns(Player& player,std::vector<Enemy>& listofEnemies)
{

}
#endif