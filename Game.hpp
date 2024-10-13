#ifndef GAME_HPP
#define GAME_HPP
#include "Entities.hpp"
#include "Items.hpp"
#include <iostream>
#include <string>



void FirstLevel(Player player)
{
    int choice;
    std::cout << "Wkraczasz do ponurych bagien, gdzie ziemia jest miekka i lepka, a kazdy krok wpada w glebokie bloto." << std::endl;
    std::cout << "Woda stoi w kaluzach, a gesta mgla spowija wszystko wokol, ograniczajac widocznosc." << std::endl;
    std::cout << "W powietrzu czuc zapach gnijacych roslin, a ciche odglosy bulgoczacej wody budza niepokoj." << std::endl;
    std::cout << "Musisz uwazac, bo w bagnach wszystko wydaje sie niebezpieczne, a droga przed toba jest zdradliwa." << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Masz przed sobą trzy sieżki" << std::endl;
    std::cout << "1 - Lewo" << std::endl;
    std::cout << "2 - Prosto" << std::endl;
    std::cout << "3 - Prawo" << std::endl;
    
    std::cin >> choice;
    switch(choice)
    {
        case 1:
            std::cout << "Wybrales pierwsza droge" << std::endl;

        break;
        case 2:
            std::cout << "Wybrales druga droge" << std::endl;
        break;
        case 3:
            std::cout << "Wybrales trzecia droge" << std::endl;
        break;
    }
}
#endif