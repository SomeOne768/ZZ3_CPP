#pragma once

class Classe
{
private:
    double min, max;
    unsigned int qty = 0;

public:
    Classe(double a, double b)
    {
        if (a < b)
        {
            min = a;
            max = b;
        }
        else
        {
            min = b;
            max = a;
        }
    }
    ~Classe() = default;

    double getBorneInf() const
    {
        return min;
    }

    double getBorneSup() const
    {
        return max;
    }

    unsigned int getQuantite() const
    {
        return qty;
    }

    void setBorneInf(double x) 
    {
        min = x;
    }

    void setBorneSup(double x) 
    {
        max = x;
    }

    void setQuantite(unsigned int n) 
    {
        qty = n;
    }

    void ajouter()
    {
        qty++;
    }
};
