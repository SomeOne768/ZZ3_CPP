
#pragma once

class Valeur
{
    float v;

public:
    Valeur() : v(0) {}
    Valeur(float x) : v(x) {}

    float getNombre() const
    {
        return v;
    }

    void setNombre(float x)
    {
        v = x;
    }
};