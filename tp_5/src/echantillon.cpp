#include "echantillon.hpp"
#include <algorithm>

#include <stdexcept>
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
    if(v.empty())
        throw new std::domain_error("pbpbpbp");

    return *std::min_element(v.begin(), v.end());
    // return v.top();
}

const Valeur &Echantillon::getMaximum() const
{
    if(v.empty())
        throw new Echantillon::MinMaxException{};
    return *std::max_element(v.begin(), v.end());
}

const Valeur & Echantillon::getValeur(unsigned int i) const
{
    if(i>=v.size())
        throw new std::out_of_range("dddd");

    return v[i];
}