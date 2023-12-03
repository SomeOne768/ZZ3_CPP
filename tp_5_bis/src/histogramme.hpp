
#pragma once
#include "classe.hpp"
#include <set>
#include "echantillon.hpp"
#include <iostream>
#include <algorithm>
#include <map>


bool operator<(const Classe &c1, const Classe &c2)
{
    return c1.getBorneInf() < c2.getBorneInf();
}

bool operator>(const Classe &c1, const Classe &c2)
{
    return c1.getBorneSup() > c2.getBorneSup();
}


template <typename T>
class ComparateurQuantite
{
public:
    bool operator()(const T &c1, const T &c2) const
    {
        throw std::exception();
    }
};

template <>
class ComparateurQuantite<Classe>
{
public:
    bool operator()(const Classe &c1, const Classe &c2) const
    {
        if(c1.getQuantite() > c2.getQuantite())
            return true;
        else if(c1.getQuantite() == c2.getQuantite())
            return c1 < c2;
        
        return false;
    }
};











template <typename COMP = std::less<Classe>>
class Histogramme
{
    using container_t = std::set<Classe, COMP>;
    container_t classes;

    using assos_t = std::multimap<Classe, Valeur>;
    assos_t myValues;

    using iter_t = assos_t::const_iterator;

    void inserer(const Valeur &e)
    {
        auto it = std::find_if(classes.begin(),
                               classes.end(),
                               [&e](const Classe &c)
                               {
                                   return c.getBorneInf() <= e.getNombre() && e.getNombre() < c.getBorneSup();
                               });

        if (it != classes.end())
        {
            Classe c{it->getBorneInf(), it->getBorneSup()};
            c.setQuantite(it->getQuantite() + 1);
            classes.erase(it);
            classes.insert(c);
            myValues.insert(std::pair<Classe, Valeur>(c, e));
        }
    }

public:
    Histogramme(double min, double max, unsigned n)
    {
        double delta = max - min;

        for (unsigned i = 0; i < n; i++)
        {
            classes.insert(Classe{min + i * delta / n, min + (i + 1) * delta / n});
        }
    }

    template <typename COMP2>
    Histogramme(const Histogramme<COMP2> &h)
    {
        for(auto &elt : h.getClasses())
        {
            Classe c = elt;
            classes.insert(c);
        }
    }

    const container_t &getClasses() const
    {
        return classes;
    }

    void ajouter(Echantillon &e)
    {
        for (auto &elt : e.getValeurs())
        {
            inserer(elt);
        }
    }

    void ajouter(double e)
    {
        Valeur elt{e};
        inserer(elt);
    }

    
    const assos_t& getValeurs() const 
    {
        return myValues;
    }

    std::pair<iter_t, iter_t> getValeurs(const Classe &c) const 
    {
        return myValues.equal_range(c);
    }
};

using Histo = Histogramme<>;
using histo_t = Histogramme<>;