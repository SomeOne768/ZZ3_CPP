#pragma once
#include <memory>
#include <vector>
#include <iostream>


class Ressource
{

    unsigned int stock;
public:
    Ressource(unsigned int);
    void consommer(unsigned int);
    unsigned int getStock() const;
};

using ressources_t = std::vector<std::weak_ptr<Ressource>>;

std::ostream& operator<<(std::ostream &oss, const ressources_t &r);