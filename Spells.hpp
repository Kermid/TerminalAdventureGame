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
}
void fireBall(Player& player,Enemy& enemy)
{
    int damage = (10 + player.intelligence);
    player.currentMana -= 10;
    enemy.currentHealth -= damage;
}
void sinisterStrike(Player& player,Enemy& enemy)
{
    int damage = (3 + player.agility) - enemy.armor;
    player.currentMana -= 5;
    enemy.currentHealth -= damage;
}
void hunterShot(Player& player,Enemy& enemy)
{
    int damage = (3 + player.agility + player.strenght) - enemy.armor;
    player.currentMana -= 10;
    enemy.currentHealth -= damage;
    enemy.currentHealth -= damage;
    enemy.currentHealth -= damage;
}
#endif 
