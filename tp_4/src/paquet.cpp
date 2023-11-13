#include "paquet.hpp"

void remplir(paquet_t &p, UsineCarte &u)
{
    // std::unique_ptr<Carte> c;
    // while( (c = u.getCarte()) != nullptr) p.push_back(c);

    while (!u.end())
        p.push_back(u.getCarte());
}

std::ostream &operator<<(std::ostream &oss, const paquet_t &p)
{
    for(auto &elt : p)
    {
        oss << elt->getValeur() << " ";
    }
    
    return oss;
}