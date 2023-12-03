#pragma once
#include <iostream>

class Classe
{
    double _min, _max;
    unsigned _qte = 0;
public:
    Classe( double a,  double b) : _min(a), _max(b)
    {
        if(_min > _max)
        {
            std::swap(_min, _max);
        }
    }


    double getBorneInf() const
    {
        return _min;
    }

    double getBorneSup() const
    {
        return _max;
    }

    double getQuantite() const
    {
        return _qte;
    }


    void setBorneInf(double a) 
    {
        _min = a;
    }

    void setBorneSup(double a) 
    {
        _max = a;
    }

    void setQuantite(double a) 
    {
        _qte = a;
    }

    void ajouter()
    {
        _qte++;
    }
};