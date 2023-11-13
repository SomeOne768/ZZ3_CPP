#include "carte.hpp"

Carte::Carte(unsigned int v) : value(v){}

unsigned int Carte::getValeur() const
{
    return value;
}