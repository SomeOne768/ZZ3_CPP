#include "ressource.hpp"

Ressource::Ressource(unsigned int n) : stock(n) {}

void Ressource::consommer(unsigned int n)
{
    stock -= n;
    // stock = (stock <0)? stock : 0;
}

unsigned int Ressource::getStock() const
{
    return stock;
}


std::ostream& operator<<(std::ostream &oss, const ressources_t &r)
{
    for(const std::weak_ptr<Ressource> &elt : r)
    {
        if(!elt.expired())
            oss << elt.lock()->getStock() << " ";
        else 
            oss << "- ";
    }

    return oss;
}