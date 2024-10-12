#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <limits>

class Player;
class Character{
    public:
        std::string name;
        int strenght;
        int agility;
        int stamina;
        int intelligence;
        int armor;
        int health;
        bool alive = true;
        Character(std::string name,int strenght,int agility,int stamina,int intelligence,int armor,int health,bool alive)
        {
            this->name = name;
            this->strenght = strenght;
            this->agility = agility;
            this->stamina = stamina;
            this->intelligence = intelligence;
            this->armor = armor;
            this->health = health;
            this->alive = alive;
        }
        Character();
   /* int Attack(Character entity,Player player)
    {
       return player.health -= entity.strenght + 2 - player.armor;
    }
    int Attack(Character entity,Character entity2)
    {
       return entity2.health -= entity.strenght + 2 - entity2.armor;
    }
    int Attack(Player player, Character entity)
    {
       return entity.health -= player.strenght + 2 - entity.armor;
    }
    bool Die(Player player)
    {
        if(player.health <= 0)
        {
            return true;
        }
    }
    bool Die(Character entity)
    {
        if(entity.health <= 0)
        {
            return true;
        }
    }*/
};
class Player : public Character{
    public:
            std::string gender;
            std::string playerClass;
            int playerId;
            Player(int playerId,std::string name,std::string playerClass,std::string gender,int strenght,int agility,int stamina,int intelligence,int armor,int health,bool alive)
            {
                this->name = name;
                this->playerId = playerId;
                this->playerClass = playerClass;
                this->gender = gender;
                this->strenght = strenght;
                this->agility = agility;
                this->stamina = stamina;
                this->intelligence = intelligence;
                this->armor = armor;
                this->health = health;
                this->alive = alive;
            }
            Player();
};

void Menu();
void Create(Player& player,int playerIdCounter);
void DisplayPlayers(std::vector<Player>& playerCharacters);
void SaveCharacter(std::vector<Player>& playerCharacters);
void ChooseCharacter(std::vector<Player>& playerCharacters, Player player);

int main()
{
    Menu();
    return 0;
}

void Menu()
{
    int playerIdCounter = 0;
    std::vector<Player> playerCharacters;

    int choice;

    bool menuContinue = true;

    Player player;

    Player *pPlayer = &player;
    Player *selectedPlayer;

    do
    {
        std::cout << "1 - Nowa gra" << std::endl;
        std::cout << "2 - Wczytaj gre" << std::endl;
        std::cout << "3 - Pokaz postacie" << std::endl;
        std::cout << "4 - Wyjdz z gry" << std::endl;
        
        std::cin >> choice;
    //obsluga blednego inputu 
    if(std::cin.fail())
    {   //czyszczenie inputu
        std::cin.clear();
        //ignoworwanie calego imputu az do nastepnej linii
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
    }
    switch(choice)
    {
        case 1:
        int choice;
            if(playerCharacters.empty())
            {
                playerIdCounter++;
                Create(player,playerIdCounter);
                playerCharacters.push_back(player);
            }
            else
            {
                int choice;
                std::cout << "1 - Stworz nowa postac" << std::endl;
                std::cout << "2 - Wybierz postac do gry" << std::endl;
                std::cin >> choice;
                switch(choice)
                {
                    case 1:
                         playerIdCounter++;
                         Create(player,playerIdCounter);
                         playerCharacters.push_back(player);
                    break;
                    case 2:
                        ChooseCharacter(playerCharacters);
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
        playerClassBool = false;
        break;
    case 2:
        player.playerClass = "Mag";
        playerClassBool = false;
        break;
    case 3:
        player.playerClass = "Lotr";
        playerClassBool = false;
    break;
    case 4:
        player.playerClass = "Berserker";
        playerClassBool = false;
    break;
    case 5:
        player.playerClass = "Nekromana";
        playerClassBool = false;
        break;
    case 6:
        player.playerClass = "Lowczy";
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
        player.strenght = 5;
        player.agility = 5;
        player.stamina = 5;
        player.intelligence = 5;
        player.armor = 1;
        player.health = 300;
        int choicePoints;
    do
    {

        std::cout << "Rozdysponuj punkty postaci." << std::endl;
        std::cout << "Ilosc punktow: " << playerStartPoints << std::endl;
        std::cout << "1 - Sila: " << player.strenght << std::endl;
        std::cout << "2 - Zrecznosc: " << player.agility << std::endl;
        std::cout << "3 - Inteligencja: " << player.intelligence << std::endl;
        std::cout << "4 - Wytrzymalosc: " << player.stamina << std::endl;
        std::cout << "5 - Zdrowie: " << player.health << std::endl;

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
            playerStartPoints--;
            break;
            case 4:
            player.stamina++;
            playerStartPoints--;
            break;
            case 5:
            player.health += 10;
            playerStartPoints--;
            break;
        
        default:
            std::cout << "Wybierz poprawna opcje!" << std::endl;
            break;
        }
    } while (playerStartPoints > 0);
    
    
    
}
void DisplayPlayers(std::vector<Player>& playerCharacters)
{
    int counter = 0;
    if(playerCharacters.empty())
    {
        std::cout << "Nie ma jeszcze postaci." << std::endl;
    }
    else
    {
        std::cout << "Lista postaci:" << std::endl;
        for(const Player player : playerCharacters)
        {
            counter++;
            std::cout << "#" << counter << " Imie: " << player.name << " Klasa: "<< player.playerClass << " Plec: " << player.gender << " Zdrowie: " << player.health << std::endl;
            std::cout << "S: " << player.strenght << " A: " << player.agility << " I: " << player.intelligence << " S: " << player.stamina << std::endl;
            std::cout << "" << std::endl;
        }
    }
}

Player* ChooseCharacter(std::vector<Player>& playerCharacters)
{
    if(playerCharacters.empty())
    {
        std::cout << "Nie ma graczy do wybrania" << std::endl;
        return nullptr;
    }
    else
    {
        int choice;

        std::cout << "Wybierz numer gracza." << std::endl;
        DisplayPlayers(playerCharacters);

        std::cin >> choice;

        return &playerCharacters[choice-1];
    }
}
//konstruktory
Player::Player()
{
}

Character::Character()
{
}
