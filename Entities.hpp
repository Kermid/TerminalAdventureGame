#ifndef ENTITIES_HPP
#define ENTITIES_HPP
#include <string>
#include "Items.hpp"
#include <iostream>
#include <ctime>
#include <vector>


class Character{
    public:
        std::string name;
        int strenght;
        int agility;
        int stamina;
        int intelligence;
        int armor = 0;
        int health;
        int mana;
        std::vector<Item> Inventory;
        Item equippedWeapons[2];
        Item equippedArmor[4];
        bool alive = true;
        int speed;
        Character(std::string name,int strenght,int agility,int stamina,int intelligence,int armor,int health,int speed,bool alive)
        {
            this->name = name;
            this->strenght = strenght;
            this->agility = agility;
            this->stamina = stamina;
            this->intelligence = intelligence;
            this->armor = armor;
            this->health = health;
            this->speed = speed;
            this->alive = alive;
        };
        Character();
};
class Player : public Character{
    public:
            std::string gender;
            std::string playerClass;
            int playerId;
            std::vector<Item> Inventory;
            Player(int playerId,std::string name,std::string playerClass,std::string gender,int strenght,int agility,int stamina,int intelligence,int armor,int health,int mana,bool alive)
            {
                this->name = name;
                this->playerId = playerId;
                this->playerClass = playerClass;
                this->gender = gender;
                this->strenght = strenght;
                this->agility = agility;
                this->stamina = stamina;
                this->intelligence = intelligence;
                this->armor = armor;
                this->health = health;
                this->mana = mana;
                this->alive = alive;
            }
            Player();
};
class Enemy : public Character
{
    public:
        int EnemyId;
         Enemy(int EnemyId,std::string name,int strenght,int agility,int stamina,int intelligence,int armor,int health,int mana,int speed,bool alive)
            {
                this->EnemyId = EnemyId;
                this->name = name;
                this->strenght = strenght;
                this->agility = agility;
                this->stamina = stamina;
                this->intelligence = intelligence;
                this->armor = armor;
                this->health = health;
                this->mana = mana;
                this->speed = speed;
                this->alive = alive;
            }
};
Player::Player()
{

}
Character::Character()
{

}
int RandomOfThree()
{
    int randomNum;
    srand(time(NULL));
    randomNum = rand() % 3;
    return randomNum;
}
void SpawnSkeletons(int randomNum,std::vector<Enemy>& listOfEnemies)
{
    
    for(int i = 0;i < randomNum;i++)
    {
        Enemy enemy(listOfEnemies.size() + 1,"Szkielet",1,4,4,1,1,50,0,2,true);
        listOfEnemies.push_back(enemy);
    }
    
}
void AnnounceEnemies(std::vector<Enemy>& listOfEnemies)
{
    if(listOfEnemies.size() >= 1)
    {
        std::cout << "Przed toba pojawila sie grupa " << listOfEnemies[0].name << "ow"<< std::endl;
    }
    else if(listOfEnemies.size() < 1)
    {
        std::cout << "Przed toba pojawila sie " << listOfEnemies[0].name << std::endl;
    }
}
void DisplayEnemies(std::vector<Enemy>& listOfEnemies)
{
    for(Enemy enemy : listOfEnemies)
    {
        std::cout << "#" << enemy.EnemyId << " " << enemy.name << " HP: " << enemy.health << std::endl;
    }
}
Enemy& ChooseEnemy(std::vector<Enemy>& listOfEnemies)
{
    int enemyChoice;

    std::cout << "Wybierz przeciwnika." << std::endl;

    DisplayEnemies(listOfEnemies);

    std::cin >> enemyChoice;

    std::cout << "Wybrano gracza #" << listOfEnemies[enemyChoice-1].EnemyId << " " << listOfEnemies[enemyChoice-1].name << std::endl;

    return listOfEnemies[enemyChoice-1];
}
Item ChooseItem(std::vector<Item>& listOfItems)
{
    std::cout << "Wybierz numer przedmiotu." << std::endl;

    int playerChoice;

    std::cin >> playerChoice;
    
    return listOfItems[playerChoice-1];
}
void EquipItem(Player& player,Item& item)
{
    if(item.type == "Weapon")
    {
        int WeaponChoice;

        std::cout << "Czy chcesz uzywac tej broni jako pierwszorzednej czy drugorzednej?" << std::endl;
        std::cout << "1 - Pierwszorzedna" << std::endl;
        std::cout << "2 - Drugorzedna" << std::endl;

        std::cin >> WeaponChoice;

        player.equippedWeapons[WeaponChoice-1] = item;
        player.agility += item.agility;
        player.strenght += item.strenght;
        player.intelligence += item.intelligence;
        player.stamina += item.stamina;
        player.armor += item.armor;

    }
    else if(item.type == "Armor")
    {
        int ArmorChoice;

        std::cout << "Na co chcesz zalozyc ten przedmiot?" << std::endl;
        std::cout << "1 - Glowa" << std::endl;
        std::cout << "2 - Tors" << std::endl;
        std::cout << "3 - Rece" << std::endl;
        std::cout << "4 - Nogi" << std::endl;

        std::cin >> ArmorChoice;
        player.equippedArmor[ArmorChoice-1];
        player.agility += item.agility;
        player.strenght += item.strenght;
        player.intelligence += item.intelligence;
        player.stamina += item.stamina;
        player.armor += item.armor;
    }
    
}
void DisplayPlayers(std::vector<Player>& playerCharacters)
{
    int counter = 0;
    if(playerCharacters.empty())
    {
        std::cout << "Nie ma jeszcze postaci." << std::endl;
    }
    else
    {
        std::cout << "Lista postaci:" << std::endl;
        for(const Player player : playerCharacters)
        {
            counter++;
            std::cout << "#" << counter << " Imie: " << player.name << " Klasa: "<< player.playerClass << " Plec: " << player.gender << " Zdrowie: " << player.health << std::endl;
            std::cout << "S: " << player.strenght << " A: " << player.agility << " I: " << player.intelligence << " S: " << player.stamina << std::endl;
            std::cout << "" << std::endl;
            
        }
    }
}
Player ChooseCharacter(std::vector<Player>& playerCharacters)
{
    if(playerCharacters.empty())
    {
        std::cout << "Nie ma graczy do wybrania" << std::endl;
        return playerCharacters[0];
        
    }
    else
    {
        int playerChoice;

        std::cout << "Wybierz numer gracza." << std::endl;
        DisplayPlayers(playerCharacters);

        std::cin >> playerChoice;
        std::cout << "Wybrano gracza #" << playerCharacters[playerChoice-1].playerId << " " << playerCharacters[playerChoice-1].name << std::endl;
        return playerCharacters[playerChoice-1];
    }
}
void CheckInventory(Player& player)
{
    bool InventoryContinue = true;
    do
    {

    
    int counter = 1;
    std::cout << "****** TWOJ EKWIPUNEK ******" << std::endl;
    for(Item item : player.Inventory)
    {   
        std::cout << "#" << counter << " " << item.name << std::endl;
        counter++;
    }
    
    int choiceEquip;
    std::cout << "Czy chcesz zalozyc ktorys z przedmiotow?" << std::endl;
    std::cout << "1 - Tak" << std::endl;
    std::cout << "2 - Nie" << std::endl;
    std::cin >> choiceEquip;
    Item chosenItem;
    switch (choiceEquip)
    {
    case 1:

        chosenItem = ChooseItem(player.Inventory);
        EquipItem(player,chosenItem);

        break;
    case 2:
            std::cout << "Niewlasciwa opcja" << std::endl;
        break;
    
    default:
        std::cout << "Niewlasciwa opcja" << std::endl;
        break;
    }
    
    }while(InventoryContinue);
}
#endif