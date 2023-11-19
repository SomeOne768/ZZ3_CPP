#pragma once
#include <vector>
#include "valeur.hpp"
#include <queue>
#include <stdexcept>
#include <exception>

// auto mini = [](const Valeur &v1, const Valeur &v2)
// {
//     return v1.getNombre() < v2.getNombre();
// };

class ValeurMinFoncteur
{

public:
    bool operator()(const Valeur &v1, const Valeur &v2) const
    {
        return v1.getNombre() < v2.getNombre();
    }
};

class Echantillon
{
    std::vector<Valeur> v;
    // std::priority_queue<Valeur, std::deque<Valeur> ,ValeurMinFoncteur> v;

public:
    unsigned int getTaille() const;
    void ajouter(float);
    const Valeur &getMinimum() const;
    const Valeur &getMaximum() const;
    const Valeur &getValeur(unsigned int) const;

    class MinMaxException : public std::domain_error
    {

    public:
        MinMaxException() : std::domain_error("blabla") {}
        const char *what() const noexcept override
        {
            return "Nothing to say...";
        }
    };
};