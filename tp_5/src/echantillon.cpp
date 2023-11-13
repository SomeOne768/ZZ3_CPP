#include "echantillon.hpp"
#include <algorithm>

unsigned int Echantillon::getTaille() const
{
    return v.size();
}

void Echantillon::ajouter(float x)
{
    v.push_back(Valeur{x});
    // v.push(Valeur{x});
}

const Valeur &Echantillon::getMinimum() const
{
    return *std::min_element(v.begin(), v.end());
    // return v.top();
}

const Valeur &Echantillon::getMaximum() const
{
    return *std::max_element(v.begin(), v.end());
}