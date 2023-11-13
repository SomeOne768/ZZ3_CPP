#include "carte.hpp"

unsigned int Carte::compteur = 0;

Carte::Carte(unsigned int v) : value(v){
    compteur++;
}

Carte::~Carte()
{
    compteur--;
}

unsigned int Carte::getValeur() const
{
    return value;
}

unsigned int Carte::getCompteur()
{
    return compteur;
}