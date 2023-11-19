#pragma once
#include "classe.hpp"
#include <vector>
#include "echantillon.hpp"
#include <set>

template <class T = std::set<Classe>>
class Histogramme
{
    T classes;
    void addClasse(const Classe &c);
public:
    Histogramme(double borneInf, double borneSup, unsigned int nbClasses);
    const T& getClasses() const;
    void ajouter(const Echantillon&);
};

using Histo = Histogramme<std::vector<Classe>>;

#include <histogramme.code.hpp>