#ifndef GAME_HPP
#define GAME_HPP
#include "Entities.hpp"
#include "Items.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

void Chest(Item item,Player& player);
void CentreSecond(Player& player);
void LeftSecond(Player& player);
void Trap(Player& player);
void CheckInventory(Player& player);
int Fight(Player& player,std::vector<Enemy>& listOfEnemies);

void FirstLevel(Player& player)
{
    int choice;
    int outcome;
    std::vector<Enemy> listOfEnemies;
    
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
                    Chest(GetArmor(),player);
                    Chest(GetArmor(),player);
                    Chest(GetArmor(),player);
                    Chest(GetWeapon(),player);
                    CheckInventory(player);
                    LeftSecond(player);
                }
                else if(outcome == 0)
                {
                    std::cout << "ZGINALES!Koniec gry." << std::endl;
                }
                
        break;
        case 2:
            int choiceSecond;

            std::cout << "Wybrales druga droge" << std::endl;
            std::cout << "Dotarles do ruin starego drewnianego domu." << std::endl;
            std::cout << "Wlasciciele dawno sie stad wyniesli, jednak mozliwe, ze zostawili za soba czesc swojego majatku." << std::endl;
            std::cout << "1 - Przeszukaj okolice  2 - Idz dalej  3 - Sprawdz ekwipunek" << std::endl;

            std::cin >> choiceSecond;

            switch (choiceSecond)
            {
            case 1:
                Trap(player);
                Chest(GetArmor(),player);
                break;
            case 2:
                CentreSecond(player);
                break;
            case 3:
                CheckInventory(player);
                break;
            
            default:
                std::cout << "Niewlasciwa opcja" << std::endl;
                break;
            }
            
            
        break;
        case 3:
            int choiceThird;

            std::cout << "Wybrales trzecia droge" << std::endl;
            std::cout << "Pod drzewem lezy szkielet, wydaje sie ze moze znajdowac sie tutaj cos ciekawego." << std::endl;
            std::cout << "1 - Przeszukaj okolice  2 - Idz dalej  3 - Sprawdz ekwipunek" << std::endl;

            std::cin >> choiceThird;

            switch (choiceThird)
            {
            case 1:
                Chest(GetWeapon(),player);
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
    enemy.currentHealth -= damage;
    
    std::cout << "Zadajesz " << damage << " obrazen przeciwnikowi"<< std::endl;
    DisplayCurrentHealth(enemy);
    
    
}
void EnemyAttack(Player& player,Enemy& enemy)
{
    int damage = (1 + enemy.strenght) - player.armor;
    if(damage < 0)
    {
        damage = 0;
    }
    player.currentHealth -= damage;
    std::cout << "Otrzymujesz " << damage << " obrazen"<< std::endl;
    DisplayCurrentHealth(player);
}
int Fight(Player& player, std::vector<Enemy>& listOfEnemies)
{
    bool endFight = false;

    SpawnSkeletons(RandomNumber(2),listOfEnemies);

    AnnounceEnemies(listOfEnemies);
    
    
    while (endFight == false)
    {
        Enemy& enemy = ChooseEnemy(listOfEnemies);
        Attack(player,enemy);
        if(enemy.currentHealth <= 0)
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
        else if(player.currentHealth <= 0)
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
void Trap(Player& player)
{
    std::cout << "Idac natafiasz na pulapke!" << std::endl;
    bool dodge = Dodge(player);
    if(dodge)
    {
        std::cout << "Udalo ci sie uniknac pulapki" << std::endl;
    }
    else if (!dodge)
    {
        player.currentHealth -= 5;
        DisplayCurrentHealth(player);
    }
    
}
void LeftSecond(Player& player)
{
    int choice;
    int outcome;
    std::vector<Enemy> listOfEnemiesLeftSecond;
    std::cout << "Przechodzisz dalej w glab cmentarza.Po walce rozgladasz sie po po okolicy" << std::endl;
    std::cout << "Na wprost przed toba widnieje wejscie do krypty z ktorej dochodza niezbyt glosne odglosy poruszania sie jakiejs istoty." << std::endl;
    std::cout << "Po prawej widac zarosnieta brame, i biegnaca przez nia sciezka." << std::endl;
    std::cout << "Masz przed soba dwie siezki" << std::endl;
    std::cout << "1 - Wejdz do krypty  2 - Prawo" << std::endl;
    std::cin >> choice;

    switch (choice)
            {
            case 1:
                Trap(player);
                Fight(player,listOfEnemiesLeftSecond);
                break;
            case 2:
                Trap(player);
                CentreSecond(player);
                break;
            default:
            std::cout << "Nie prawidlowy wybor" << std::endl;
                break;
            }
}
void CentreSecond(Player& player)
{

}
#endif