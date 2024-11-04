#ifndef INN_HPP
#define INN_HPP
#include "Entities.hpp"

void GameOfBones(Player& player)
{
    int firstBone;
    int SecondBone;
    int ThirdBone;
    int choice;
    int money;
    while(true)
    {

    std::cout << "Masz " << player.gold << " zlota." << std::endl;
    std::cout << "Podaj ile stawiasz pieniedzy." << std::endl;
    std::cin >> money;
    
    if(money > player.gold)
    {
        std::cout << "Nie stac cie na taki zaklad." << std::endl;
        continue;
    }
    else if(player.gold == 0)
    {
        std::cout << "Nie stac cie na gre w kosci" << std::endl;
        break;
    }
    else
    {
        player.gold -= money;
        firstBone = RandomNumber(6);
        SecondBone = RandomNumber(6);
        ThirdBone = RandomNumber(6);

        int sumOfPlayer = firstBone + SecondBone + ThirdBone;

        firstBone = RandomNumber(6);
        SecondBone = RandomNumber(6);
        ThirdBone = RandomNumber(6);

        int sumOfOpponent = firstBone + SecondBone + ThirdBone;

        if(sumOfPlayer > sumOfOpponent)
        {
            std::cout << "Twoje kosci: " << sumOfPlayer << std::endl;
            std::cout << "Kosci przeciwnika: " << sumOfOpponent << std::endl;
            std::cout << "Wygrywasz!" << std::endl;
            std::cout << "Otrzymujesz: " << money + 1 << std::endl;
            player.gold += money + 1;
        }
        else if(sumOfPlayer < sumOfOpponent)
        {
            std::cout << "Twoje kosci: " << sumOfPlayer << std::endl;
            std::cout << "Kosci przeciwnika: " << sumOfOpponent << std::endl;
            std::cout << "Przegrywasz!" << std::endl;
            std::cout << "Przeciwnik otrzymuje: " << money + 1 << std::endl;
        }
        else if(sumOfPlayer == sumOfOpponent)
        {
            std::cout << "Twoje kosci: " << sumOfPlayer << std::endl;
            std::cout << "Kosci przeciwnika: " << sumOfOpponent << std::endl;
            std::cout << "Remis!" << std::endl;
            std::cout << "Pieniadze wracaja do wlascicieli." << std::endl;
        }
        std::cout << "Grasz dalej?" << std::endl;

        std::cout << "1 - Tak 2 - Nie" << std::endl;

        std::cin >> choice;

        if(choice >= 1 && choice <= 2)
        {
            if(choice == 2)
            {
                break;
            }
            else
            {
                std::cout << "Grasz dalej!" << std::endl;
            }
        }
    }

    
    

    }
}
void OrderBeer(Player& player)
{
    player.gold -= 1;
    player.currentMana += 20;
    if(player.mana - player.currentMana < 20)
    {
        player.currentMana += player.mana- player.currentMana;
    }
    else
    {
        player.currentMana += 20;
    }
    ShowStats(player);
}
void OrderMeal(Player& player)
{
    player.gold -= 1;
    if(player.health - player.currentHealth < 12)
    {
        player.currentHealth += player.health - player.currentHealth;
    }
    else
    {
        player.currentHealth += 12;
    }
    ShowStats(player);

}
void Inn(Player& player)
{
    int choice;
    bool InnContinue = true;
    std::cout << "Witaj w karczmie!" << std::endl;
    while(InnContinue)
    {
        std::cout << "Co podac?" << std::endl;
        std::cout << "1 - Piwo +20 Many |1 Zlota" << std::endl;
        std::cout << "2 - Jedzenie +20 Punktow zdrowia |1 Zlota" << std::endl;
        std::cout << "3 - Zagraj w Kosci." << std::endl;
        std::cout << "4 - Wyjdz z karczmy" << std::endl;

        std::cin >> choice;

        switch (choice)
        {
        case 1:
            OrderBeer(player);
        break;
        case 2:
            OrderMeal(player);
        break;
        case 3:
            GameOfBones(player);
        break;
        case 4:
            InnContinue = false;
        break;
        
        default:
        std::cout << "Nieprawidlowa opcja!" << std::endl;
            break;
        }

        
    }
}
#endif 
