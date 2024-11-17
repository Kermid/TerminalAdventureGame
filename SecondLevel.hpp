#ifndef SECONDLEVEL_HPP
#define SECONDLEVEL_HPP
#include "Entities.hpp"
#include "Locations.hpp"

int SecondLevelLeft(Player player);
int SecondLevelCentre(Player& player);
int SecondLevelRight(Player& player);
int SecondLevelBearsDen(Player& player);
int SecondLevelCentreSecond(Player& player);
int SecondLevelRightSecond(Player& player);
void ActionBandit(Player& player,Enemy& enemy,bool& warriorBlock,int& warriorblockCounter);
void ActionBoar(Player& player,Enemy& enemy,bool& warriorBlock,int& warriorblockCounter);
void ActionForestGhost(Player& player,Enemy& enemy,bool& warriorBlock,int& warriorblockCounter);
void ActionBear(Player& player,Enemy& enemy,bool& warriorBlock,int& warriorblockCounter);
int FightSecondLevel(Player& player, std::vector<Enemy>& listOfEnemies,std::string typeOfFight,bool& barbarianRage,bool& warriorBlock,int& warriorblockCounter);
int SecondLevel(Player& player)
{
    int choice;
    int outcome;
    bool continueFirst = true;
    std::vector<Enemy> listOfEnemies;

    Location locationLeft = generateForestArea();
    Location locationCentre = generateForestArea();
    Location locationRight= generateForestArea();

    while(continueFirst)
    {
        std::cout << "Masz przed soba trzy siezki" << std::endl;
        std::cout << "1 - Lewo  2 - Prosto  3 - Prawo 4 - Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;
    
        switch (choice)
        {
        case 1:
            outcome = GenerateLocationRandomFight(locationLeft,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return SecondLevelLeft(player);
            }
            else if(outcome == 0)
            {
                 std::cout << "ZGINALES!Koniec gry." << std::endl;
            }
            continueFirst = false;
        break;
        case 2:
            outcome = GenerateLocationRandomFight(locationCentre,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return SecondLevelCentre(player);
            }
            else if(outcome == 0)
            {
                 std::cout << "ZGINALES!Koniec gry." << std::endl;
            }
            continueFirst = false;
        break;
        case 3:
            outcome = GenerateLocationRandomFight(locationRight,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return SecondLevelRight(player);
            }
            else if(outcome == 0)
            {
                 std::cout << "ZGINALES!Koniec gry." << std::endl;
            }
            continueFirst = false;
        case 4:
            CheckInventory(player);
        break;
        default:
            std::cout << "Nieprawidlowy wybor" << std::endl;
        break;
        }
    }
    return 0;
}
inline int SecondLevelLeft(Player player)
{
    int choice;
    int outcome;
    bool continueFirst = true;
    std::vector<Enemy> listOfEnemies;

    Location locationLeft = generateForestArea();
    Location locationCentre = generateForestArea();
    Location locationRight= generateForestArea();

    while(continueFirst)
    {
        std::cout << "Masz przed soba trzy siezki" << std::endl;
        std::cout << "1 - Lewo  2 - Prosto  3 - Prawo 4 - Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;
    
        switch (choice)
        {
        case 1:
            outcome = GenerateLocationRandomFight(locationLeft,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return SecondLevelBearsDen(player);
            }
            continueFirst = false;
        break;
        case 2:
            outcome = GenerateLocationRandomFight(locationCentre,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return SecondLevelCentreSecond(player);
            }
            continueFirst = false;
        break;
        case 3:
            outcome = GenerateLocationRandomFight(locationRight,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                //return SecondLevelRightSecond(player);
                return 0;
            }
            else if(outcome == 0)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 4:
            CheckInventory(player);
        break;
        default:
            std::cout << "Nieprawidlowy wybor" << std::endl;
        break;
        }
    }
    return 0;
}
int SecondLevelCentre(Player &player)
{
    int choice;
    int outcome;
    bool continueFirst = true;
    std::vector<Enemy> listOfEnemies;

    Location locationLeft = generateForestArea();
    Location locationCentre = generateForestArea();
    Location locationRight= generateForestArea();

    while(continueFirst)
    {
        std::cout << "Masz przed soba trzy siezki" << std::endl;
        std::cout << "1 - Lewo  2 - Prosto  3 - Prawo 4 - Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;
    
        switch (choice)
        {
        case 1:
            outcome = GenerateLocationRandomFight(locationLeft,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 2:
            outcome = GenerateLocationRandomFight(locationCentre,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 3:
            outcome = GenerateLocationRandomFight(locationRight,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            else if(outcome == 0)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 4:
            CheckInventory(player);
        break;
        default:
            std::cout << "Nieprawidlowy wybor" << std::endl;
        break;
        }
    }
    return 0;
}
int SecondLevelRight(Player& player)
{
    int choice;
    int outcome;
    bool continueFirst = true;
    std::vector<Enemy> listOfEnemies;

    Location locationLeft = generateForestArea();
    Location locationCentre = generateForestArea();
    Location locationRight= generateForestArea();

    while(continueFirst)
    {
        std::cout << "Masz przed soba trzy siezki" << std::endl;
        std::cout << "1 - Lewo  2 - Prosto  3 - Prawo 4 - Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;
    
        switch (choice)
        {
        case 1:
            outcome = GenerateLocationRandomFight(locationLeft,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 2:
            outcome = GenerateLocationRandomFight(locationCentre,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 3:
            outcome = GenerateLocationRandomFight(locationRight,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            else if(outcome == 0)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 4:
            CheckInventory(player);
        break;
        default:
            std::cout << "Nieprawidlowy wybor" << std::endl;
        break;
        }
    }
    return 0;
}
int FightSecondLevel(Player& player, std::vector<Enemy>& listOfEnemies,std::string typeOfFight,bool& barbarianRage,bool& warriorBlock,int& warriorblockCounter)
{
    bool endFight = false;
    int ExpValue = 0;
    int barbarianRageCounter = 0;
    
    int counter = 0;
    if(typeOfFight == "Wolves")
    {
        int randomNum = RandomNumber(4);
        SpawnWolves(randomNum,listOfEnemies);
        ExpValue = randomNum * 15;
    }
    else if(typeOfFight == "Boars")
    {
        int randomNum = RandomNumber(2);
        SpawnBoars(randomNum,listOfEnemies);
        ExpValue = randomNum * 50;
    }
    else if(typeOfFight == "Bear")
    {
        SpawnBear(1,listOfEnemies);
        ExpValue = 120;
    }
    else if(typeOfFight == "Ghost of the forest")
    {
        SpawnForestGhost(2,listOfEnemies);
        ExpValue = 2 * 50;
    }
    else if(typeOfFight == "Bandits")
    {
        int randomNum = RandomNumber(3);
        SpawnBandits(randomNum,listOfEnemies);
        ExpValue = randomNum * 60;
    }

    AnnounceEnemies(listOfEnemies);
    
    
    while (endFight == false)
    {
        Enemy& enemy = ChooseEnemy(listOfEnemies);
        FightingInterface(player,enemy,listOfEnemies,barbarianRage,warriorBlock);
        if(barbarianRage)
        {
            barbarianRageCounter++;
            if(barbarianRageCounter == 3)
            {
                BarbarianRageEnd(player);
                barbarianRage = !barbarianRage;
            }
        }
        
        for(Enemy& enemyFight : listOfEnemies)
        {
            if(enemyFight.currentHealth <= 0)
            {
            
                listOfEnemies.erase(std::remove_if(listOfEnemies.begin(),listOfEnemies.end(),[&enemyFight](Enemy& e) {return e.EnemyId == enemyFight.EnemyId;}),listOfEnemies.end());

                //Po zabiciu id jest aktualizowane
                counter = 1;
                for(Enemy& enemyIdUpdate : listOfEnemies)
                {
                    enemyIdUpdate.EnemyId = counter;
                    counter++;
                
                }
             }
        }
        
        for(Enemy& enemy : listOfEnemies)
        {
            
            if(enemy.name == "Wilk")
            {
                if(enemy.stun)
                {
                    std::cout << "--------------------" << std::endl;
                    std::cout << "PRZECIWNIK OGLUSZONY" << std::endl;
                    std::cout << "--------------------" << std::endl;
                }
                else
                {
                    ActionWolf(player,enemy,warriorBlock,warriorblockCounter);
                    EndBlock(warriorblockCounter,warriorBlock);
                }
            }
            else if(enemy.name == "Dzik")
            {
                if(enemy.stun)
                {
                    std::cout << "--------------------" << std::endl;
                    std::cout << "PRZECIWNIK OGLUSZONY" << std::endl;
                    std::cout << "--------------------" << std::endl;
                }
                else
                {
                    ActionBoar(player,enemy,warriorBlock,warriorblockCounter);
                    EndBlock(warriorblockCounter,warriorBlock);
                }
                
            } 
            else if(enemy.name == "Niedzwiedz")
            {
                 if(enemy.stun)
                {
                    std::cout << "--------------------" << std::endl;
                    std::cout << "PRZECIWNIK OGLUSZONY" << std::endl;
                    std::cout << "--------------------" << std::endl;
                }
                else
                {
                    ActionBear(player,enemy,warriorBlock,warriorblockCounter);
                    EndBlock(warriorblockCounter,warriorBlock);
                }
                
            }
            else if(enemy.name == "Duch lasu")
            {
                if(enemy.stun)
                {
                    std::cout << "--------------------" << std::endl;
                    std::cout << "PRZECIWNIK OGLUSZONY" << std::endl;
                    std::cout << "--------------------" << std::endl;
                }
                else
                {
                     ActionForestGhost(player,enemy,warriorBlock,warriorblockCounter);
                     EndBlock(warriorblockCounter,warriorBlock);
                }
               
            }
            else if(enemy.name == "Bandyta")
            {
                if(enemy.stun)
                {
                    std::cout << "--------------------" << std::endl;
                    std::cout << "PRZECIWNIK OGLUSZONY" << std::endl;
                    std::cout << "--------------------" << std::endl;
                }
                else
                {
                     ActionBandit(player,enemy,warriorBlock,warriorblockCounter);
                     EndBlock(warriorblockCounter,warriorBlock);
                }
               
            }
            if(enemy.poisoned)
            {
                enemy.currentHealth -= 2;
                std::cout << "------------------------" << std::endl;
                std::cout << "OBRAZENIA OD TRUCIZNY: 2"<< std::endl;
                std::cout << "------------------------" << std::endl;
            }
            if(enemy.bleed)
            {
                enemy.currentHealth -= 2;
                std::cout << "--------------------------" << std::endl;
                std::cout << "OBRAZENIA OD KRWAWIENIA: 2"<< std::endl;
                std::cout << "--------------------------" << std::endl;
            }
        }
        //checking if list is empty or player has died
        if(listOfEnemies.empty())
        {
            player.PlayerGiveExperience(ExpValue);
            std::cout << "Otrzymales " << ExpValue << " punktow doswiadczenia!" << std::endl;
            if(player.experience >= 70 && player.Level == 1)
            {
                player.levelUp();
                std::cout << "Osiagnales " << player.Level << " poziom!" << std::endl;
            }
            else if(player.experience >= 120 && player.Level == 2)
            {
                player.levelUp();
                std::cout << "Osiagnales " << player.Level << " poziom!" << std::endl;
            }
            else if(player.experience >= 200 && player.Level == 3)
            {
                player.levelUp();
                std::cout << "Osiagnales " << player.Level << " poziom!" << std::endl;
            }
            endFight = true;
            return 1;
        }
        else if(player.currentHealth <= 0)
        {
            endFight = true;
            return 0;
        }
    }
    return 2;
}
int FightSecondLevel(Player& player, std::vector<Enemy>& listOfEnemies,std::string typeOfFight,bool& barbarianRage,bool& warriorBlock,int& warriorblockCounter,int numberOfEnemies)
{
    bool endFight = false;
    int ExpValue = 0;
    int barbarianRageCounter = 0;
    
    int counter = 0;
    if(typeOfFight == "Wolves")
    {
        
        SpawnWolves(numberOfEnemies,listOfEnemies);
        ExpValue = numberOfEnemies * 15;
    }
    else if(typeOfFight == "Boars")
    {
        
        SpawnBoars(numberOfEnemies,listOfEnemies);
        ExpValue = numberOfEnemies * 50;
    }
    else if(typeOfFight == "Bear")
    {
        SpawnBear(numberOfEnemies,listOfEnemies);
        ExpValue = numberOfEnemies * 120;
    }
    else if(typeOfFight == "Ghost of the forest")
    {
        SpawnForestGhost(numberOfEnemies,listOfEnemies);
        ExpValue = numberOfEnemies * 50;
    }
    else if(typeOfFight == "Bandits")
    {
        
        SpawnBandits(numberOfEnemies,listOfEnemies);
        ExpValue = numberOfEnemies * 60;
    }

    AnnounceEnemies(listOfEnemies);
    
    
    while (endFight == false)
    {
        Enemy& enemy = ChooseEnemy(listOfEnemies);
        FightingInterface(player,enemy,listOfEnemies,barbarianRage,warriorBlock);
        if(barbarianRage)
        {
            barbarianRageCounter++;
            if(barbarianRageCounter == 3)
            {
                BarbarianRageEnd(player);
                barbarianRage = !barbarianRage;
            }
        }
        
        for(Enemy& enemyFight : listOfEnemies)
        {
            if(enemyFight.currentHealth <= 0)
            {
            
                listOfEnemies.erase(std::remove_if(listOfEnemies.begin(),listOfEnemies.end(),[&enemyFight](Enemy& e) {return e.EnemyId == enemyFight.EnemyId;}),listOfEnemies.end());

                //Po zabiciu id jest aktualizowane
                counter = 1;
                for(Enemy& enemyIdUpdate : listOfEnemies)
                {
                    enemyIdUpdate.EnemyId = counter;
                    counter++;
                
                }
             }
        }
        
        for(Enemy& enemy : listOfEnemies)
        {
            
            if(enemy.name == "Wilk")
            {
                if(enemy.stun)
                {
                    std::cout << "--------------------" << std::endl;
                    std::cout << "PRZECIWNIK OGLUSZONY" << std::endl;
                    std::cout << "--------------------" << std::endl;
                }
                else
                {
                    ActionWolf(player,enemy,warriorBlock,warriorblockCounter);
                    EndBlock(warriorblockCounter,warriorBlock);
                }
            }
            else if(enemy.name == "Dzik")
            {
                if(enemy.stun)
                {
                    std::cout << "--------------------" << std::endl;
                    std::cout << "PRZECIWNIK OGLUSZONY" << std::endl;
                    std::cout << "--------------------" << std::endl;
                }
                else
                {
                    ActionBoar(player,enemy,warriorBlock,warriorblockCounter);
                    EndBlock(warriorblockCounter,warriorBlock);
                }
                
            } 
            else if(enemy.name == "Niedzwiedz")
            {
                 if(enemy.stun)
                {
                    std::cout << "--------------------" << std::endl;
                    std::cout << "PRZECIWNIK OGLUSZONY" << std::endl;
                    std::cout << "--------------------" << std::endl;
                }
                else
                {
                    ActionBear(player,enemy,warriorBlock,warriorblockCounter);
                    EndBlock(warriorblockCounter,warriorBlock);
                }
                
            }
            else if(enemy.name == "Duch lasu")
            {
                if(enemy.stun)
                {
                    std::cout << "--------------------" << std::endl;
                    std::cout << "PRZECIWNIK OGLUSZONY" << std::endl;
                    std::cout << "--------------------" << std::endl;
                }
                else
                {
                     ActionForestGhost(player,enemy,warriorBlock,warriorblockCounter);
                     EndBlock(warriorblockCounter,warriorBlock);
                }
               
            }
            else if(enemy.name == "Bandyta")
            {
                if(enemy.stun)
                {
                    std::cout << "--------------------" << std::endl;
                    std::cout << "PRZECIWNIK OGLUSZONY" << std::endl;
                    std::cout << "--------------------" << std::endl;
                }
                else
                {
                     ActionBandit(player,enemy,warriorBlock,warriorblockCounter);
                     EndBlock(warriorblockCounter,warriorBlock);
                }
               
            }
            if(enemy.poisoned)
            {
                enemy.currentHealth -= 2;
                std::cout << "------------------------" << std::endl;
                std::cout << "OBRAZENIA OD TRUCIZNY: 2"<< std::endl;
                std::cout << "------------------------" << std::endl;
            }
            if(enemy.bleed)
            {
                enemy.currentHealth -= 2;
                std::cout << "--------------------------" << std::endl;
                std::cout << "OBRAZENIA OD KRWAWIENIA: 2"<< std::endl;
                std::cout << "--------------------------" << std::endl;
            }
        }
        //checking if list is empty or player has died
        if(listOfEnemies.empty())
        {
            player.PlayerGiveExperience(ExpValue);
            std::cout << "Otrzymales " << ExpValue << " punktow doswiadczenia!" << std::endl;
            if(player.experience >= 70 && player.Level == 1)
            {
                player.levelUp();
                std::cout << "Osiagnales " << player.Level << " poziom!" << std::endl;
            }
            else if(player.experience >= 120 && player.Level == 2)
            {
                player.levelUp();
                std::cout << "Osiagnales " << player.Level << " poziom!" << std::endl;
            }
            else if(player.experience >= 200 && player.Level == 3)
            {
                player.levelUp();
                std::cout << "Osiagnales " << player.Level << " poziom!" << std::endl;
            }
            endFight = true;
            return 1;
        }
        else if(player.currentHealth <= 0)
        {
            endFight = true;
            return 0;
        }
    }
    return 2;
}
int SecondLevelBearsDen(Player& player)
{
    int choice;
    int outcome;
    bool continueFirst = true;
    std::vector<Enemy> listOfEnemies;
    std::string description = "W srodku znajduja sie dwa niedzwiedzie!Przygotuj sie do walki!";
    Location bearsden(description,true,true);
    Location SecondLevelLeftSecond = generateForestArea();
     while(continueFirst)
    {
        std::cout << "Stoisz przed jaskinia.Ze srodka dobiegaja powarkiwania.Wchodzisz do srodka?" << std::endl;
        std::cout << "1 - Wejdz do jaskini 2 - Odejdz 3 - Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;
    
        switch (choice)
        {
        case 1:
            outcome = GenerateLocation(bearsden,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter,"Niedzwiedz",2);
            if(outcome == 1)
            {
                return SecondLevelLeft(player);
            }
            else if(outcome == 0)
            {
                 std::cout << "ZGINALES!Koniec gry." << std::endl;
            }
            continueFirst = false;
        break;
        case 2:
            outcome = GenerateLocationRandomFight(SecondLevelLeftSecond,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return SecondLevelCentreSecond(player);
            }
            else if(outcome == 0)
            {
                 std::cout << "ZGINALES!Koniec gry." << std::endl;
            }
            continueFirst = false;
        break;     
        case 3:
            CheckInventory(player);
        break;
        default:
            std::cout << "Nieprawidlowy wybor" << std::endl;
        break;
        }
    }
    return 0;
}
int SecondLevelCentreSecond(Player& player)
{
    int choice;
    int outcome;
    bool continueFirst = true;
    std::vector<Enemy> listOfEnemies;

    Location locationLeft = generateForestArea();
    Location locationCentre = generateForestArea();
    Location locationRight= generateForestArea();

    while(continueFirst)
    {
        std::cout << "Masz przed soba trzy siezki" << std::endl;
        std::cout << "1 - Lewo  2 - Prosto  3 - Prawo 4 - Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;
    
        switch (choice)
        {
        case 1:
            outcome = GenerateLocationRandomFight(locationLeft,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 2:
            outcome = GenerateLocationRandomFight(locationCentre,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 3:
            outcome = GenerateLocationRandomFight(locationRight,player,listOfEnemies,barbarianRage,warriorBlock,warriorblockCounter);
            if(outcome == 1)
            {
                return 1;
            }
            else if(outcome == 0)
            {
                return 1;
            }
            continueFirst = false;
        break;
        case 4:
            CheckInventory(player);
        break;
        default:
            std::cout << "Nieprawidlowy wybor" << std::endl;
        break;
        }
    }
    return 0;
}

#endif


