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

};
class Aromor : public Item
{
    public:
        int armor;
        int strenght;
        int agility;
        int stamina;
        int intelligence;
};
#endif