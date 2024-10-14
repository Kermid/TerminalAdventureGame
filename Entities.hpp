#ifndef ENTITIES_HPP
#define ENTITIES_HPP
#include <string>
#include "Entities.hpp"
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
        bool alive = true;
        int Inventory[4][4];
        Character(std::string name,int strenght,int agility,int stamina,int intelligence,int armor,int health,bool alive)
        {
            this->name = name;
            this->strenght = strenght;
            this->agility = agility;
            this->stamina = stamina;
            this->intelligence = intelligence;
            this->armor = armor;
            this->health = health;
            this->alive = alive;
        }
        Character();
};
class Player : public Character{
    public:
            std::string gender;
            std::string playerClass;
            int playerId;
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
         Enemy(int EnemyId,std::string name,int strenght,int agility,int stamina,int intelligence,int armor,int health,int mana,bool alive)
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
                this->alive = alive;
            }
};
Player::Player()
{

}
Character::Character()
{

}
int RandomNum()
{
    int randomNum;
    srand(time(NULL));
    randomNum = rand() % 3;
    return randomNum;
}
void SpawnEnemy(int randomNum,std::vector<Enemy>& listOfEnemies)
{
    int id = 0;
    for(int i = 0;i <= randomNum;i++)
    {
        id++;
        Enemy enemy(id,"Szkielet",4,4,4,1,1,50,0,true);
        listOfEnemies.push_back(enemy);
    }
    
}
void DisplayEnemies(std::vector<Enemy>& listOfEnemies)
{
    for(Enemy enemy : listOfEnemies)
    {
        std::cout << "#" << enemy.EnemyId << " HP: " << enemy.health << std::endl;
    }
}
Enemy ChooseEnemy(std::vector<Enemy>& listOfEnemies)
{
    int enemyChoice;
    std::cout << "Wybierz przeciwnika." << std::endl;
    DisplayEnemies(listOfEnemies);
    std::cin >> enemyChoice;
    std::cout << "Wybrano gracza #" << listOfEnemies[enemyChoice-1].playerId << " " << listOfEnemies[enemyChoice-1].name << std::endl;

    return listOfEnemies[1];
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
#endif