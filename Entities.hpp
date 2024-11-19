#ifndef ENTITIES_HPP
#define ENTITIES_HPP
#include <string>
#include "Items.hpp"
#include <iostream>
#include <ctime>
#include <vector>


bool Wolfdodge = false;
bool warriorBlock = false;
bool barbarianRage = false;
int warriorblockCounter = 0;

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
        int gold;
        int speed;
        bool poisoned = false;
        bool bleed = false;
        bool stun = false;
        Character(std::string name,int strenght,int agility,int stamina,int intelligence,int armor,int health,int speed,bool alive,int currentMana,int gold)
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
            this->gold = gold;
        };
        Character();
};
class Player : public Character{
    public:
            std::string gender;
            std::string playerClass;
            int playerId;
            std::vector<Item> Inventory;
            int Level = 1;
            int experience = 0;
            Player(int playerId,std::string name,std::string playerClass,std::string gender,int strenght,int agility,int stamina,int intelligence,int armor,int health,int mana,bool alive,int currenHealth,int currentMana,int gold)
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
                this->gold = gold;
            }
            Player();
           void levelUp()
           {
            if(playerClass == "Wojownik")
            {
                Level++;
                strenght += 2;
                agility += 1;
                stamina += 2;
                intelligence += 1;

                int newHealth = stamina * 10;
                health =  newHealth;

                int newMana = intelligence * 10;
                mana = newMana;
            }
            else if(playerClass == "Mag")
            {
                Level++;
                strenght += 1;
                agility += 1;
                stamina += 1;
                intelligence += 3;

                int newHealth = stamina * 10;
                health =  newHealth;

                int newMana = intelligence * 10;
                mana = newMana;
            }
            else if(playerClass == "Lotr")
            {
                Level++;
                strenght += 1;
                agility += 3;
                stamina += 1;
                intelligence += 1;

                int newHealth = stamina * 10;
                health =  newHealth;

                int newMana = intelligence * 10;
                mana = newMana;
            }
            else if(playerClass == "Berserker")
            {
                Level++;
                strenght += 3;
                agility += 1;
                stamina += 1;
                intelligence += 2;

                int newHealth = stamina * 10;
                health =  newHealth;

                int newMana = intelligence * 10;
                mana = newMana;
            }
            else if(playerClass == "Nekromanta")
            {
                Level++;
                strenght += 1;
                agility += 1;
                stamina += 2;
                intelligence += 2;

                int newHealth = stamina * 10;
                health =  newHealth;

                int newMana = intelligence * 10;
                mana = newMana;
            }
            else if(playerClass == "Lowczy")
            {
                Level++;
                strenght += 2;
                agility += 2;
                stamina += 1;
                intelligence += 1;

                int newHealth = stamina * 10;
                health =  newHealth;

                int newMana = intelligence * 10;
                mana = newMana;
            }
           }
           void PlayerGiveExperience(int value)
           {    
                experience += value;
           }
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
void strongAttackEnemy(Player& player,Enemy& enemy);
bool MagicalCriticalStrike(Enemy& enemy);
bool MagicalCriticalStrike(Player& player);
bool CriticalStrike(Player& player);
bool CriticalStrike(Enemy& enemy);
void hardeningEnemy(Enemy& enemy);
void fireBallEnemy(Player& player,Enemy& enemy);
bool dodgeNext(Enemy& enemy);
int RandomNumber(int number)
{
    int randomNum;
    randomNum = (rand() % number) + 1;
    return randomNum;
}
void SpawnSkeletons(int randomNum,std::vector<Enemy>& listOfEnemies)
{
    
    for(int i = 0;i < randomNum;i++)
    {
        Enemy enemy(listOfEnemies.size() + 1,"Szkielet",3,4,4,1,2,50,30,2,true,50,30);
        listOfEnemies.push_back(enemy);
    }
    
}
void SpawnBear(int randomNum,std::vector<Enemy>& listOfEnemies)
{
    
    for(int i = 0;i < randomNum;i++)
    {
        Enemy enemy(listOfEnemies.size() + 1,"Niedzwiedz",10,5,6,1,3,70,30,2,true,70,30);
        listOfEnemies.push_back(enemy);
    }
    
}
void SpawnBoars(int randomNum,std::vector<Enemy>& listOfEnemies)
{
    
    for(int i = 0;i < randomNum;i++)
    {
        Enemy enemy(listOfEnemies.size() + 1,"Dzik",4,9,4,1,2,35,30,2,true,35,30);
        listOfEnemies.push_back(enemy);
    }
    
}
void SpawnBandits(int randomNum,std::vector<Enemy>& listOfEnemies)
{
    
    for(int i = 0;i < randomNum;i++)
    {
        Enemy enemy(listOfEnemies.size() + 1,"Bandyta",6,6,6,2,3,40,30,2,true,40,30);
        listOfEnemies.push_back(enemy);
    }
    
}
void SpawnForestGhost(int randomNum,std::vector<Enemy>& listOfEnemies)
{
    
    for(int i = 0;i < randomNum;i++)
    {
        Enemy enemy(listOfEnemies.size() + 1,"Duch lasu",3,4,4,1,2,50,40,2,true,50,40);
        listOfEnemies.push_back(enemy);
    }
    
}
void SpawnMage(int randomNum,std::vector<Enemy>& listOfEnemies)
{
    for(int i = 0;i < randomNum;i++)
    {
         Enemy enemy(listOfEnemies.size() + 1,"Szkielet Mag",4,4,4,8,3,30,30,2,true,30,30);
         listOfEnemies.push_back(enemy);
    }
   
}
void SpawnWolves(int randomNum,std::vector<Enemy>& listOfEnemies)
{
    
    for(int i = 0;i < randomNum;i++)
    {
        Enemy enemy(listOfEnemies.size() + 1,"Wilk",2,7,4,1,0,20,20,6,true,20,20);
        listOfEnemies.push_back(enemy);
    }
    
}
void SpawnWarriorSkeleton(std::vector<Enemy>& listOfEnemies)
{
    Enemy enemy(listOfEnemies.size() + 1,"Szkielet wojownik",6,4,6,1,4,70,30,3,true,70,20);
    listOfEnemies.push_back(enemy);
}
void AnnounceEnemies(std::vector<Enemy>& listOfEnemies)
{
    if(listOfEnemies.size() > 1)
    {
        std::cout << "Przed toba pojawila sie grupa " << listOfEnemies[0].name << "ow"<< std::endl;
    }
    else if(listOfEnemies.size() == 1)
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
    
    while(true)
    {
        std::cout << "Wybierz przeciwnika." << std::endl;

        DisplayEnemies(listOfEnemies);
    
        std::cin >> enemyChoice;
        
            if(enemyChoice > 0 && enemyChoice <= listOfEnemies.size())
            {
                std::cout << "Wybrano gracza #" << listOfEnemies[enemyChoice-1].EnemyId << " " << listOfEnemies[enemyChoice-1].name << std::endl;
                return listOfEnemies[enemyChoice-1];
                break;
            }
            else
            {
                std::cout << "Nieprawidlowy numer przeciwnika!" << std::endl;
            }
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
        std::cout << "-------------------------------------------------------------" << std::endl;
        std::cout << "|Lista postaci:" << std::endl;
        for(const Player player : playerCharacters)
        {
            counter++;
            std::cout << "|#" << counter << " Imie: " << player.name << " Klasa: "<< player.playerClass << " Plec: " << player.gender << " Zdrowie: " << player.health << std::endl;
            std::cout << "|Sila: " << player.strenght << " Zrecznosc: " << player.agility << " Inteligecja: " << player.intelligence << " Stamina: " << player.stamina << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
            
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
        std::cout << "__________________________________" << std::endl;
        std::cout << "1 - Pierwszorzedna 2 - Drugorzedna" << std::endl;
        std::cout << "" << std::endl;

        std::cin >> WeaponChoice;

        //zabezpieczenie przed odjeciem 
        if(player.equippedWeapons[WeaponChoice-1].name != "")
        {
            
            UnEquip(player,player.equippedWeapons[WeaponChoice-1]);
            player.Inventory.push_back(player.equippedWeapons[WeaponChoice-1]);
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
       
        for(int i = 0;i <= player.Inventory.size();i++)
        {
            if(player.Inventory[i].name == item.name)
            {
                player.Inventory.erase(player.Inventory.begin() + i);
                break;
            }
        }
        
    }
    else if(item.type == "Armor")
    {
        int ArmorChoice;

        std::cout << "Na co chcesz zalozyc ten przedmiot?" << std::endl;
        std::cout << "__________" << std::endl;
        std::cout << "|1 - Glowa" << std::endl;
        std::cout << "|2 - Tors" << std::endl;
        std::cout << "|3 - Rece" << std::endl;
        std::cout << "|4 - Nogi" << std::endl;

        std::cin >> ArmorChoice;

        if(player.equippedArmor[ArmorChoice-1].name != "")
        {
            UnEquip(player,player.equippedArmor[ArmorChoice-1]);
            player.Inventory.push_back(player.equippedArmor[ArmorChoice-1]);
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
        for(int i = 0;i <= player.Inventory.size();i++)
        {
            if(player.Inventory[i].name == item.name)
            {
                player.Inventory.erase(player.Inventory.begin() + i);
                break;
            }
        }
    }
    
}
void UseHealingPotion(Item item,Player& player)
{
    
    if(player.health - player.currentHealth < 12)
    {
        player.currentHealth += player.health - player.currentHealth;
    }
    else
    {
        player.currentHealth += 12;
    }
    
    for(int i = 0;i <= player.Inventory.size();i++)
    {
        if(player.Inventory[i].type == "Mikstura Leczaca")
        {
            player.Inventory.erase(player.Inventory.begin() + i);
            break;
        }
    }
}
void UseManaPotion(Item item,Player& player)
{
    
    if(player.mana- player.currentMana < 10)
    {
        player.currentMana += player.mana- player.currentMana;
    }
    else
    {
        player.currentMana += 10;
    }
    
    for(int i = 0;i <= player.Inventory.size();i++)
    {
        if(player.Inventory[i].type == "Mikstura Many")
        {
            player.Inventory.erase(player.Inventory.begin() + i);
            break;
        }
    }
}
void CheckInventory(Player& player)
{
    int actionChoice;
    Item chosenItem;
    bool InventoryContinue = true;
    int potionUse;
    while(InventoryContinue)
    {

    std::cout << "****** TWOJE STATYSTYKI ******" << std::endl;
    std::cout << "|Nazwa gracza: " << player.name << std::endl;
    std::cout << "|Zdrowie : " << player.currentHealth << "/" << player.health << std::endl;
    std::cout << "|Mana : " << player.currentMana << "/" << player.mana << std::endl;
    std::cout << "|Sila: " << player.strenght << std::endl;
    std::cout << "|Zrecznosc: " << player.agility << std::endl;
    std::cout << "|Inteligencja: " << player.intelligence << std::endl;
    std::cout << "|Pancerz: " << player.armor << std::endl;
    std::cout << "|Zloto: " << player.gold << std::endl;

    int counter = 1;

    std::cout << "****** TWOJ EKWIPUNEK ******" << std::endl;

    for(Item item : player.Inventory)
    {   
        std::cout << "|#" << counter << " " << item.name << std::endl;
        counter++;
    }
    std::cout << "_______________________________________________________________________________________________" << std::endl;
    std::cout << "1 - Sprawdz przedmiot  2 - Zaloz przedmiot  3 - Sprawdz noszony ekwipunek 4 - Wyjdz z ekwipunku" << std::endl;

    std::cin >> actionChoice;
    
    switch (actionChoice)
    {
    case 1:

        chosenItem = ChooseItem(player.Inventory);
        if(chosenItem.type == "Mikstura Leczaca")
        {
            std::cout << chosenItem.name << std::endl;
            std::cout << "1 - Uzyj 2 - Odloz" << std::endl;
            std::cin >> potionUse;
            std::cout << "" << std::endl;
            switch (potionUse)
            {
            case 1:
                UseHealingPotion(chosenItem,player);
                break;
            case 2:
                
                break;
            default:
                std::cout << "Niepoprawna opcja" << std::endl;
                break;
            }
        }
        else if(chosenItem.type == "Mikstura Many")
        {
            std::cout << chosenItem.name << std::endl;
            std::cout << "1 - Uzyj 2 - Odloz" << std::endl;
            std::cin >> potionUse;
            std::cout << "" << std::endl;
            switch (potionUse)
            {
            case 1:
                UseManaPotion(chosenItem,player);
                break;
            case 2:
                
                break;
            default:
                std::cout << "Niepoprawna opcja" << std::endl;
                break;
            }
        }
        else
        {
            std::cout << chosenItem.name << " Sila: " << chosenItem.strenght << " Zrecznosc: " << chosenItem.agility << " Wytrzymalosc: " << chosenItem.stamina << " Inteligencja: " << chosenItem.intelligence << std::endl;
            std::cout << "" << std::endl;
        }
        
        
    break;
    case 2:
        chosenItem = ChooseItem(player.Inventory);
        EquipItem(player,chosenItem);
    break;
    case 3:
        std::cout << " ****** NOSZONY EKWIPUNEK ******" << std::endl;
        std::cout << "|Bron pierwszorzedna: " << player.equippedWeapons[0].name << std::endl;
        std::cout << "|Bron Drugorzedna: " << player.equippedWeapons[1].name << std::endl;
        std::cout << "|Glowa: " << player.equippedArmor[0].name << std::endl;
        std::cout << "|Tors: " << player.equippedArmor[1].name << std::endl;
        std::cout << "|Rece: " << player.equippedArmor[2].name << std::endl;
        std::cout << "|Noga: " << player.equippedArmor[3].name << std::endl;
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
void ShowStats(Player& player)
{   
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "|Twoje zdrowie: " << player.currentHealth << "/" << player.health << std::endl;
    std::cout << "|Twoja Mana: " << player.currentMana << "/" << player.mana << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
}
void ActionBear(Player& player,Enemy& enemy,bool& warriorBlock,int& warriorblockCounter)
{
    bool endOfHardnening = false;
    int random = RandomNumber(30);
    if (random >= 0 && random < 10)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        if(CriticalStrike(enemy))
        {
           if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
                warriorBlock = false;
            }
            else
            {
                int damage = 2 * (1 + enemy.strenght) - player.armor;
                std::cout << "------------------------------" << std::endl;
                std::cout << "|ATAK KRYTYCZNY PRZECIWNIKA: " << damage << std::endl;
                std::cout << "------------------------------" << std::endl;
                player.currentHealth -= damage;
            }
        }
        else
        {
           if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
                
            }
            else
            {
                int damage = (1 + enemy.strenght) - player.armor;
                std::cout << "-------------------" << std::endl;
                std::cout << "|ATAK PRZECIWNIKA: " << damage << std::endl;
                std::cout << "-------------------" << std::endl;
                player.currentHealth -= damage;
            }
        }

        DisplayCurrentHealth(player);
    }
    else if (random >= 20 && random <= 30)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        if(warriorBlock)
        {
            std::cout << "----------------" << std::endl;
            std::cout << "|BLOKUJESZ ATAK" << std::endl;
            std::cout << "----------------" << std::endl;
            warriorblockCounter++;
            
        }
        else
        {
            strongAttackEnemy(player,enemy);
        }
       
    }
    else if(random >= 10 && random < 20)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        hardeningEnemy(enemy);
    }
}
void ActionBoar(Player& player,Enemy& enemy,bool& warriorBlock,int& warriorblockCounter)
{
      bool endOfHardnening = false;
    int random = RandomNumber(30);
    if (random >= 0 && random < 10)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        if(CriticalStrike(enemy))
        {
           if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
                warriorBlock = false;
            }
            else
            {
                int damage = 2 * (1 + enemy.strenght) - player.armor;
                std::cout << "------------------------------" << std::endl;
                std::cout << "|ATAK KRYTYCZNY PRZECIWNIKA: " << damage << std::endl;
                std::cout << "------------------------------" << std::endl;
                player.currentHealth -= damage;
            }
        }
        else
        {
           if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
                
            }
            else
            {
                int damage = (1 + enemy.strenght) - player.armor;
                std::cout << "-------------------" << std::endl;
                std::cout << "|ATAK PRZECIWNIKA: " << damage << std::endl;
                std::cout << "-------------------" << std::endl;
                player.currentHealth -= damage;
            }
        }

        DisplayCurrentHealth(player);
    }
    else if (random >= 20 && random <= 30)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        if(warriorBlock)
        {
            std::cout << "----------------" << std::endl;
            std::cout << "|BLOKUJESZ ATAK" << std::endl;
            std::cout << "----------------" << std::endl;
            warriorblockCounter++;
            
        }
        else
        {
            strongAttackEnemy(player,enemy);
        }
       
    }
    else if(random >= 10 && random < 20)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        hardeningEnemy(enemy);
    }
}
void ActionForestGhost(Player& player,Enemy& enemy,bool& warriorBlock,int& warriorBlockCounter)
{
    int random = RandomNumber(30);
    if (random >= 0 && random < 20)
    {
        if(CriticalStrike(enemy))
        {   
            if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
                warriorBlock = false;
            }
            else
            {
                int damage = 2 * (1 + enemy.strenght) - player.armor;
                std::cout << "------------------------------" << std::endl;
                std::cout << "|ATAK KRYTYCZNY PRZECIWNIKA: " << damage << std::endl;
                std::cout << "------------------------------" << std::endl;
                player.currentHealth -= damage;
            }
            
        }
        else
        {
            if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
                warriorBlock = false;
            }
            else
            {
                int damage = (1 + enemy.strenght) - player.armor;
                std::cout << "-------------------" << std::endl;
                std::cout << "|ATAK PRZECIWNIKA: " << damage << std::endl;
                std::cout << "-------------------" << std::endl;
                player.currentHealth -= damage;
            }
        }

        DisplayCurrentHealth(player);
    }
    else if (random >= 20 && random <= 30)
    {
        fireBallEnemy(player,enemy);
    }
}
void ActionBandit(Player& player,Enemy& enemy,bool& warriorBlock,int& warriorblockCounter)
{
      bool endOfHardnening = false;
    int random = RandomNumber(30);
    if (random >= 0 && random < 10)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        if(CriticalStrike(enemy))
        {
           if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
                warriorBlock = false;
            }
            else
            {
                int damage = 2 * (1 + enemy.strenght) - player.armor;
                std::cout << "------------------------------" << std::endl;
                std::cout << "|ATAK KRYTYCZNY PRZECIWNIKA: " << damage << std::endl;
                std::cout << "------------------------------" << std::endl;
                player.currentHealth -= damage;
            }
        }
        else
        {
           if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
                
            }
            else
            {
                int damage = (1 + enemy.strenght) - player.armor;
                std::cout << "-------------------" << std::endl;
                std::cout << "|ATAK PRZECIWNIKA: " << damage << std::endl;
                std::cout << "-------------------" << std::endl;
                player.currentHealth -= damage;
            }
        }

        DisplayCurrentHealth(player);
    }
    else if (random >= 20 && random <= 30)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        if(warriorBlock)
        {
            std::cout << "----------------" << std::endl;
            std::cout << "|BLOKUJESZ ATAK" << std::endl;
            std::cout << "----------------" << std::endl;
            warriorblockCounter++;
            
        }
        else
        {
            strongAttackEnemy(player,enemy);
        }
       
    }
    else if(random >= 10 && random < 20)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        hardeningEnemy(enemy);
    }
}
void ActionMage(Player& player,Enemy& enemy,bool& warriorBlock,int& warriorBlockCounter)
{
    int random = RandomNumber(30);
    if (random >= 0 && random < 20)
    {
        if(CriticalStrike(enemy))
        {   
            if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
                warriorBlock = false;
            }
            else
            {
                int damage = 2 * (1 + enemy.strenght) - player.armor;
                std::cout << "------------------------------" << std::endl;
                std::cout << "|ATAK KRYTYCZNY PRZECIWNIKA: " << damage << std::endl;
                std::cout << "------------------------------" << std::endl;
                player.currentHealth -= damage;
            }
            
        }
        else
        {
            if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
                warriorBlock = false;
            }
            else
            {
                int damage = (1 + enemy.strenght) - player.armor;
                std::cout << "-------------------" << std::endl;
                std::cout << "|ATAK PRZECIWNIKA: " << damage << std::endl;
                std::cout << "-------------------" << std::endl;
                player.currentHealth -= damage;
            }
        }

        DisplayCurrentHealth(player);
    }
    else if (random >= 20 && random <= 30)
    {
        fireBallEnemy(player,enemy);
    }

}
void ActionSkeletonWarrior(Player& player,Enemy& enemy,bool& warriorBlock,int& warriorblockCounter)
{
    bool endOfHardnening = false;
    int random = RandomNumber(30);
    if (random >= 0 && random < 10)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        if(CriticalStrike(enemy))
        {
           if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
                warriorBlock = false;
            }
            else
            {
                int damage = 2 * (1 + enemy.strenght) - player.armor;
                std::cout << "------------------------------" << std::endl;
                std::cout << "|ATAK KRYTYCZNY PRZECIWNIKA: " << damage << std::endl;
                std::cout << "------------------------------" << std::endl;
                player.currentHealth -= damage;
            }
        }
        else
        {
           if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
                
            }
            else
            {
                int damage = (1 + enemy.strenght) - player.armor;
                std::cout << "-------------------" << std::endl;
                std::cout << "|ATAK PRZECIWNIKA: " << damage << std::endl;
                std::cout << "-------------------" << std::endl;
                player.currentHealth -= damage;
            }
        }

        DisplayCurrentHealth(player);
    }
    else if (random >= 20 && random <= 30)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        if(warriorBlock)
        {
            std::cout << "----------------" << std::endl;
            std::cout << "|BLOKUJESZ ATAK" << std::endl;
            std::cout << "----------------" << std::endl;
            warriorblockCounter++;
            
        }
        else
        {
            strongAttackEnemy(player,enemy);
        }
       
    }
    else if(random >= 10 && random < 20)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        hardeningEnemy(enemy);
    }
}
void ActionWolf(Player& player,Enemy& enemy,bool& warriorBlock,int& warriorblockCounter)
{
    int random = RandomNumber(30);
    if (random >= 0 && random < 20)
    {
        if(CriticalStrike(enemy))
        {
            if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
                Wolfdodge = false;
            }
            else
            {
                int damage = 2 * (1 + enemy.strenght) - player.armor;
                std::cout << "------------------------------" << std::endl;
                std::cout << "|ATAK KRYTYCZNY PRZECIWNIKA: " << damage << std::endl;
                std::cout << "------------------------------" << std::endl;
                player.currentHealth -= damage;
                Wolfdodge = false;
            }
            
        }
        else if(!CriticalStrike(enemy))
        {
            if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "------------------------------" << std::endl;
                warriorblockCounter++;
                Wolfdodge = false;
            }
            else
            {
                int damage = (1 + enemy.strenght) - player.armor;
                std::cout << "-------------------" << std::endl;
                std::cout << "|ATAK PRZECIWNIKA: " << damage << std::endl;
                std::cout << "-------------------" << std::endl;
                player.currentHealth -= damage;
                Wolfdodge = !Wolfdodge;
            }
        }

        DisplayCurrentHealth(player);
    }
    else if (random >= 20 && random <= 30)
    {
        Wolfdodge = dodgeNext(enemy);
    }

}
void EnemyAttack(Player& player,Enemy& enemy,bool& warriorBlock,int& warriorblockCounter)
{
    
    if(CriticalStrike(enemy))
    {
        if(warriorBlock)
            {
                std::cout << "----------------" << std::endl;
                std::cout << "|BLOKUJESZ ATAK" << std::endl;
                std::cout << "----------------" << std::endl;
                warriorblockCounter++;
            }
            else
            {
                int damage = 2 * (1 + enemy.strenght) - player.armor;
                std::cout << "------------------------------" << std::endl;
                std::cout << "|ATAK KRYTYCZNY PRZECIWNIKA: " << damage << std::endl;
                std::cout << "------------------------------" << std::endl;
                player.currentHealth -= damage;
            }
    }
    else if(!CriticalStrike(enemy))
    {
       if(warriorBlock)
        {
            std::cout << "----------------" << std::endl;
            std::cout << "|BLOKUJESZ ATAK" << std::endl;
            std::cout << "----------------" << std::endl;
            warriorblockCounter++;
        }
        else
        {
            int damage = (1 + enemy.strenght) - player.armor;
            std::cout << "-------------------" << std::endl;
            std::cout << "|ATAK PRZECIWNIKA: " << damage << std::endl;
            std::cout << "-------------------" << std::endl;
            player.currentHealth -= damage;
            
        }
    }

    DisplayCurrentHealth(player);
}
void Attack(Player& player,Enemy& enemy)
{
    
    if(!CriticalStrike(player))
    {
        if(Wolfdodge)
        {
            std::cout << "----------------" << std::endl;
            std::cout << "UNIK PRZECIWNIKA" << std::endl;
            std::cout << "----------------" << std::endl;
            Wolfdodge = false;
        }
        else
        {
            int damage = (1 + player.strenght) - enemy.armor;
            std::cout << "----------------" << std::endl;
            std::cout << "NORMALNY ATAK: " << damage << std::endl;
            std::cout << "----------------" << std::endl;
            enemy.currentHealth -= damage;
        }
        
    }
    else if(CriticalStrike(player))
    {
        if(Wolfdodge)
        {
            std::cout << "----------------" << std::endl;
            std::cout << "UNIK PRZECIWNIKA" << std::endl;
            std::cout << "----------------" << std::endl;
            Wolfdodge = false;
        }
        else
        {
             int damage = 2 * (1 + player.strenght) - enemy.armor;
            std::cout << "----------------------" << std::endl;
            std::cout << "TRAFIENIE KRYTYCZNE: " << damage << std::endl;
            std::cout << "----------------------" << std::endl;
            enemy.currentHealth -= damage;
        }
       
    }

    DisplayCurrentHealth(enemy);

}
#endif