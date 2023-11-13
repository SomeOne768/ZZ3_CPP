#include "echantillon.hpp"

unsigned int Echantillon::getTaille() const
{
    return v.size();
}

void Echantillon::ajouter(float x)
{
    v.push(Valeur{x});
}

const Valeur Echantillon::getMinimum() const
{
    return v.top();
}