#include "usine.hpp"


UsineCarte::UsineCarte()
{
    max = 52;
}

UsineCarte::UsineCarte(unsigned int n)
{
    max = n;
}

std::unique_ptr<Carte> UsineCarte::getCarte()
{
    if(number >= max)
        return nullptr;
    return std::unique_ptr<Carte>{new Carte{number++}};
}

bool UsineCarte::end() const
{
    return number == max;
}