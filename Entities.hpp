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
        int currentHealth;
        int mana;
        int currentMana;
        std::vector<Item> Inventory;
        Item equippedWeapons[2];
        Item equippedArmor[4]; 
        bool alive = true;
        int speed;
        Character(std::string name,int strenght,int agility,int stamina,int intelligence,int armor,int health,int speed,bool alive,int currentMana)
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
            this->currentMana = currentMana;
        };
        Character();
};
class Player : public Character{
    public:
            std::string gender;
            std::string playerClass;
            int playerId;
            std::vector<Item> Inventory;
            Player(int playerId,std::string name,std::string playerClass,std::string gender,int strenght,int agility,int stamina,int intelligence,int armor,int health,int mana,bool alive,int currenHealth,int currentMana)
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
                this->currentHealth = currenHealth;
                this->currentMana = currentMana;
            }
            Player();
};
class Enemy : public Character
{
    public:
        int EnemyId;
         Enemy(int EnemyId,std::string name,int strenght,int agility,int stamina,int intelligence,int armor,int health,int mana,int speed,bool alive,int currentHealth,int currentMana)
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
                this->currentHealth = currentHealth;
                this->currentMana = currentMana;
            }
};
Player::Player()
{

}
Character::Character()
{

}
int RandomNumber(int number)
{
    int randomNum;
    srand(time(NULL));
    randomNum = (rand() % number) + 1;
    return randomNum;
}
void SpawnSkeletons(int randomNum,std::vector<Enemy>& listOfEnemies)
{
    
    for(int i = 0;i < randomNum;i++)
    {
        Enemy enemy(listOfEnemies.size() + 1,"Szkielet",2,4,4,1,2,50,30,2,true,50,30);
        listOfEnemies.push_back(enemy);
    }
    
}
void SpawnWolves(int randomNum,std::vector<Enemy>& listOfEnemies)
{
    
    for(int i = 0;i < randomNum;i++)
    {
        Enemy enemy(listOfEnemies.size() + 1,"Wilk",1,4,4,1,0,30,0,2,2,true,30);
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
        std::cout << "#" << enemy.EnemyId << " " << enemy.name << " HP: " << enemy.currentHealth << "/"<< enemy.health << std::endl;
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
bool Dodge(Player& player)
{
    int dodgeValue = player.agility + 5;
    std::cout << "UNIK: " << dodgeValue << std::endl;
    int random = RandomNumber(100);
    if(dodgeValue >= random)
    {
        std::cout << " SZANSA NA TRAFIENIE PULAKI: " << random << std::endl;
        return true;
    }
    else if ( dodgeValue <= random)
    {
        std::cout << random << std::endl;
        return false;
    }
    return false;
}
void DisplayCurrentHealth(Player& player)
{
    std::cout << "Twoje zdrowie wynosi teraz: " << player.currentHealth << "/" << player.health << std::endl;
}
void DisplayCurrentHealth(Enemy& enemy)
{
    if(enemy.currentHealth < 0)
    {
        enemy.currentHealth = 0;
        std::cout << "Zdrowie przciwnika wynosi: " << enemy.currentHealth << "/" << enemy.health << std::endl;
    }
    else
    {
        std::cout << "Zdrowie przciwnika wynosi: " << enemy.currentHealth << "/" << enemy.health << std::endl;
    }
    
}
void UnEquip(Player& player,Item& item)
{

        player.agility -= item.agility;
        player.strenght -= item.strenght;
        player.intelligence -= item.intelligence;
        player.stamina -= item.stamina;
        player.armor -= item.armor;

        int newHealth = player.stamina * 10;
        player.health = newHealth;

        int newMana = player.intelligence * 10;
        player.mana = newMana;
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

        
        std::cout << "SILA" << player.equippedWeapons[WeaponChoice-1].strenght << std::endl;
        std::cout << "NAZWA" << player.equippedWeapons[WeaponChoice-1].name << std::endl;

        //zabezpieczenie przed odjeciem 
        if(player.equippedWeapons[WeaponChoice-1].name != "")
        {
            UnEquip(player,player.equippedWeapons[WeaponChoice-1]);
        }

        player.equippedWeapons[WeaponChoice-1] = item;
        player.agility += item.agility;
        player.strenght += item.strenght;
        player.intelligence += item.intelligence;
        player.stamina += item.stamina;
        player.armor += item.armor;

        int newHealth = player.stamina * 10;
        player.health =  newHealth;

        int newMana = player.intelligence * 10;
        player.mana = newMana;
        
        if(item.stamina > 0)
        {
            player.currentHealth += item.stamina * 10;
        }
        
        
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

        if(player.equippedArmor[ArmorChoice-1].name != "")
        {
            UnEquip(player,player.equippedArmor[ArmorChoice-1]);
        }
        player.equippedArmor[ArmorChoice-1] = item;
        player.agility += item.agility;
        player.strenght += item.strenght;
        player.intelligence += item.intelligence;
        player.stamina += item.stamina;
        player.armor += item.armor;

        int newHealth = player.stamina * 10;
        player.health = newHealth;

        int newMana = player.intelligence * 10;
        player.mana = newMana;

        if(item.stamina > 0)
        {
            player.currentHealth += item.stamina * 10;
        }
    }
    
}
void CheckInventory(Player& player)
{
    int actionChoice;
    Item chosenItem;
    bool InventoryContinue = true;
    while(InventoryContinue)
    {
    std::cout << "****** TWOJ STATYSTYKI ******" << std::endl;
    std::cout << "|Nazwa gracza: " << player.name << std::endl;
    std::cout << "|Zdrowie maksymalne: " << player.health << std::endl;
    std::cout << "|Zdrowie aktualne: " << player.currentHealth << std::endl;
    std::cout << "|Mana: " << player.mana << std::endl;
    std::cout << "|Sila: " << player.strenght << std::endl;
    std::cout << "|Zrecznosc: " << player.agility << std::endl;
    std::cout << "|Inteligencja: " << player.intelligence << std::endl;
    std::cout << "|Pancerz: " << player.armor << std::endl;
    std::cout << "|Zloto: " << std::endl;

    int counter = 1;

    std::cout << "****** TWOJ EKWIPUNEK ******" << std::endl;

    for(Item item : player.Inventory)
    {   
        std::cout << "|#" << counter << " " << item.name << std::endl;
        counter++;
    }

    std::cout << "1 - Sprawdz przedmiot  2 - Zaloz przedmiot  3 - Sprawdz noszony ekwipunek 4 - Wyjdz z ekwipunku" << std::endl;

    std::cin >> actionChoice;
    

        
   
    switch (actionChoice)
    {
    case 1:

        chosenItem = ChooseItem(player.Inventory);
        std::cout << chosenItem.name << " Sila: " << chosenItem.strenght << " Zrecznosc: " << chosenItem.agility << " Wytrzymalosc: " << chosenItem.stamina << " Inteligencja: " << chosenItem.intelligence << std::endl;
        std::cout << "" << std::endl;
        
    break;
    case 2:
        chosenItem = ChooseItem(player.Inventory);
        EquipItem(player,chosenItem);
    break;
    case 3:
        std::cout << " ****** NOSZONY EKWIPUNEK ******" << std::endl;
        std::cout << " |Bron pierwszorzedna: " << player.equippedWeapons[0].name << std::endl;
        std::cout << " |Bron Drugorzedna: " << player.equippedWeapons[1].name << std::endl;
        std::cout << " |Glowa: " << player.equippedArmor[0].name << std::endl;
        std::cout << " |Tors: " << player.equippedArmor[1].name << std::endl;
        std::cout << " |Rece: " << player.equippedArmor[2].name << std::endl;
        std::cout << " |Noga: " << player.equippedArmor[3].name << std::endl;
    break;
    case 4:
        InventoryContinue = false;
    break;
    default:
        std::cout << "Niewlasciwa opcja" << std::endl;
    break;
    }
    }
}
#endif