#ifndef SPELLS_HPP
#define SPELLS_HPP
#include "Entities.hpp"
#include "iostream"
#include "vector"

bool MagicalCriticalStrike(Enemy& enemy);
bool MagicalCriticalStrike(Player& player);
bool CriticalStrike(Player& player);
void strongAttack(Player& player,Enemy& enemy)
{
    if(!CriticalStrike(player))
    {
        int damage = (10 + player.strenght) - enemy.armor;
        player.currentMana -= 10;
        enemy.currentHealth -= damage;
        std::cout << "KRYTYCZNY SILNY ATAK: " << damage << std::endl;
    }
    else if(CriticalStrike(player))
    {
        int damage = 2 * (10 + player.strenght) - enemy.armor;
        player.currentMana -= 10;
        enemy.currentHealth -= damage;
        std::cout << "KRYTYCZNY SILNY ATAK: " << damage << std::endl;
    }
}
void fireBall(Player& player,Enemy& enemy)
{
    if(!MagicalCriticalStrike(player))
    {
        int damage = (10 + player.intelligence);
        player.currentMana -= 10;
        enemy.currentHealth -= damage;
        std::cout << "KULA OGNIA: " << damage << std::endl;
    }
    else if(MagicalCriticalStrike(player))
    {
        int damage = 2 * (10 + player.intelligence);
        player.currentMana -= 10;
        enemy.currentHealth -= damage;
        std::cout << "KULA OGNIA: " << damage << std::endl;
    }
    
}
void sinisterStrike(Player& player,Enemy& enemy)
{   
     if(!CriticalStrike(player))
    {
        int damage = (3 + player.agility) - enemy.armor;
        player.currentMana -= 5;
        enemy.currentHealth -= damage;
        std::cout << "PODSTEPNY CIOS: " << damage << std::endl;
    }
    else if(CriticalStrike(player))
    {
        int damage = 2 * (3 + player.agility) - enemy.armor;
        player.currentMana -= 5;
        enemy.currentHealth -= damage;
        std::cout << "KRYTYCZNY PODSTEPNY CIOS: " << damage << std::endl;
    }
    
}
void hunterShot(Player& player,Enemy& enemy)
{
    
     if(!CriticalStrike(player))
    {
        int damage = (3 + player.agility + (player.strenght/2)) - enemy.armor;
        player.currentMana -= 10;
        std::cout << "SALWA LOWCY 1: " << damage << std::endl;
        enemy.currentHealth -= damage;
        std::cout << "SALWA LOWCY 2: " << damage << std::endl;
        enemy.currentHealth -= damage;
        std::cout << "SALWA LOWCY 3: " << damage << std::endl;
        enemy.currentHealth -= damage;
    }
    else if(CriticalStrike(player))
    {
        int damage = 2 * (3 + player.agility + (player.strenght/2)) - enemy.armor;
        player.currentMana -= 10;
        std::cout << " KRYTYCZNA SALWA LOWCY 1: " << damage << std::endl;
        enemy.currentHealth -= damage;
        std::cout << "KRYTYCZNA SALWA LOWCY 2: " << damage << std::endl;
        enemy.currentHealth -= damage;
        std::cout << "KRYTYCZNA SALWA LOWCY 3: " << damage << std::endl;
        enemy.currentHealth -= damage;
    }
}
bool Dodge(Player& player)
{
    int dodgeValue = player.agility + 5;
    std::cout << "WARTOSC UNIKU: " << dodgeValue << std::endl;
    int random = RandomNumber(100);
    if(dodgeValue >= random)
    {
        std::cout << "SZANSA NA TRAFIENIE PULAKI: " << random << std::endl;
        return true;
    }
    else if ( dodgeValue <= random)
    {
        std::cout << " SZANSA NA TRAFIENIE PULAKI: "<< random << std::endl;
        return false;
    }
    return false;
}
bool CriticalStrike(Player& player)
{
    int critValue = player.agility + 5;
    int random = RandomNumber(100);
    if(critValue >= random)
    {
        return true;
    }
    else if ( critValue <= random)
    {
        return false;
    }
    return false;
}
bool CriticalStrike(Enemy& enemy)
{
    int critValue = enemy.agility + 5;
    int random = RandomNumber(100);
    if(critValue >= random)
    {
        return true;
    }
    else if ( critValue <= random)
    {
        return false;
    }
    return false;
}
bool MagicalCriticalStrike(Player& player)
{
    int critValue = player.intelligence + 5;
    int random = RandomNumber(100);
    if(critValue >= random)
    {
        return true;
    }
    else if ( critValue <= random)
    {
        return false;
    }
    return false;
}
bool MagicalCriticalStrike(Enemy& enemy)
{
    int critValue = enemy.intelligence + 5;
    int random = RandomNumber(100);
    if(critValue >= random)
    {
        return true;
    }
    else if ( critValue <= random)
    {
        return false;
    }
    return false;
}
#endif 
