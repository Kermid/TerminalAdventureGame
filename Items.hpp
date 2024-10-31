#ifndef ITEMS_HPP
#define ITEMS_HPP
#include <iostream>
#include <vector>



class Item
{
    public:
        std::string name;
        int armor;
        int damage;
        int strenght;
        int agility;
        int stamina;
        int intelligence;
        int cost;
        std::string type;
        Item(std::string name,int armor,int damage,int strenght,int agility,int stamina,int intelligence,int cost,std::string type)
        {
            this->name = name;
            this->armor = armor;
            this->damage = damage;
            this->strenght = strenght;
            this->agility = agility;
            this->stamina = stamina;
            this->intelligence = intelligence;
            this->cost = cost;
            this->type = type;
        };
        Item() : name(""), strenght(0), agility(0), stamina(0), intelligence(0), armor(0), type("") {};
        Item(std::string name,int cost)
        {
            this->name = name;
            this->cost = cost;
            if(name == "Mikstura Leczaca")
            {
                type = "Mikstura Leczaca";
            }
            else if(name == "Mikstura Many")
            {
                type = "Mikstura Many";
            }
            
        };
       
};

Item GetWeaponFirstLevel()
{
    
    int random = (rand() % 8) + 1;

    switch (random)
    {
    case 1:
            return  Item("Krotki miecz",0,2,1,1,0,0,1,"Weapon");
            
        break;
    case 2:
            return  Item("Maczuga",0,3,2,1,0,0,1,"Weapon");
            
        break;
    case 3:
            return Item("Sztylet",0,0,1,3,0,0,1,"Weapon");
             
        break;
    case 4:
            return Item("Luk",0,0,2,2,0,0,1,"Weapon");
            
        break;
    case 5:
            return Item("Dlugi miecz",0,0,4,0,1,0,2,"Weapon");
            
        break;
    case 6:
            return Item("Kostur",0,0,1,0,1,4,1,"Weapon");
            
        break;
    case 7:
            return Item("Wojenny topor",0,0,5,0,0,0,2,"Weapon");
            
        break;
    case 8:
            return Item("Kusza",0,0,3,0,3,0,2,"Weapon");
            
        break;
    
    }
    return Item("Patyk",0,1,0,0,0,0,0,"Weapon");
}
Item GetArmorFirstLevel()
{
    
    int random = (rand() % 8) + 1;
    
    switch (random)
    {
    case 1:
            return Item("Szaty",1,0,0,0,1,3,1,"Armor");
            
        break;
    case 2:
            return Item("Skorzana zbroja",2,0,1,3,1,0,1,"Armor");
            
        break;
    case 3:
            return Item("Kolczuga",3,0,3,1,2,0,1,"Armor");
            
        break;
    case 4:
            return Item("Zbroja plytowa",5,0,3,0,4,0,2,"Armor");
            
        break;
    case 5:
            return Item("Kaptur",1,0,0,2,2,2,2,"Armor");
            
        break;
    case 6:
            return Item("Zelazny chelm",3,0,2,0,0,0,2,"Armor");
           
        break;
    case 7:
            return Item("Kapelusz czarodzieja",1,0,0,0,2,5,1,"Armor");
            
        break;
    case 8:
            return Item("Buty",1,1,1,1,1,1,1,"Armor");
            
        break;
    
    }
    return Item("Szmaty",0,0,0,0,0,0,0,"Armor");
}
Item GetWeaponSecondLevel()
{
    
    int random = (rand() % 8) + 1;

    switch (random)
    {
    case 1:
            return  Item("Krotki miecz II",0,4,2,2,0,0,3,"Weapon");
            
        break;
    case 2:
            return  Item("Maczuga II",0,5,4,2,0,0,3,"Weapon");
            
        break;
    case 3:
            return Item("Sztylet II",0,2,2,6,0,0,3,"Weapon");
             
        break;
    case 4:
            return Item("Luk II",0,5,4,4,0,0,3,"Weapon");
            
        break;
    case 5:
            return Item("Dlugi miecz II",0,5,7,0,3,0,5,"Weapon");
            
        break;
    case 6:
            return Item("Kostur II",0,1,2,0,2,7,5,"Weapon");
            
        break;
    case 7:
            return Item("Wojenny topor II",0,9,9,0,0,0,5,"Weapon");
            
        break;
    case 8:
            return Item("Kusza II",0,8,5,0,5,0,5,"Weapon");
            
        break;
    
    }
    return Item("Patyk II",0,2,0,0,0,0,0,"Weapon");
}
Item GetArmorSecondLevel()
{
    
    int random = (rand() % 8) + 1;
    
    switch (random)
    {
    case 1:
            return Item("Szaty II",3,0,0,0,2,6,3,"Armor");
            
        break;
    case 2:
            return Item("Skorzana zbroja II",4,0,2,6,2,0,3,"Armor");
            
        break;
    case 3:
            return Item("Kolczuga II",3,0,3,2,2,0,3,"Armor");
            
        break;
    case 4:
            return Item("Zbroja plytowa II",10,0,2,0,4,0,6,"Armor");
            
        break;
    case 5:
            return Item("Kaptur II",2,0,0,3,3,3,3,"Armor");
            
        break;
    case 6:
            return Item("Zelazny chelm II",5,0,4,0,0,0,3,"Armor");
           
        break;
    case 7:
            return Item("Kapelusz czarodzieja II",2,0,0,0,3,8,1,"Armor");
            
        break;
    case 8:
            return Item("Buty II",2,2,2,2,2,2,2,"Armor");
            
        break;
    
    }
    return Item("Szmaty",1,0,0,0,0,0,2,"Armor");
}
Item getHealthPotion()
{
    return Item("Mikstura Leczaca",2);
}
Item getManaPotion()
{
    return Item("Mikstura Many",2);
}
Item ChooseItem(std::vector<Item>& listOfItems)
{
    std::cout << "Wybierz numer przedmiotu." << std::endl;

    int playerChoice;

    std::cin >> playerChoice;
    
    return listOfItems[playerChoice-1];
}


#endif