#ifndef LOCATIONS_HPP
#define LOCATIONS_HPP
#include <iostream>


class Location
{

public:
    std::string description;
    bool hasFight;
    bool hasLoot;
};

Location generateForestArea()
{
    Location location
    int randomEvent = rand() % 100;
    if(randomEvent < 10)
    {
        location.description = "Przed Tobą rozciąga się gęsta paproć, gdzie słychać szmer....";
        location.hasFight = true;
        location.hasLoot = true;
    }
    else if(randomEvent < 20)
    {
        location.description = "Przed Tobą rozciąga się gęsty las, a światło ledwo przedziera się przez grube korony drzew. Powietrze jest wilgotne, a wokół słychać świergot ptaków i szum liści.";
        location.hasFight = false;
        location.hasLoot = false;
    }
    else if(randomEvent < 30)
    {
        location.description = "Idziesz wzdłuż strumienia, chłodna woda przepływa w pobliżu.";
        location.hasFight = false;
        location.hasLoot = true;
    }
    else if(randomEvent < 40)
    {
        location.description = "Ścieżka prowadzi przez mokradła – błoto zaczyna grzęznąć pod Twoimi stopami.";
        location.hasFight = true;
        location.hasLoot = true;
    }
    else if(randomEvent < 50)
    {
        location.description = "Wchodzisz w głębszą część lasu, gdzie zapach gnijących liści staje się bardziej intensywny. Ziemia jest pokryta grubą warstwą mokrych liści, przez które co jakiś czas coś przemyka";
        location.hasFight = true;
        location.hasLoot = true;
    }
    else if(randomEvent < 60)
    {
        location.description = "Wysokie krzewy ograniczają Ci widoczność, ale dostrzegasz ciemne cienie przemykające między drzewami. Przygotowujesz się, by ewentualnie bronić się przed dziką zwierzyną";
        location.hasFight = true;
        location.hasLoot = true;
    }
    else if(randomEvent < 70)
    {
        location.description = "Slychac trzask gdzies z lewej strony.Po chwili okazuje sie ze to zasadzka!";
        location.hasFight = true;
        location.hasLoot = true;
    }
    else if(randomEvent < 80)
    {
        location.description = "Przedzierasz się przez gęstwinę, mijając drzewa porośnięte mchem i grzyby.";
        location.hasFight = false;
        location.hasLoot = true;
    }
    else if(randomEvent < 90)
    {
        location.description = "Podczas poszukiwania jagód zauważasz duże, świeże ślady niedźwiedzia w błocie. Zanim zdołasz się wycofać, zza drzew wyłania się masywne zwierzę, które zaczyna powoli ruszać w Twoją stronę";
        location.hasFight = true;
        location.hasLoot = true;
    }
    else 
    {
        location.description = "Słyszysz szelest liści i patrzysz w górę. Między konarami dostrzegasz lisa wspinającego się na drzewo. Wydaje się, że ten fragment lasu jest pełen życia";
        location.hasFight = false;
        location.hasLoot = false;
    }
}

#endif