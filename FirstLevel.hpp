#ifndef GAME_HPP
#define GAME_HPP
#include "Entities.hpp"
#include "Items.hpp"
#include "Spells.hpp"
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

bool Wolfdodge;
void Chest(Item item,Player& player);
int CentreSecond(Player& player);
int LeftSecond(Player& player);
void Trap(Player& player);
void CheckInventory(Player& player);
int Fight(Player& player,std::vector<Enemy>& listOfEnemies,std::string typeOfFight);
void FightingInterface(Player& player,Enemy& enemy);
void HealingShrine(Player& player);
int RightThird(Player& player);
int LeftThird(Player& player);
int CentreThird(Player& player);
int Crypt(Player& player);
int FirstLevel(Player& player)
{
    int choice;
    int outcome;

    std::vector<Enemy> listOfEnemies;

    //case 2 jest tutaj bo sie psuje jak jest w switch

    bool SecondContinue = true;
    std::cout << "Wkraczasz do ponurych bagien, gdzie ziemia jest miekka i lepka, a kazdy krok wpada w glebokie bloto." << std::endl;
    std::cout << "Woda stoi w kaluzach, a gesta mgla spowija wszystko wokol, ograniczajac widocznosc." << std::endl;
    std::cout << "W powietrzu czuc zapach gnijacych roslin." << std::endl;
    std::cout << "Musisz uwazac, bo w bagnach wszystko wydaje sie niebezpieczne, a droga przed toba jest zdradliwa." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Masz przed soba trzy siezki" << std::endl;
    std::cout << "1 - Lewo  2 - Prosto  3 - Prawo " << std::endl;
    std::cout << "" << std::endl;
    
    std::cin >> choice;
    switch(choice)
    {
        case 1:

            std::cout << "Wybrales pierwsza droge" << std::endl;
            std::cout << " " << std::endl;
            std::cout << "Wkraczasz na zapomniany cmentarz.Krzywe,omszale nagrobki wyrastaja z grzaskiego gruntu,"  << std::endl;
            std::cout << "a powykrecane drzewa splataja swoje galezie nad nimi, tworzac ponura kopule." << std::endl;
            std::cout << "Metna woda zbiera sie w kaluzach wokol grobow, a mgla unosi sie nisko nad ziemia." << std::endl;
            std::cout << "Cmentarz jest cichy, poza odleglym rechotem zab i szeletem traw slychac szelest lisci w oddali" << std::endl;
            std::cout << " " << std::endl;

                outcome = Fight(player,listOfEnemies,"Skeletons");
                if(outcome == 1)
                {
                    Chest(GetWeaponFirstLevel(),player);
                    return LeftSecond(player);
                    
                }
                else if(outcome == 0)
                {
                    std::cout << "ZGINALES!Koniec gry." << std::endl;
                }
                
        break;
        case 2:
            int choiceSecond;
            
            std::cout << "Wybrales druga droge" << std::endl;
            std::cout << " " << std::endl;
            std::cout << "Dotarles do ruin starego drewnianego domu." << std::endl;
            std::cout << "Wlasciciele dawno sie stad wyniesli, jednak mozliwe, ze zostawili za soba czesc swojego majatku." << std::endl;

           while(SecondContinue)
            {
                std::cout << " " << std::endl;
                std::cout << "1 - Przeszukaj okolice  2 - Idz dalej  3 - Sprawdz ekwipunek" << std::endl;

                std::cin >> choiceSecond;

                switch (choiceSecond)
                {
                case 1:
                    Trap(player);
                    Chest(GetArmorFirstLevel(),player);
                    return CentreSecond(player);
                    SecondContinue = false;
                break;
                case 2:
                    return CentreSecond(player);
                    SecondContinue = false;
                break;
                case 3:
                    CheckInventory(player);
                break;
            
                default:
                    std::cout << "Niewlasciwa opcja" << std::endl;
                break;
                }
            
            }

        break;

        case 3:
            int choiceThird;
            bool continueThird = true;

            std::cout << "Wybrales trzecia droge" << std::endl;
            std::cout << " " << std::endl;
            std::cout << "Pod drzewem lezy szkielet, wydaje sie ze moze znajdowac sie tutaj cos ciekawego." << std::endl;

            while(continueThird)
            {
                std::cout << " " << std::endl;
                std::cout << "1 - Przeszukaj okolice  2 - Idz dalej  3 - Sprawdz ekwipunek" << std::endl;

                std::cin >> choiceThird;

                switch(choiceThird)
                {
                case 1:
                    Chest(GetWeaponFirstLevel(),player);
                    RightThird(player);
                    continueThird = false;
                break;
                case 2:
                    HealingShrine(player);
                    RightThird(player);
                    continueThird = false;
                break;
                case 3:
                    CheckInventory(player);
                break;
            
                default:
                    std::cout << "Niewlasciwa opcja" << std::endl;
                break;
                }
           }

        break;
        
            
            
    }
}
void Chest(Item item,Player& player)
{
    int choiceTake;
    int choiceItem;
    int counter;
    bool itemTaking = true;
    Item healthPotion = Item("Mikstura Leczaca",2);
    Item manaPotion = Item("Mikstura Many",2);
    std::vector<Item> chest;
    
    chest.push_back(item);

    for(int i = 0; i < RandomNumber(2);i++)
    {
        chest.push_back(healthPotion);
    }
    for(int i = 0; i < RandomNumber(2);i++)
    {
        chest.push_back(manaPotion);
    }
    
    std::cout << "-------------------------------------------" << std::endl;
    std::cout << "****** Udalo ci sie znalesc skrzynie ******" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    while(itemTaking)
    {
        counter = 1;
         for(Item& itemChest : chest)
    {
        std::cout << "|#" << counter << " " << itemChest.name << std::endl;
        counter++;
    }
    std::cout << "_________________________________________________" << std::endl;
    std::cout << "|1 - Wez przedmiot  |2 - Wez wszystko |3 - Odejdz" << std::endl;
    std::cout << "" << std::endl;
    
    std::cin >> choiceTake;
    switch (choiceTake)
    {
    case 1:
            std::cout << "Wybierz numer przedmiotu, ktory chcesz wziac: ";
            std::cin >> choiceItem;

            if (choiceItem > 0 && choiceItem <= chest.size())
            {
                
                player.Inventory.push_back(chest[choiceItem - 1]);

                
                chest.erase(chest.begin() + (choiceItem - 1));

            }
            else
            {
                std::cout << "Niepoprawny numer przedmiotu." << std::endl;
            }
            if(chest.empty())
            {
                itemTaking = false;
            }
            break;
            
        break;
    case 2:
    for(Item itemChest : chest)
        {
            player.Inventory.push_back(itemChest);
        }
        chest.clear();
        itemTaking = false;
        break;
    case 3:
        std::cout << "Odchodzisz." << std::endl;
        itemTaking = false;
        break;
    default:
        std::cout << "Wybierz poprawna opcje." << std::endl;
        break;
    }
    }
   
    
}
void Attack(Player& player,Enemy& enemy)
{
    
    if(!CriticalStrike(player))
    {
        if(Wolfdodge)
        {
            std::cout << "----------------" << std::endl;
            std::cout << "UNIK PRZECIWNIKA" << std::endl;
            std::cout << "----------------" << std::endl;
        }
        else
        {
            int damage = (1 + player.strenght) - enemy.armor;
            std::cout << "----------------" << std::endl;
            std::cout << "NORMALNY ATAK: " << damage << std::endl;
            std::cout << "----------------" << std::endl;
            enemy.currentHealth -= damage;
        }
        
    }
    else if(CriticalStrike(player))
    {
        if(Wolfdodge)
        {
            std::cout << "----------------" << std::endl;
            std::cout << "UNIK PRZECIWNIKA" << std::endl;
            std::cout << "----------------" << std::endl;
        }
        else
        {
             int damage = 2 * (1 + player.strenght) - enemy.armor;
            std::cout << "----------------------" << std::endl;
            std::cout << "TRAFIENIE KRYTYCZNE: " << damage << std::endl;
            std::cout << "----------------------" << std::endl;
            enemy.currentHealth -= damage;
        }
       
    }

    DisplayCurrentHealth(enemy);

}
void ActionMage(Player& player,Enemy& enemy)
{
    int random = RandomNumber(30);
    if (random >= 0 && random < 20)
    {
        if(CriticalStrike(enemy))
        {
            int damage = 2 * (1 + enemy.strenght) - player.armor;
            std::cout << "------------------------------" << std::endl;
            std::cout << "|ATAK KRYTYCZNY PRZECIWNIKA: " << damage << std::endl;
            std::cout << "------------------------------" << std::endl;
            player.currentHealth -= damage;
        }
        else
        {
            int damage = (1 + enemy.strenght) - player.armor;
            std::cout << "-------------------" << std::endl;
            std::cout << "ATAK PRZECIWNIKA: " << damage << std::endl;
            std::cout << "-------------------" << std::endl;
            std::cout << "" << std::endl;
            player.currentHealth -= damage;
        }

        DisplayCurrentHealth(player);
    }
    else if (random >= 20 && random <= 30)
    {
        fireBallEnemy(player,enemy);
    }

}
void ActionSkeletonWarrior(Player& player,Enemy& enemy)
{
    bool endOfHardnening = false;
    int random = RandomNumber(30);
    if (random >= 0 && random < 10)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        if(CriticalStrike(enemy))
        {
            int damage = 2 * (1 + enemy.strenght) - player.armor;
            std::cout << "------------------------------" << std::endl;
            std::cout << "|ATAK KRYTYCZNY PRZECIWNIKA: " << damage << std::endl;
            std::cout << "------------------------------" << std::endl;
            player.currentHealth -= damage;
        }
        else
        {
            int damage = (1 + enemy.strenght) - player.armor;
            std::cout << "-------------------" << std::endl;
            std::cout << "ATAK PRZECIWNIKA: " << damage << std::endl;
            std::cout << "-------------------" << std::endl;
            std::cout << "" << std::endl;
            player.currentHealth -= damage;
        }

        DisplayCurrentHealth(player);
    }
    else if (random >= 20 && random <= 30)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
       strongAttackEnemy(player,enemy);
    }
    else if(random >= 10 && random < 20)
    {
        if(endOfHardnening)
        {
            enemy.armor -= 3;
            endOfHardnening = !endOfHardnening;
        }
        hardeningEnemy(enemy);
    }
}
void ActionWolf(Player& player,Enemy& enemy)
{
    
    int random = RandomNumber(30);
    if (random >= 0 && random < 20)
    {
        if(CriticalStrike(enemy))
        {
            int damage = 2 * (1 + enemy.strenght) - player.armor;
            std::cout << "------------------------------" << std::endl;
            std::cout << "|ATAK KRYTYCZNY PRZECIWNIKA: " << damage << std::endl;
            std::cout << "------------------------------" << std::endl;
            player.currentHealth -= damage;
            Wolfdodge = false;
        }
        else
        {
            int damage = (1 + enemy.strenght) - player.armor;
            std::cout << "-------------------" << std::endl;
            std::cout << "ATAK PRZECIWNIKA: " << damage << std::endl;
            std::cout << "-------------------" << std::endl;
            std::cout << "" << std::endl;
            player.currentHealth -= damage;
            Wolfdodge = false;
        }

        DisplayCurrentHealth(player);
    }
    else if (random >= 20 && random <= 30)
    {


        Wolfdodge = dodgeNext(enemy);
    }

}
void EnemyAttack(Player& player,Enemy& enemy)
{
    
    if(CriticalStrike(enemy))
    {
        int damage = 2 * (1 + enemy.strenght) - player.armor;
        std::cout << "------------------------------" << std::endl;
        std::cout << "|ATAK KRYTYCZNY PRZECIWNIKA: " << damage << std::endl;
        std::cout << "------------------------------" << std::endl;
        player.currentHealth -= damage;
    }
    else
    {
        int damage = (1 + enemy.strenght) - player.armor;
        std::cout << "-------------------" << std::endl;
        std::cout << "ATAK PRZECIWNIKA: " << damage << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "" << std::endl;
        player.currentHealth -= damage;
    }

    DisplayCurrentHealth(player);
}
int Fight(Player& player, std::vector<Enemy>& listOfEnemies,std::string typeOfFight)
{
    bool endFight = false;

    if(typeOfFight == "Skeletons")
    {
        SpawnSkeletons(RandomNumber(2),listOfEnemies);
    }
    else if(typeOfFight == "Wolves")
    {
        SpawnWolves(RandomNumber(4),listOfEnemies);
    }
    else if(typeOfFight == "Skeleton Mage")
    {
        SpawnMage(RandomNumber(1),listOfEnemies);
        SpawnSkeletons(RandomNumber(1),listOfEnemies);
    }
    else if(typeOfFight == "Skeleton Warrior")
    {
        SpawnWarriorSkeleton(listOfEnemies);
    }

    AnnounceEnemies(listOfEnemies);
    
    
    while (endFight == false)
    {
        Enemy& enemy = ChooseEnemy(listOfEnemies);
        FightingInterface(player,enemy);
        if(enemy.currentHealth <= 0)
        {
            
            listOfEnemies.erase(std::remove_if(listOfEnemies.begin(),listOfEnemies.end(),[&enemy](Enemy& e) {return e.EnemyId == enemy.EnemyId;}),listOfEnemies.end());

            //Po zabiciu id jest aktualizowane

            for(Enemy& enemy : listOfEnemies)
            {
                enemy.EnemyId--;
            }
        }
        for(Enemy& enemy : listOfEnemies)
        {
            
            if(enemy.name == "Szkielet")
            {
                EnemyAttack(player,enemy);
            }
            else if(enemy.name == "Wilk")
            {
                ActionWolf(player,enemy);
            } 
            else if(enemy.name == "Szkielet wojownik")
            {
                ActionSkeletonWarrior(player,enemy);
            }
            else if(enemy.name == "Szkielet Mag")
            {
                ActionMage(player,enemy);
                
            }
        }
        //checking if list is empty or player has died
        if(listOfEnemies.empty())
        {
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
void CalculatingTurns(Player& player,std::vector<Enemy>& listofEnemies)

{

}
void Trap(Player& player)
{
    std::cout << "__________________________" << std::endl;
    std::cout << "Idac natafiasz na pulapke!" << std::endl;
    bool dodge = Dodge(player);
    if(dodge)
    {   std::cout << "_____________________________" << std::endl;
        std::cout << "Udalo ci sie uniknac pulapki!" << std::endl;
    }
    else if (!dodge)
    {
        player.currentHealth -= 5;
        DisplayCurrentHealth(player);
    }
    
}
int LeftSecond(Player& player)
{
    int choice;
    int outcome;
    bool continueSecond = true;
    std::vector<Enemy> listOfEnemiesLeftSecond;
    std::cout << "Przechodzisz dalej w glab cmentarza.Po walce rozgladasz sie po po okolicy" << std::endl;
    std::cout << "Na wprost przed toba widnieje wejscie do krypty z ktorej dochodza niezbyt glosne odglosy poruszania sie jakiejs istoty." << std::endl;
    std::cout << "Po prawej widac zarosnieta brame, i biegnaca przez nia sciezka." << std::endl;
    while(continueSecond)
    {
        std::cout << "Masz przed soba dwie siezki" << std::endl;
        std::cout << "______________________________________________________" << std::endl;
        std::cout << "|1 - Wejdz do krypty |2 - Prawo |3 - Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;

            switch (choice)
            {
            case 1:
                Trap(player);
                outcome = Fight(player,listOfEnemiesLeftSecond,"Skeleton Mage");
                if(outcome == 1)
                {
                    Chest(GetWeaponFirstLevel(),player);
                    return Crypt(player);
                    
                }
                else if(outcome == 0)
                {
                    std::cout << "ZGINALES!Koniec gry." << std::endl;
                }
                continueSecond = false;
                break;
            case 2:
                Trap(player);
                
                return CentreSecond(player);
                continueSecond = false;
                break;
            case 3:
                CheckInventory(player);
                
            break;
            default:
            std::cout << "Nie prawidlowy wybor" << std::endl;
                break;
            }
    }
    
}
int LeftSecondCleared(Player& player)
{
    int choice;
    int outcome;
    bool continueSecond = true;
    std::vector<Enemy> listOfEnemiesLeftSecond;
    std::cout << "Przechodzisz dalej w glab cmentarza.Po walce rozgladasz sie po po okolicy" << std::endl;
    std::cout << "Na wprost przed toba widnieje wejscie do krypty z ktorej dochodza niezbyt glosne odglosy poruszania sie jakiejs istoty." << std::endl;
    std::cout << "Po prawej widac zarosnieta brame, i biegnaca przez nia sciezka." << std::endl;
    while(continueSecond)
    {
        std::cout << "Masz przed soba dwie siezki" << std::endl;
        std::cout << "______________________________________________________" << std::endl;
        std::cout << "|1 - Wejdz do krypty |2 - Prawo |3 - Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;

            switch (choice)
            {
            case 1:
                return Crypt(player);
                continueSecond = false;
                break;
            case 2:
                Trap(player);
                
                return CentreSecond(player);
                continueSecond = false;
                break;
            case 3:
                CheckInventory(player);
                
            break;
            default:
            std::cout << "Nie prawidlowy wybor" << std::endl;
                break;
            }
    }
    
}
int CentreSecond(Player& player)
{
    int choice;
    int outcome;
    bool continueThird = true;
    std::vector<Enemy> listOfEnemiesCentreSecond;
    std::cout << "Idziesz dalej w glab mrocznego bagna nie napotkujac wiekszego oporu od mieszkancow tej krainy." << std::endl;
    std::cout << "Jedna wzgledny spokoj z czasem zaczyna zamienac sie w niepokoj." << std::endl;
    std::cout << "Starozytne drzewa obrasta mech, spogladanie dalej otrudnia rowniez gesta mgla, ktora ani troche sie nie zmniejszyla." << std::endl;
    while(continueThird)
    {
        std::cout << "Masz przed soba trzy siezki" << std::endl;
        std::cout << "_______________________________________________________________" << std::endl;
        std::cout << "|1 - Lewo  |2 - Przed siebie |3 - Prawo  |4 - Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;
        switch (choice)
            {
            case 1:
                //mageskeleton
                Trap(player);
                outcome = Fight(player,listOfEnemiesCentreSecond,"Skeleton Mage");
                if(outcome == 1)
                {
                    Chest(GetWeaponFirstLevel(),player);
                    return LeftThird(player);
                }
                else if(outcome == 0)
                {
                    std::cout << "ZGINALES!Koniec gry." << std::endl;
                    continueThird = false;
                }
                break;
                case 2:
                //wolves
                Trap(player);
                outcome = Fight(player,listOfEnemiesCentreSecond,"Wolves");
                if(outcome == 1)
                {
                    Chest(GetWeaponFirstLevel(),player);
                    return CentreThird(player);
                }
                else if(outcome == 0)
                {
                    std::cout << "ZGINALES!Koniec gry." << std::endl;
                    continueThird = false;
                }
                
                break;
                case 3:
                //skeletons
                outcome = Fight(player,listOfEnemiesCentreSecond,"Skeletons");
                if(outcome == 1)
                {
                    Chest(GetArmorFirstLevel(),player);
                    return RightThird(player);
                }
                else if(outcome == 0)
                {
                    std::cout << "ZGINALES!Koniec gry." << std::endl;
                    continueThird = false;
                }
                break;
                case 4:
                CheckInventory(player);
                break;
                default:
                std::cout << "Nie prawidlowy wybor" << std::endl;
                break;
            }
        }
    
}
int LeftThird(Player& player)
{
    int choice;
    int outcome;
    bool continueThird = true;
    std::vector<Enemy> listOfEnemiesLeftThird;
    std::cout << "Przed toba pojawia sie grupa przeciwnikow." << std::endl;
    std::cout << "Bagna zaczynaja powoli ustepowac i przed toba zaczyna sie mniej mokry kawalek lasu" << std::endl;
    while(continueThird)
    {
        std::cout << "Masz przed soba trzy siezki" << std::endl;
        std::cout << "____________________________________________" << std::endl;
        std::cout << "|1 - Lewo  |2 - Prawo  |3- Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;
    
        switch (choice)
        {
            case 1:
            HealingShrine(player);
            outcome = Fight(player,listOfEnemiesLeftThird,"Wolves");
                if(outcome == 1)
                {
                    Chest(GetArmorFirstLevel(),player);
                    return 1;
                }
                else if(outcome == 0)
                {
                    std::cout << "ZGINALES!Koniec gry." << std::endl;
                    continueThird = false;
                }
            break;
            case 2:

            return CentreThird(player);
            continueThird = false;

            break;
            case 3:

            CheckInventory(player);

            break;
            default:

            std::cout << "Nie prawidlowy wybor" << std::endl;

            break;
        }
    }
    
}
int CentreThird(Player& player)
{
    int choice;
    int outcome;
    bool continueThird = true;
    std::vector<Enemy> listOfEnemiesCentreThird;
    std::cout << "Przed toba pojawia sie grupa przeciwnikow." << std::endl;
    std::cout << "Bagna zaczynaja powoli ustepowac i przed toba zaczyna sie mniej mokry kawalek lasu" << std::endl;
    while(continueThird)
    {
        std::cout << "Masz przed soba trzy siezki" << std::endl;
        std::cout << "__________________________________" << std::endl;
        std::cout << "|1 - Miasto |2 - Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;
    
        switch (choice)
        {
            case 1:
            outcome = Fight(player,listOfEnemiesCentreThird,"Skeletons");
                if(outcome == 1)
                {
                    Chest(GetArmorFirstLevel(),player);
                    return 1;
                    
                }
                else if(outcome == 0)
                {
                    std::cout << "ZGINALES!Koniec gry." << std::endl;
                    continueThird = false;
                }
        break;
        case 2:
            CheckInventory(player);
        break;
        default:
            std::cout << "Nie prawidlowy wybor" << std::endl;
        break;
        }
    }
}
int RightThird(Player& player)
{
     int choice;
    int outcome;
    bool continueThird = true;
    std::vector<Enemy> listOfEnemiesRightThird;
    std::cout << "Przed toba pojawia sie grupa przeciwnikow." << std::endl;
    std::cout << "Bagna zaczynaja powoli ustepowac i przed toba zaczyna sie mniej mokry kawalek lasu" << std::endl;
    while(continueThird)
    {
        std::cout << "Masz przed soba trzy siezki" << std::endl;
        std::cout << "_____________________________________________" << std::endl;
        std::cout << "|1 - Idz przed siebie  |2 - Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;
    
        switch (choice)
        {
            case 1:
                outcome = Fight(player,listOfEnemiesRightThird,"Skeletons");
                if(outcome == 1)
                {
                    Chest(GetWeaponFirstLevel(),player);
                    return 1;
                    
                }
                else if(outcome == 0)
                {
                    std::cout << "ZGINALES!Koniec gry." << std::endl;
                    continueThird = false;
                }
        break;
        case 2:
            CheckInventory(player);
        break;
        case 3:
            
        break;
        default:
            std::cout << "Nie prawidlowy wybor" << std::endl;
        break;
        }
    }
    return 0;
}
void FightingInterface(Player& player,Enemy& enemy)

{
    int choice;
    int classType;
    if(player.playerClass == "Wojownik")
    {
        classType = 1;
    }
    else if(player.playerClass == "Mag")
    {
        classType = 2;
    }
    else if(player.playerClass == "Lotr")
    {
        classType = 3;
    }
    else if(player.playerClass == "Berserker")
    {
        classType = 4;
    }
    else if(player.playerClass == "Nekromanta")
    {
        classType = 5;
    }
    else if(player.playerClass == "Lowczy")
    {
        classType = 6;
    }

    switch (classType)
    {
    case 1:
        std::cout << "_______________________________________" << std::endl;
        std::cout << "|1 - Atak |2 - Silny atak" << " |MANA: "<< player.currentMana << "/" << player.mana << "|"<< std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            Attack(player,enemy);
            break;
        case 2:
            strongAttack(player,enemy);
            break;
        default:
            break;
        }
        break;
    case 2:
        std::cout << "_______________________________________" << std::endl;
        std::cout << "|1 - Atak |2 - Kula ognia" << " |MANA: "<< player.currentMana << "/" << player.mana << "|"<< std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            Attack(player,enemy);
            break;
        case 2:
            fireBall(player,enemy);
            break;
        default:
            break;
        }
        break;
    case 3:
        std::cout << "_______________________________________" << std::endl;
        std::cout << "|1 - Atak |2 - Podstepny atak" << " |MANA: "<< player.currentMana << "/" << player.mana << "|"<< std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            Attack(player,enemy);
            break;
        case 2:
            sinisterStrike(player,enemy);
            break;
        default:
            break;
        }
        break;
        
    case 4:
        std::cout << "_______________________________________" << std::endl;
        std::cout << "|1 - Atak |2 - Silny atak" << " |MANA: "<< player.currentMana << "/" << player.mana << "|"<< std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            Attack(player,enemy);
            break;
        case 2:
            strongAttack(player,enemy);
            break;
        default:
            break;
        }
        break;
        break;
    case 5:
        std::cout << "_______________________________________" << std::endl;
        std::cout << "|1 - Atak |2 - Kula ognia" << " |MANA: "<< player.currentMana << "/" << player.mana << "|"<< std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            Attack(player,enemy);
            break;
        case 2:
            fireBall(player,enemy);
            break;
        default:
            break;
        }
        break;
    case 6:
        std::cout << "_______________________________________" << std::endl;
        std::cout << "|1 - Atak |2 - Salwa lowcy" << " |Mana: "<< player.currentMana << "/" << player.mana << "|"<< std::endl;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            Attack(player,enemy);
            break;
        case 2:
            hunterShot(player,enemy);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
}
void HealingShrine(Player& player)
{
    std::cout << "Napotykasz swiete leczace miejsce." << std::endl;
    std::cout << "W tej okolicy to jeden z nielicznych sposobow, aby dodac sobie troche sil." << std::endl;
    std::cout << player.currentHealth << "/" << player.health << std::endl;
    std::cout << player.currentMana << "/" << player.mana << std::endl;
    player.currentHealth += 10;
    player.currentMana += 20;

}
int Crypt(Player& player)
{
    int choice;
    int outcome;
    bool continueSecond = true;
    std::vector<Enemy> listOfEnemiesCrypt;
    std::cout << "Po walce przechodzisz dalej w glad krypty." << std::endl;
    std::cout << "Wchodzisz do ostatniego pomieszczenia z grobowcami, gdzie stoi jakas postac." << std::endl;
    std::cout << "Ludzki szkielet w pelnej zbroi zbliza sie do ciebie powoli..." << std::endl;
    while(continueSecond)
    {
        
        std::cout << "______________________________________________________" << std::endl;
        std::cout << "|1 - Walka |2 - Uciekaj! |3 - Sprawdz ekwipunek" << std::endl;
        std::cin >> choice;

            switch (choice)
            {
            case 1:
               
                outcome = Fight(player,listOfEnemiesCrypt,"Skeleton Warrior");
                if(outcome == 1)
                {
                    Chest(GetWeaponFirstLevel(),player);
                    return LeftSecondCleared(player);
                    
                }
                else if(outcome == 0)
                {
                    std::cout << "ZGINALES!Koniec gry." << std::endl;
                }
                continueSecond = false;
                break;
            case 2:
                
                
                return LeftSecondCleared(player);
                continueSecond = false;
                break;
            case 3:
                CheckInventory(player);
                
            break;
            default:
            std::cout << "Nie prawidlowy wybor" << std::endl;
                break;
            }
    }
}
#endif