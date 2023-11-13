#pragma once
#include <memory>
#include "ressource.hpp"

class Consommateur
{
    unsigned int need;
    std::shared_ptr<Ressource> p;

public:
    Consommateur(unsigned int n, std::shared_ptr<Ressource>&r)
    {
        need = n;
        p = r;
    }

    ~Consommateur() = default;

    void puiser()
    {   
        if(p == nullptr)
            return;

        int reste = p->getStock() - need;
        
        if(reste >= 0)
            p->consommer(need);
        else
        {
            p->consommer(p->getStock());
            p = nullptr;
        }
    }

};