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
        Weapon(std::string name,int strenght,int agility,int stamina,int intelligence,int cost)
        {
            this->name = name;
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
         Armor(std::string name,int armor,int strenght,int agility,int stamina,int intelligence,int cost)
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
Weapon GetWeapon()
{
    srand(time(NULL));
    int random = (rand() % 8) + 1;
    switch (random)
    {
    case 1:
            return  Weapon("Krotki miecz",2,1,1,0,1);
            
        break;
    case 2:
            return  Weapon("Maczuga",3,0,1,0,1);
            
        break;
    case 3:
            return Weapon("Sztylet",2,2,0,0,1);
             
        break;
    case 4:
            return Weapon("Krotki miecz",2,2,0,0,1);
            
        break;
    case 5:
            return Weapon("Miecz Dlugi",4,0,1,0,2);
            
        break;
    case 6:
            return Weapon("Krotki miecz",1,0,1,4,1);
            
        break;
    case 7:
            return Weapon("Wojenny topor",5,0,0,0,2);
            
        break;
    case 8:
            return Weapon("Kusza",3,0,3,0,2);
            
        break;
    
    }
}
Armor GetAromor()
{
    srand(time(NULL));
    int random = (rand() % 8) + 1;

    switch (random)
    {
    case 1:
            return Armor("Szaty",1,0,0,1,3,1);
            
        break;
    case 2:
            return Armor("Skorzana zbroja",2,0,3,2,0,1);
            
        break;
    case 3:
            return Armor("Kolczuga",3,3,0,2,0,1);
            
        break;
    case 4:
            return Armor("Zbroja plytowa",4,3,0,4,0,1);
            
        break;
    case 5:
            return Armor("Kaptur",1,0,1,1,0,1);
            
        break;
    case 6:
            return Armor("Zelazny chelm",2,2,0,0,0,1);
           
        break;
    case 7:
            return Armor("Kapelusz czarodzieja",1,0,0,1,2,1);
            
        break;
    case 8:
            return Armor("Buty",1,1,1,1,1,1);
            
        break;
    
    }
}
#endif