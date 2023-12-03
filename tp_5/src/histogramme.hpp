#pragma once
#include "classe.hpp"
#include <vector>
#include "echantillon.hpp"
#include <set>
#include <iostream>
#include <map>


// Pour rempalcer la lambda
// class MyF
// {
// public:
//     Valeur _v;
//     MyF(Valeur v) : _v(v) {}

//     bool operator()(const Classe &c) const
//     {
//          return c.getBorneInf() <= _v.getNombre() && _v.getNombre() < c.getBorneSup();
//     }
// };


using iter_t = std::multimap<const Classe, Valeur>::const_iterator;
template <typename Foncteur = std::less<Classe>>
class Histogramme
{
    std::set<Classe, Foncteur> classes;
    void addClasse(const Classe &c);
    std::multimap<const Classe, Valeur> valueMap;

public:
    Histogramme() = default;
    template <typename F>
    Histogramme(const Histogramme<F> &);
    Histogramme(double borneInf, double borneSup, unsigned int nbClasses);
    const std::set<Classe, Foncteur> &getClasses() const;
    void ajouter(const Echantillon&);
    void ajouter(double);
    const std::multimap<const Classe, Valeur> getValeurs() const;
    std::pair<iter_t, iter_t> getValeurs(const Classe&) const;
    
};

using Histo = Histogramme<>;

#include "histogramme.code.hpp"