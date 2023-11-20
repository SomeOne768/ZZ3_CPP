#pragma once
#include "classe.hpp"
#include <vector>
#include "echantillon.hpp"
#include <set>
#include <iostream>

template <typename Foncteur = std::less<Classe>>
class Histogramme
{
    std::set<Classe, Foncteur> classes;
    void addClasse(const Classe &c);

public:
    Histogramme(double borneInf, double borneSup, unsigned int nbClasses);
    const std::set<Classe, Foncteur> &getClasses() const;
    void ajouter(const Echantillon&);
};

using Histo = Histogramme<>;

#include "histogramme.code.hpp"