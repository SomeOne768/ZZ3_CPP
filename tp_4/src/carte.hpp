#pragma once

class UsineCarte;

class Carte
{
    friend UsineCarte;
    unsigned int value;
    Carte(unsigned int);
    static unsigned int compteur;
public:
    ~Carte();
    Carte(Carte&) = delete;
    auto operator=(Carte&) = delete;

    unsigned int getValeur() const;
    static unsigned int getCompteur();
};