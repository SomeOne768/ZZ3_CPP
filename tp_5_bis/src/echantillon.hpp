#pragma once
#include <vector>
#include <valeur.hpp>
#include <set>
#include <stdexcept>
#include <iostream>
class Echantillon
{

    // std::vector<Valeur> _v;
    std::set<Valeur, std::less<Valeur>> _v;
public:     
    Echantillon() = default;
    unsigned getTaille() const
    {
        return _v.size();
    }

    void ajouter(Valeur &v)
    {
        _v.insert(v);
    }

    void ajouter(double v)
    {Valeur g {v};
        _v.insert(g);
    }

    const Valeur& getMinimum() const
    {
        if(_v.begin() != _v.end())
            return *_v.begin();
        
        throw std::domain_error(" r");
    }

    const Valeur& getMaximum() const
    {
        if(_v.rbegin() != _v.rend())
            return *_v.rbegin();
        
        throw std::domain_error("r");
    }


    const Valeur& getValeur(unsigned n) const
    {
        auto it = _v.begin();
        auto end = _v.end();
        unsigned i=0;
        
        while(it != end && i<n)
        {
            i++;
            it++;
        }

        if(it != end) return *it;

        throw std::out_of_range(" ");
    }

    const std::set<Valeur, std::less<Valeur>>& getValeurs() const
    {
        return _v;
    }


};