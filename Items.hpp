#ifndef WEAPONS_HPP
#define WEAPONS_HPP
#include <iostream>

class Item
{
    public:
        std::string name;
        int cost;
    

};
class Weapon : public Item
{
    public:
        int damage;
        int strenght;
        int agility;
        int stamina;
        int intelligence;
        Weapon(std::string name,int damage,int strenght,int agility,int stamina,int intelligence)
        {
            this->name = name;
            this->damage = damage;
            this->strenght = strenght;
            this->agility = agility;
            this->stamina = stamina;
            this->intelligence = intelligence;
            this->cost = cost;
        }

};
class Armor : public Item
{
    public:
        int armor;
        int strenght;
        int agility;
        int stamina;
        int intelligence;
         Armor(std::string name,int damage,int strenght,int agility,int stamina,int intelligence)
        {
            this->name = name;
            this->armor = armor;
            this->strenght = strenght;
            this->agility = agility;
            this->stamina = stamina;
            this->intelligence = intelligence;
            this->cost = cost;
        }
};
#endif