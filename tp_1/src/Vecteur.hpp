#ifndef VECTEUR_AZ_2023ZZ3
#define VECTEUR_AZ_2023ZZ3
#include <iostream>

template <typename T>
class Vecteur{

    T *tab;
    unsigned int _taille;
public:
    Vecteur<T>();
    ~Vecteur<T>();
    Vecteur<T>(const Vecteur<T>&);
    Vecteur<T>& operator=(const Vecteur<T>&);
};

#endif