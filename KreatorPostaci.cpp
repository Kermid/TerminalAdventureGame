#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <limits>
#include "Entities.hpp"
#include "Game.hpp"
#include "Items.hpp"

Player selectedPlayer;
void Menu();
void Create(Player& player,int playerIdCounter);
void DisplayPlayers(std::vector<Player>& playerCharacters);
Player ChooseCharacter(std::vector<Player>& playerCharacters);

int main()
{
   
    Menu();
    
    return 0;
}

void Menu()
{
    int playerIdCounter = 0;
    std::vector<Player> playerCharacters;

    int choiceMenu;

    bool menuContinue = true;

    Player player = Player(1,"Kermid","Wojownik","Mezczyzna",13,5,5,5,5,50,50,true);
    playerCharacters.push_back(player);
    Character character;
    do
    {
        std::cout << "1 - Nowa gra" << std::endl;
        std::cout << "2 - Wczytaj gre" << std::endl;
        std::cout << "3 - Pokaz postacie" << std::endl;
        std::cout << "4 - Wyjdz z gry" << std::endl;
        
        std::cin >> choiceMenu;
    //obsluga blednego inputu 
    if(std::cin.fail())
    {   //czyszczenie inputu
        std::cin.clear();
        //ignoworwanie calego imputu az do nastepnej linii
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
    }
    switch(choiceMenu)
    {
        case 1:
            if(playerCharacters.empty())
            {
                playerIdCounter++;
                Create(player,playerIdCounter);
                playerCharacters.push_back(player);
            }
            else
            {
                int choiceGame;
                std::cout << "1 - Stworz nowa postac" << std::endl;
                std::cout << "2 - Wybierz postac do gry" << std::endl;
                std::cin >> choiceGame;
                switch(choiceGame)
                {
                    case 1:
                         playerIdCounter++;
                         Create(player,playerIdCounter);
                         playerCharacters.push_back(player);
                    break;
                    case 2:
                        selectedPlayer = ChooseCharacter(playerCharacters);
                        FirstLevel(selectedPlayer,character);
                        menuContinue = false;
                    break;
                    default:
                         std::cout << "Wybierz opcje od 1-4" << std::endl;
                    break;
                    
                }
            }
        break;
        case 2:
        break;
        case 3:

            DisplayPlayers(playerCharacters);
        
        break;
        case 4:
            menuContinue = false;
        break;
        default:
            std::cout << "Wybierz opcje 1 - 4" << std::endl;
    }
    }while(menuContinue);


}
void Create(Player &player,int playerIdCounter)
{
    
    int playerClass;
    bool playerClassBool = true;
    char temp;
    int playerStartPoints = 8;

    std::cin.ignore();
    std::cout << "Podaj nazwe swojej postaci" << std::endl;
    std::getline(std::cin,player.name);

    std::cout << "Podaj klase swojej postaci 1-6" << std::endl;
    std::cout << "1 - Wojownik" << std::endl;
    std::cout << "2 - Mag" << std::endl;
    std::cout << "3 - Lotr" << std::endl;
    std::cout << "4 - Berserker" << std::endl;
    std::cout << "5 - Nekromanta" << std::endl;
    std::cout << "6 - Lowczy" << std::endl;

    std::cin >> playerClass;
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        if(playerClass >= 1 && playerClass <= 6)
    {

    while(playerClassBool)
    {

        switch (playerClass)
    {
    case 1:
        player.playerClass = "Wojownik";
        player.armor = 3;
        player.intelligence = 2;
        player.agility = 3;
        player.stamina = 7;
        player.strenght = 7;
        player.speed = 4;
        player.health = 10 * player.stamina;
        player.mana = 10 * player.intelligence;
        playerClassBool = false;
        break;
    case 2:
        player.playerClass = "Mag";
        player.armor = 1;
        player.intelligence = 7;
        player.stamina = 2;
        player.agility = 2;
        player.strenght = 2;
        player.speed = 3;
        player.health = 10 * player.stamina;
        player.mana = 10 * player.intelligence;
        playerClassBool = false;
        break;
    case 3:
        player.playerClass = "Lotr";
        player.armor = 1;
        player.intelligence = 3;
        player.stamina = 3;
        player.agility = 6;
        player.strenght = 4;
        player.speed = 6;
        player.health = 10 * player.stamina;
        player.mana = 10 * player.intelligence;
        playerClassBool = false;
    break;
    case 4:
        player.playerClass = "Berserker";
        player.armor = 0;
        player.intelligence = 2;
        player.stamina = 4;
        player.stamina = 3;
        player.strenght = 9;
        player.speed = 4;
        player.health = 10 * player.stamina;
        player.mana = 10 * player.intelligence;
        playerClassBool = false;
    break;
    case 5:
        player.playerClass = "Nekromana";
        player.armor = 2;
        player.intelligence = 7;
        player.stamina = 3;
        player.strenght = 2;
        player.speed = 3;
        player.health = 10 * player.stamina;
        player.mana = 10 * player.intelligence;
        playerClassBool = false;
        break;
    case 6:
        player.playerClass = "Lowczy";
        player.armor = 1;
        player.intelligence = 3;
        player.stamina = 4;
        player.strenght = 3;
        player.speed = 5;
        player.health = 10 * player.stamina;
        player.mana = 10 * player.intelligence;
        playerClassBool = false;
        break;
    default:
        std::cout << "Wybierz poprawna opcje" << std::endl;
        break;
    }
    }
    }
    }
    
    while(true)
    {
        
        std::cout << "Wybierz plec" << std::endl;
        std::cout << "M - Mezczyzna" << std::endl;
        std::cout << "W - Kobieta" << std::endl;

        std::cin >> temp;

        if(temp == 'w' || temp == 'm' || temp == 'W' || temp == 'M')
        {
            player.gender = temp;
            break;
        }
        else
        {
            std::cout << "Wybierz odpowiednia opcje" << std::endl;
        }
    }

        player.playerId = playerIdCounter;
        int choicePoints;
    do
    {

        std::cout << "Rozdysponuj punkty postaci." << std::endl;
        std::cout << "Zdrowie: " << player.health << " Mana: " << player.mana << std::endl;
        std::cout << "Ilosc punktow: " << playerStartPoints << std::endl;
        std::cout << "1 - Sila: " << player.strenght << std::endl;
        std::cout << "2 - Zrecznosc: " << player.agility << std::endl;
        std::cout << "3 - Inteligencja: " << player.intelligence << std::endl;
        std::cout << "4 - Wytrzymalosc: " << player.stamina << std::endl;

        std::cin >> choicePoints;
         //obsluga blednego inputu 
         if(std::cin.fail())
            {   //czyszczenie inputu
            std::cin.clear();
            //ignoworwanie calego imputu az do nastepnej linii
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
            }
        switch (choicePoints)
        {
            case 1:
            player.strenght++;
            playerStartPoints--;
            break;
            case 2:
            player.agility++;
            playerStartPoints--;
            break;
            case 3:
            player.intelligence++;
            player.mana = 10 * player.intelligence;
            playerStartPoints--;
            break;
            case 4:
            player.stamina++;
            player.health = 10 * player.stamina;
            playerStartPoints--;
            
            break;
        
        default:
            std::cout << "Wybierz poprawna opcje!" << std::endl;
            break;
        }
    } while (playerStartPoints > 0);
    
    
    
}
