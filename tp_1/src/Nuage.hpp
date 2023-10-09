#ifndef NUAGE_AZ_2023ZZ3
#define NUAGE_AZ_2023ZZ3
#include <vector>
#include <Point.hpp>
#include <Polaire.hpp>
#include <Cartesien.hpp>

class Nuage
{
    using Points = std::vector<Point*>;
    Points v;

public:
    using const_iterator = Points::const_iterator;
    Nuage();
    ~Nuage();
    void ajouter(Point &);
    unsigned int size() const;
    const_iterator begin() const;
    const_iterator end() const;
};

Cartesien barycentre(const Nuage &n);

class BarycentreCartesien
{

public:
    BarycentreCartesien(){}
    ~BarycentreCartesien(){}
    Cartesien operator()(const Nuage &n);
};

class BarycentrePolaire
{

public:
    BarycentrePolaire(){}
    ~BarycentrePolaire(){}
    Polaire operator()(const Nuage &n);
};

#endif