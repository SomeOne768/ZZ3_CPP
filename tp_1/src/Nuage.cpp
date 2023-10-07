#include "Nuage.hpp"
#include <cmath>

Nuage::Nuage()
{
}

Nuage::~Nuage()
{
}

void Nuage::ajouter(Point &p)
{
    v.push_back(&p);
}

unsigned int Nuage::size() const
{
    return v.size();
}

Nuage::const_iterator Nuage::begin() const
{
    return v.begin();
}

Nuage::const_iterator Nuage::end() const
{
    return v.end();
}

Cartesien barycentre(const Nuage &n)
{
    double x = 0,
           y = 0;
    int count = 0;
    Nuage::const_iterator it = n.begin();
    Cartesien parcourir;
    while (it != n.end())
    {
        (*it)->convertir(parcourir);
        x += parcourir.getX();
        y += parcourir.getY();
        count++;
        it++;
    }

    return Cartesien{x / count, y / count};
}

Cartesien BarycentreCartesien::operator()(const Nuage &n)
{
    return barycentre(n);
}

Polaire BarycentrePolaire::operator()(const Nuage &n)
{
    double  x = 0,
            y = 0;
    
    int count = 0;
    for(Nuage::const_iterator it=n.begin(); it!=n.end(); it++)
    {
        Cartesien temp;
        (*it)->convertir(temp);
        x += temp.getX();
        y += temp.getY();
        count++;
    }

    double  theta = atan(y/x) / M_PI * 180,
            rayon = sqrt(x*x + y*y) / count;
    Polaire p{theta, rayon};
    return p;
}