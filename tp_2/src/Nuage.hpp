#ifndef NUAGE_AZ_2023ZZ3
#define NUAGE_AZ_2023ZZ3
#include <vector>
#include "Point.hpp"
#include "Polaire.hpp"
#include "Cartesien.hpp"

template <typename point> // Possibilité d'utiliser Point voir autre commentaire
class Nuage
{
    using Points = std::vector<point*>;
    Points v;
    // ::Point p; => Cas où on utilise le même nom pour le template
    // ::std::vector;

public:
    Nuage() = default;
    ~Nuage() = default;
    void ajouter(point);
    unsigned int size() const;

    // using const_iterator = std::vector<point*>::const_iterator;
    using const_iterator = typename Points::const_iterator;
    const_iterator begin() const;
    const_iterator end() const;
};

#include "Nuage.code.hpp"

// Cartesien barycentre(const Nuage<T> &n);

// class BarycentreCartesien
// {

// public:
//     BarycentreCartesien(){}
//     ~BarycentreCartesien(){}
//     Cartesien operator()(const Nuage &n);
// };

// class BarycentrePolaire
// {

// public:
//     BarycentrePolaire(){}
//     ~BarycentrePolaire(){}
//     Polaire operator()(const Nuage &n);
// };

#endif