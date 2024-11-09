#ifndef SPELLS_HPP
#define SPELLS_HPP
#include "iostream"
#include "vector"
#include "Entities.hpp"


bool MagicalCriticalStrike(Enemy& enemy);
bool MagicalCriticalStrike(Player& player);
bool CriticalStrike(Player& player);
void strongAttack(Player& player,Enemy& enemy)
{
    int manaCost = 10;
    if(player.currentMana >= manaCost)
    {
        if(!CriticalStrike(player))
    {
        int damage = (RandomNumber(10) + player.strenght) - enemy.armor;
        player.currentMana -= manaCost;
        enemy.currentHealth -= damage;
        std::cout << "--------------" << std::endl;
        std::cout << "SILNY ATAK: " << damage << std::endl;
        std::cout << "--------------" << std::endl;
    }
    else if(CriticalStrike(player))
    {
        int damage = 2 * (RandomNumber(10) + player.strenght) - enemy.armor;
        player.currentMana -= manaCost;
        enemy.currentHealth -= damage;
        std::cout << "-----------------------" << std::endl;
        std::cout << "KRYTYCZNY SILNY ATAK: " << damage << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
    }
    else 
    {
        std::cout << "**** BRAK MANY ****"<< std::endl;
    }
    
}
void fireBall(Player& player,Enemy& enemy)
{
    int manaCost = 10;
    if(player.currentMana >= manaCost)
    {
        if(!MagicalCriticalStrike(player))
    {
        int damage = (RandomNumber(10) + player.intelligence);
        player.currentMana -= 10;
        enemy.currentHealth -= damage;
        std::cout << "---------------" << std::endl;
        std::cout << "KULA OGNIA: " << damage << std::endl;
        std::cout << "---------------" << std::endl;
    }
    else if(MagicalCriticalStrike(player))
    {
        int damage = 2 * (RandomNumber(10) + player.intelligence);
        player.currentMana -= 10;
        enemy.currentHealth -= damage;
        std::cout << "----------------------" << std::endl;
        std::cout << "KRYTYCZNA KULA OGNIA: " << damage << std::endl;
        std::cout << "----------------------" << std::endl;
    }
    }
    else
    {
        std::cout << "**** BRAK MANY ****"<< std::endl;
    }
    
    
}
void sinisterStrike(Player& player,Enemy& enemy)
{   
    int manaCost = 5;
    if(player.currentMana >= manaCost)
    {
        if(!CriticalStrike(player))
    {
        int damage = (RandomNumber(3) + player.agility) - enemy.armor;
        player.currentMana -= 5;
        enemy.currentHealth -= damage;
        std::cout << "------------------" << std::endl;
        std::cout << "PODSTEPNY CIOS: " << damage << std::endl;
        std::cout << "------------------" << std::endl;
    }
    else if(CriticalStrike(player))
    {
        int damage = 2 * (RandomNumber(3) + player.agility) - enemy.armor;
        player.currentMana -= 5;
        enemy.currentHealth -= damage;
        std::cout << "---------------------------" << std::endl;
        std::cout << "KRYTYCZNY PODSTEPNY CIOS: " << damage << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
    }
    else
    {
        std::cout << "**** BRAK MANY ****"<< std::endl;
    }
    
    
}
void hunterShot(Player& player,Enemy& enemy)
{
    int manaCost = 10;
    if(player.currentMana >= manaCost)
    {
        if(!CriticalStrike(player))
    {
        int damage = (RandomNumber(3) + player.agility + (player.strenght/2)) - enemy.armor;
        player.currentMana -= 10;
        std::cout << "-----------------" << std::endl;
        std::cout << "SALWA LOWCY 1: " << damage << std::endl;
        std::cout << "-----------------" << std::endl;
        enemy.currentHealth -= damage;
        std::cout << "-----------------" << std::endl;
        std::cout << "SALWA LOWCY 2: " << damage << std::endl;
        std::cout << "-----------------" << std::endl;
        enemy.currentHealth -= damage;
    }
    else if(CriticalStrike(player))
    {
        int damage = 2 * (RandomNumber(3) + player.agility + (player.strenght/2)) - enemy.armor;
        player.currentMana -= 10;
        std::cout << "-----------------------------" << std::endl;
        std::cout << " KRYTYCZNA SALWA LOWCY 1: " << damage << std::endl;
        std::cout << "-----------------------------" << std::endl;
        enemy.currentHealth -= damage;
        std::cout << "-----------------------------" << std::endl;
        std::cout << "KRYTYCZNA SALWA LOWCY 2: " << damage << std::endl;
        std::cout << "-----------------------------" << std::endl;
        enemy.currentHealth -= damage;
    }
    }
    else
    {
        std::cout << "**** BRAK MANY ****"<< std::endl;
        std::cout << "" << std::endl;
    }
    
}
bool Dodge(Player& player)
{
    int dodgeValue = player.agility + 15;
    int random = RandomNumber(100);
    if(dodgeValue >= random)
    {
        return true;
    }
    else if ( dodgeValue <= random)
    {
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
void fireBallEnemy(Player& player,Enemy& enemy)
{
    int manaCost = 10;
    if(enemy.currentMana >= manaCost)
    {
        if(!MagicalCriticalStrike(enemy))
    {
        int damage = (RandomNumber(10) + enemy.intelligence);
        enemy.currentMana -= 10;
        player.currentHealth -= damage;
        std::cout << "-----------------------" << std::endl;
        std::cout << "KULA OGNIA PRZECIWNIKA: " << damage << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
    else if(MagicalCriticalStrike(enemy))
    {
        int damage = 2 * (RandomNumber(10) + enemy.intelligence);
        enemy.currentMana -= 10;
        player.currentHealth -= damage;
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "KRYTYCZNA KULA OGNIA PRZECIWNIKA: " << damage << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
    }
    else
    {   std::cout << "--------------------" << std::endl;
        std::cout << "**** PRZECIWNIKOWKI BRAKUJE MANY ****"<< std::endl;
        std::cout << "--------------------" << std::endl;
    }
    
    
}
void hardeningEnemy(Enemy& enemy)
{
    enemy.armor += 3;
    std::cout << "------------------------------" << std::endl;
    std::cout << "WROG PRZYJMUJE POSTAWE OBRONNA"<< std::endl;
    std::cout << "------------------------------" << std::endl;
}
void strongAttackEnemy(Player& player,Enemy& enemy)
{
    int manaCost = 10;
    if(enemy.currentMana >= manaCost)
    {
        if(!CriticalStrike(enemy))
    {
        int damage = (RandomNumber(5) + enemy.strenght) - player.armor;
        enemy.currentMana -= manaCost;
        player.currentHealth -= damage;
        std::cout << "----------------------" << std::endl;
        std::cout << "SILNY ATAK PRZECIWNIKA: " << damage << std::endl;
        std::cout << "----------------------" << std::endl;
    }
    else if(CriticalStrike(enemy))
    {
        int damage = 2 * (RandomNumber(5) + enemy.strenght) - player.armor;
        enemy.currentMana -= manaCost;
        player.currentHealth -= damage;
        std::cout << "--------------------------------" << std::endl;
        std::cout << "KRYTYCZNY SILNY ATAK PRZECIWNIKA: " << damage << std::endl;
        std::cout << "--------------------------------" << std::endl;
    }
    }
    else 
    {
        std::cout << "**** BRAK MANY ****"<< std::endl;
    }
    
}
bool dodgeNext(Enemy& enemy)
{
    int dodgeValue = 50;
    int random = RandomNumber(100);
    if(dodgeValue >= random)
    {
        return true;
    }
    else if ( dodgeValue <= random)
    {
        return false;
    }
    return false;
}
void WideStrike(Player& player,std::vector<Enemy>& listOfEnemies,Enemy& enemy)
{
    int manaCost = 10;
    if(player.currentMana >= manaCost)
    {
        if(!CriticalStrike(player))
        {
            int damage = (RandomNumber(10) + player.strenght) - enemy.armor;
            player.currentMana -= manaCost;
            if(listOfEnemies.size() == 2)
            {
                if(enemy.EnemyId == 1)
                {
                    listOfEnemies[enemy.EnemyId - 1].currentHealth -= damage;
                    listOfEnemies[enemy.EnemyId].currentHealth -= damage / 2;
                    std::cout << "----------------------" << std::endl;
                    std::cout << "SZEROKI ATAK: " << damage << std::endl;
                    std::cout << "OBRAZENIA OBOK CELU: " << damage / 2 << std::endl;
                    std::cout << "----------------------" << std::endl;
                }
                else if(enemy.EnemyId == 2)
                {
                    listOfEnemies[enemy.EnemyId - 1].currentHealth -= damage;
                    listOfEnemies[enemy.EnemyId - 2].currentHealth -= damage / 2;
                    std::cout << "----------------------" << std::endl;
                    std::cout << "SZEROKI ATAK: " << damage << std::endl;
                    std::cout << "OBRAZENIA OBOK CELU: " << damage / 2 << std::endl;
                    std::cout << "----------------------" << std::endl;
                }
            }
            else
            {
                listOfEnemies[enemy.EnemyId + 1].currentHealth -= damage / 2;
                enemy.currentHealth -= damage;
                listOfEnemies[enemy.EnemyId - 1].currentHealth -= damage / 2;

                std::cout << "--------------" << std::endl;
                std::cout << "SZEROKI ATAK: " << damage << std::endl;
                std::cout << "OBRAZENIA OBOK CELU: " << damage / 2 << std::endl;
                std::cout << "--------------" << std::endl;
            }
        
       
        }
        else
        {
            int damage = 2 * (RandomNumber(10) + player.strenght) - enemy.armor;
            player.currentMana -= manaCost;
            if(listOfEnemies.size() == 2)
            {
                if(enemy.EnemyId == 1)
                {
                    listOfEnemies[enemy.EnemyId - 1].currentHealth -= damage;
                    listOfEnemies[enemy.EnemyId].currentHealth -= damage / 2;
                    std::cout << "-----------------------------" << std::endl;
                    std::cout << "KRYTYCZNY SZEROKI ATAK: " << damage << std::endl;
                    std::cout << "KRYTYCZNE OBRAZENIA OBOK CELU: " << damage / 2 << std::endl;
                    std::cout << "-----------------------------" << std::endl;
                }
                else if(enemy.EnemyId == 2)
                {
                    listOfEnemies[enemy.EnemyId - 1].currentHealth -= damage;
                    listOfEnemies[enemy.EnemyId - 2].currentHealth -= damage / 2;
                    std::cout << "-----------------------------" << std::endl;
                    std::cout << "KRYTYCZNY SZEROKI ATAK: " << damage << std::endl;
                    std::cout << "KRYTYCZNE OBRAZENIA OBOK CELU: " << damage / 2 << std::endl;
                    std::cout << "-----------------------------" << std::endl;
                }
            }
            else
            {
                listOfEnemies[enemy.EnemyId + 1].currentHealth -= damage / 2;
                enemy.currentHealth -= damage;
                listOfEnemies[enemy.EnemyId - 1].currentHealth -= damage / 2;

                std::cout << "-----------------------------" << std::endl;
                std::cout << "KRYTYCZNY SZEROKI ATAK: " << damage << std::endl;
                std::cout << "KRYTYCZNE OBRAZENIA OBOK CELU: " << damage / 2 << std::endl;
                std::cout << "-----------------------------" << std::endl;
            }
        }
    }
    else 
    {
        std::cout << "**** BRAK MANY ****"<< std::endl;
    }
    
}
void Block(Player& player,bool& warriorBlock)
{
     int manaCost = 10;
     if(player.currentMana >= manaCost)
    {
        std::cout << "-------------" << std::endl;
        std::cout << "UZYLES BLOKU: " << std::endl;
        std::cout << "-------------" << std::endl;
        warriorBlock = true;

    }
    else 
    {
        std::cout << "**** BRAK MANY ****"<< std::endl;
    }

}
void MagicMissiles(Player& player,std::vector<Enemy>& listOfEnemies,Enemy& enemy)
{
    int manaCost = 30;
    int damage;
    if(player.currentMana >= manaCost)
    {
        if(!MagicalCriticalStrike(player))
        {
            if(listOfEnemies.size() == 1)
            {
                for(int i = 0;i < 4;i++)
                { 
                    damage = (RandomNumber(3) + player.intelligence);
                    enemy.currentHealth -= damage;
                    std::cout << "-------------------"<< std::endl;
                    std::cout << "MAGICZNE POCISKI: " << damage << std::endl;
                    std::cout << "-------------------"<< std::endl;
                }
            }
            else
            {
                for(int i = 0;i < 4;i++)
                {   
                    damage = (RandomNumber(3) + player.intelligence);
                    listOfEnemies[RandomNumber(listOfEnemies.size()) - 1].currentHealth -= damage;
                    std::cout << "-------------------"<< std::endl;
                    std::cout << "MAGICZNE POCISKI: " << damage << std::endl;
                    std::cout << "-------------------"<< std::endl;
                }
            }
            
            player.currentMana -= 10;   
        }
        else 
        {
            if(listOfEnemies.size() == 1)
            {
                for(int i = 0;i < 4;i++)
                { 
                    damage = 2 * (RandomNumber(3) + player.intelligence);
                    enemy.currentHealth -= damage;
                    std::cout << "-------------------"<< std::endl;
                    std::cout << "KRYTYCZNE MAGICZNE POCISKI: " << damage << std::endl;
                    std::cout << "-------------------"<< std::endl;
                }
            }
            else
            {
                for(int i = 0;i < 4;i++)
                {
                    damage = 2 * (RandomNumber(3) + player.intelligence);
                    listOfEnemies[RandomNumber(listOfEnemies.size())].currentHealth -= damage;
                    std::cout << "-------------------"<< std::endl;
                    std::cout << "KRYTYCZNE MAGICZNE POCISKI: " << damage << std::endl;
                    std::cout << "-------------------"<< std::endl;
                }
            }
            
            player.currentMana -= 10;
        }
    }
    else
    {
        std::cout << "**** BRAK MANY ****"<< std::endl;
    }
    
    
}
void VenomStrike(Player& player,Enemy& enemy)
{
    int manaCost = 5;
    if(player.currentMana >= manaCost)
    {
        if(!CriticalStrike(player))
    {
        int damage = (RandomNumber(2) + player.agility) - enemy.armor;
        enemy.poisoned = true;
        player.currentMana -= 5;
        enemy.currentHealth -= damage;
        std::cout << "---------------------" << std::endl;
        std::cout << "ZATRUTE UDERZENIE: " << damage << std::endl;
        std::cout << "---------------------" << std::endl;
    }
    else if(CriticalStrike(player))
    {
        int damage = 2 * (RandomNumber(3) + player.agility) - enemy.armor;
        enemy.poisoned = true;
        player.currentMana -= 5;
        enemy.currentHealth -= damage;
        std::cout << "------------------------------" << std::endl;
        std::cout << "KRYTYCZNE ZATRUTE UDERZENIE: " << damage << std::endl;
        std::cout << "------------------------------" << std::endl;
    }
    }
    else
    {
        std::cout << "**** BRAK MANY ****"<< std::endl;
    }
}
void Kick(Enemy& enemy)
{
    enemy.stun = true;
    std::cout << "-----------" << std::endl;
    std::cout << "KOPNIECIE: " << std::endl;
    std::cout << "-----------" << std::endl;
}
void CarnageStrike(Player& player,Enemy& enemy)
{
    int manaCost = 15;
    int heal;
    if(player.currentMana >= manaCost)
    {
        if(!CriticalStrike(player))
    {
        int damage = (RandomNumber(10) + player.strenght) - enemy.armor;
        heal = damage / 2;
        if(player.health - player.currentHealth < heal)
        {
            player.currentHealth += player.health - player.currentHealth;
        }
        else
        {
            player.currentHealth += heal;
        }
        
        player.currentMana -= manaCost;
        enemy.currentHealth -= damage;
        std::cout << "-----------------------" << std::endl;
        std::cout << "KRWIOZERCZE UDERZENIE: " << damage << std::endl;
        std::cout << "LECZENIE: " << damage / 2 << std::endl;
        std::cout << "-----------------------" << std::endl;
    }
    else if(CriticalStrike(player))
    {
        int damage = 2 * (RandomNumber(10) + player.strenght) - enemy.armor;
        heal = damage / 2;
        if(player.health - player.currentHealth < heal)
        {
            player.currentHealth += player.health - player.currentHealth;
        }
        else
        {
            player.currentHealth += heal;
        }
        player.currentMana -= manaCost;
        enemy.currentHealth -= damage;
        std::cout << "---------------------------" << std::endl;
        std::cout << "KRYTYCZNY KRWIOZERCZY CIOS: " << damage << std::endl;
        std::cout << "LECZENIE: " << heal << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
    }
    else 
    {
        std::cout << "**** BRAK MANY ****"<< std::endl;
    }
}
void BarbarianRage(Player& player,bool& barbarianRage)
{
    barbarianRage = true;
    player.strenght += 8;
    player.agility += 8;
    player.currentHealth += 10;
    std::cout << "---------------" << std::endl;
    std::cout << "SILA + 8 " << std::endl;
    std::cout << "ZRECZONSC + 8 " << std::endl;
    std::cout << "ZDROWIE + 10" << std::endl;
    std::cout <<"----------------" << std::endl;
}
void BarbarianRageEnd(Player& player)
{
    player.strenght -= 8;
    player.agility -= 8;
    player.currentHealth -= 10;
    std::cout << "---------------" << std::endl;
    std::cout << "SILA - 8 " << std::endl;
    std::cout << "ZRECZONSC - 8 " << std::endl;
    std::cout << "ZDROWIE - 10 " << std::endl;
    std::cout << "---------------" << std::endl;
}
void lifeSteal(Player& player,Enemy& enemy)
{
     int manaCost = 10;
    if(player.currentMana >= manaCost)
    {
        if(!MagicalCriticalStrike(player))
    {
        int damage = (RandomNumber(10) + player.intelligence);
        player.currentHealth += damage / 3;
        player.currentMana -= 10;
        enemy.currentHealth -= damage;
        std::cout << "-----------------" << std::endl;
        std::cout << "KRADZIEZ ZYCIA: " << damage << std::endl;
        std::cout << "LECZENIE: " << damage / 3 << std::endl;
        std::cout << "-----------------" << std::endl;
    }
    else if(MagicalCriticalStrike(player))
    {
        int damage = 2 * (RandomNumber(10) + player.intelligence);
        player.currentHealth += damage / 3;
        player.currentMana -= 10;
        enemy.currentHealth -= damage;
        std::cout << "-------------------------" << std::endl;
        std::cout << "KRYTYCZNA KRADZIEZ ZYCIA: " << damage << std::endl;
        std::cout << "LECZENIE: " << damage / 3 << std::endl;
        std::cout << "-------------------------" << std::endl;
    }
    }
    else
    {
        std::cout << "**** BRAK MANY ****"<< std::endl;
    }
}
void RendStrike(Player& player,Enemy& enemy)
{
    int manaCost = 10;
    enemy.bleed = true;
    if(player.currentMana >= manaCost)
    {
        if(!CriticalStrike(player))
    {
        int damage = (RandomNumber(10) + player.strenght) - enemy.armor;
        player.currentMana -= manaCost;
        enemy.currentHealth -= damage;
        std::cout << "--------------" << std::endl;
        std::cout << "KRWAWIACY CIOS: " << damage << std::endl;
        std::cout << "--------------" << std::endl;
    }
    else if(CriticalStrike(player))
    {
        int damage = 2 * (RandomNumber(10) + player.strenght) - enemy.armor;
        player.currentMana -= manaCost;
        enemy.currentHealth -= damage;
        std::cout << "------------------------" << std::endl;
        std::cout << "KRYTYCZNY KRWAWIACY CIOS: " << damage << std::endl;
        std::cout << "------------------------" << std::endl;
    }
    }
    else 
    {
        std::cout << "**** BRAK MANY ****"<< std::endl;
    }
}
void SpawnDemon()
{
    
}
#endif 
