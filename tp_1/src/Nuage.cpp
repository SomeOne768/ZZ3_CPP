#include "Nuage.hpp"


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
    double  x = 0,
            y = 0;
    int count = 0;
    Nuage::const_iterator it = n.begin();
    Cartesien parcourir;
    while(it != n.end())
    {
        (*it)->convertir(parcourir);
        x += parcourir.getX();
        y += parcourir.getY();
        count++;
        it++;
    }

    return Cartesien{x/count, y/count};
}