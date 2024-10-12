#ifndef GAME_HPP
#define GAME_HPP
#include <string>

class Player;
class Character{
    public:
        std::string name;
        int strenght;
        int agility;
        int stamina;
        int intelligence;
        int armor;
        int health;
        int mana;
        bool alive = true;
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
//konstruktory
Player::Player()
{
}

Character::Character()
{
}
#endif