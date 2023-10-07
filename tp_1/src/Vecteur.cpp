#include "Vecteur.hpp"

template <typename T>
Vecteur<T>::Vecteur()
{
    tab = nullptr;
    try
    {
        _taille = 10;
        tab = new T[_taille];
    }
    catch (std::bad_alloc &e)
    {
        _taille = 0;
        std::cerr << e.what();
    }
}

template <typename T>
Vecteur<T>::~Vecteur()
{
    if (tab)
    {
        delete[] tab;
    }
}

template <typename T>
Vecteur<T>::Vecteur(const Vecteur<T> &v)
{
    tab = new T[v._taille];
    for (unsigned int i = 0; i < v._taille; i++)
    {
        tab[i] = v.tab[i];
    }
    _taille = v._taille;
}

template <typename T>
Vecteur<T>& Vecteur<T>::operator=(const Vecteur<T> &v)
{
    if (this != &v)
    {
        this.~Vecteur<T>();
        tab = new T[v._taille];
        _taille = v._taille;
        for (unsigned int i = 0; i < v._taille; i++)
        {
            tab[i] = v.tab[i];
        }
    }

    return *this;
}