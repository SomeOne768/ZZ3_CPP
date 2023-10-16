#include "Nuage.hpp"
#include <cmath>
#include "Cartesien.hpp"
#include "Polaire.hpp"

template <typename point>
unsigned int Nuage<point>::size() const
{
    return v.size();
}

template <typename point>
void Nuage<point>::ajouter(const point &p)
{
    v.push_back(&p);
}

template <typename point>
typename Nuage<point>::const_iterator Nuage<point>::begin() const
{
    return v.begin();
}

template<typename point>
typename Nuage<point>::const_iterator Nuage<point>::end() const
{
    return v.end();
}

// Cartesien barycentre(const Nuage &n)
// {
//     double x = 0,
//            y = 0;
//     int count = 0;
//     Nuage::const_iterator it = n.begin();
//     Cartesien parcourir;
//     while (it != n.end())
//     {
//         (*it)->convertir(parcourir);
//         x += parcourir.getX();
//         y += parcourir.getY();
//         count++;
//         it++;
//     }

//     return Cartesien{x / count, y / count};
// }

// Cartesien BarycentreCartesien::operator()(const Nuage &n)
// {
//     return barycentre(n);
// }

// Polaire BarycentrePolaire::operator()(const Nuage &n)
// {
//     double  x = 0,
//             y = 0;

//     int count = 0;
//     for(Nuage::const_iterator it=n.begin(); it!=n.end(); it++)
//     {
//         Cartesien temp;
//         (*it)->convertir(temp);
//         x += temp.getX();
//         y += temp.getY();
//         count++;
//     }

//     double  theta = atan(y/x) / M_PI * 180,
//             rayon = sqrt(x*x + y*y) / count;
//     Polaire p{theta, rayon};
//     return p;
// }