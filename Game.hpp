#ifndef GAME_HPP
#define GAME_HPP
#include "Entities.hpp"
#include "Items.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

void Chest(Item item,Player& player);
int Fight(Player& player,std::vector<Enemy>& listOfEnemies);
void FirstLevel(Player& player)
{
    int choice;
    int outcome;
    std::vector<Enemy> listOfEnemies;
    Item itemArmor = GetArmor();
    Item itemWeapon = GetWeapon();
    std::cout << "Wkraczasz do ponurych bagien, gdzie ziemia jest miekka i lepka, a kazdy krok wpada w glebokie bloto." << std::endl;
    std::cout << "Woda stoi w kaluzach, a gesta mgla spowija wszystko wokol, ograniczajac widocznosc." << std::endl;
    std::cout << "W powietrzu czuc zapach gnijacych roslin." << std::endl;
    std::cout << "Musisz uwazac, bo w bagnach wszystko wydaje sie niebezpieczne, a droga przed toba jest zdradliwa." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Masz przed soba trzy siezki" << std::endl;
    std::cout << "1 - Lewo  2 - Prosto  3 - Prawo" << std::endl;
    std::cout << "" << std::endl;
    
    std::cin >> choice;
    switch(choice)
    {
        case 1:

            std::cout << "Wybrales pierwsza droge" << std::endl;
            std::cout << "Wkraczasz na zapomniany cmentarz.Krzywe,omszale nagrobki wyrastaja z grzaskiego gruntu,"  << std::endl;
            std::cout << "a powykrecane drzewa splataja swoje galezie nad nimi, tworzac ponura kopule." << std::endl;
            std::cout << "Metna woda zbiera sie w kaluzach wokol grobow, a mgla unosi sie nisko nad ziemia." << std::endl;
            std::cout << "Cmentarz jest cichy, poza odleglym rechotem zab i szeletem traw slychac szelest w oddali" << std::endl;
            std::cout << "Miejsce zdaje sie zapomniane przez czas." << std::endl;

                outcome = Fight(player,listOfEnemies);
                if(outcome == 1)
                {
                    Chest(itemWeapon,player);
                }
                else if(outcome == 0)
                {
                    std::cout << "ZGINALES!Koniec gry." << std::endl;
                }
                
        break;
        case 2:
            std::cout << "Wybrales druga droge" << std::endl;
            std::cout << "Przeszukujesz ruiny starego drewnianego domu." << std::endl;
            std::cout << "Wlasciciele dawno sie stad wyniesli, jednak mozliwe, ze zostawili za soba czesc swojego majatku." << std::endl;
            Chest(itemArmor,player);
            CheckInventory(player);
        break;
        case 3:
            int choice;
            std::cout << "Wybrales trzecia droge" << std::endl;
            std::cout << "Pod drzewem lezy szkielet, wydaje sie ze moze znajdowac sie tutaj cos ciekawego." << std::endl;
            std::cout << "1 - Przeszukaj okolice  2 - Idz dalej  3 - Sprawdz ekwipunek" << std::endl;
            std::cin >> choice;

            switch (choice)
            {
            case 1:
                Chest(itemWeapon,player);
                break;
            case 2:
                
                break;
            case 3:
                CheckInventory(player);
                break;
            
            default:
                break;
            }
            
        break;
    }
}
void Chest(Item item,Player& player)
{
    int choiceTake;
    std::cout << "****** Udalo ci sie znalesc skrzynie ******" << std::endl;
    std::cout << "W srodku znajduje sie: " << item.name << std::endl;
    std::cout << "Czy bierzesz " << item.name << "?" << std::endl;
    std::cout << "1 - Tak  2 - Nie" << std::endl;
    std::cout << "" << std::endl;
    
    std::cin >> choiceTake;
    switch (choiceTake)
    {
    case 1:
        player.Inventory.push_back(item);
        CheckInventory(player);
        break;
    case 2:
            std::cout << "Nie bierzesz " << item.name << std::endl;
        break;
    default:
        std::cout << "Wybierz poprawna opcje." << std::endl;
        break;
    }
    
}
void Attack(Player& player,Enemy& enemy)
{
    int damage = (1 + player.strenght) - enemy.armor;
    if(damage < 0)
    {
        damage = 0;
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
        damage = 0;
    }
    player.health -= damage;
    std::cout << "Otrzymujesz " << damage << " obrazen"<< std::endl;
    std::cout << "Twoje zdrowie wynosi: " << player.health << std::endl;
}
int Fight(Player& player, std::vector<Enemy>& listOfEnemies)
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

            //Po zabiciu id jest aktualizowane

            for(Enemy& enemy : listOfEnemies)
            {
                enemy.EnemyId--;
            }
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
        if(listOfEnemies.empty())
        {
            endFight = true;
            return 1;
        }
        else if(player.health <= 0)
        {
            endFight = true;
            return 0;
        }
    }
    return 2;
}
void CalculatingTurns(Player& player,std::vector<Enemy>& listofEnemies)
{

}

#endif