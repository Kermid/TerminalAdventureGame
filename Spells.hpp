#ifndef SPELLS_HPP
#define SPELLS_HPP
#include "Entities.hpp"
#include "iostream"
#include "vector"

void strongAttack(Player& player,Enemy& enemy)
{
    int damage = (10 + player.strenght) - enemy.armor;
    player.currentMana -= 10;
    enemy.currentHealth -= damage;
    std::cout << "SILNY ATAK: " << damage << std::endl;
}
void fireBall(Player& player,Enemy& enemy)
{
    int damage = (10 + player.intelligence);
    player.currentMana -= 10;
    enemy.currentHealth -= damage;
    std::cout << "KULA OGNIA: " << damage << std::endl;
}
void sinisterStrike(Player& player,Enemy& enemy)
{
    int damage = (3 + player.agility) - enemy.armor;
    player.currentMana -= 5;
    enemy.currentHealth -= damage;
    std::cout << "PODSTEPNY CIOS: " << damage << std::endl;
}
void hunterShot(Player& player,Enemy& enemy)
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
#endif 
