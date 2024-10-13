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
#endif