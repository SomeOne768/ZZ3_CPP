#ifndef VECTEUR_CODE_AZ_2023ZZ3
#define VECTEUR_CODE_AZ_2023ZZ3

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
Vecteur<T> &Vecteur<T>::operator=(const Vecteur<T> &v)
{
    if (this != &v)
    {
        delete[] tab;
        tab = new T[v._taille];
        _taille = v._taille;
        for (unsigned int i = 0; i < v._taille; i++)
        {
            tab[i] = v.tab[i];
        }
    }

    return *this;
}

template <typename T>
const T &Vecteur<T>::operator[](unsigned int i) const
{
    if (i >= _taille || i < 0)
        throw std::exception();

    return tab[i];
}

template <typename T>
T &Vecteur<T>::operator[](unsigned int i)
{
    if (i >= _taille || i < 0)
        throw std::exception();

    return tab[i];
}


template <typename T>
std::ostream &Vecteur<T>::operator<<(std::ostream &oss)
{
    for (unsigned int i = 0; i < _taille; i++)
    {
        oss << tab[i] << " ";
    }
    oss << std::endl;
    return oss;
}

template <typename T>
unsigned int Vecteur<T>::size() const
{
    return _taille;
}

template <typename T>
std::ostream &operator<<(std::ostream &oss, const Vecteur<T> &v)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        oss << v[i] << " ";
    }
    oss << std::endl;
    return oss;
}

template <typename T>
void Vecteur<T>::increaseTab(unsigned int n)
{
    delete[] tab;
    tab = new T[n];
    _taille = n;
}

template <typename T>
Vecteur<T> &operator+(const Vecteur<T> &v, const Vecteur<T> &v2)
{
    Vecteur<T> v3;
    T *newTab = new T[v.size() + v2.size()];
    for(auto i=0; i<v.size(); i++)
    {
        newTab[i] = v[i];
    }

    for(auto i=0; i<v2.size(); i++)
    {
        newTab[i + v.size()] = v2[i];
    }

    v3._taille = v.size() + v2.size();
    delete[] v3.tab;
    v3.tab = newTab;

    return v3;
}

template <typename T>
Vecteur<T>& Vecteur<T>::operator+(const Vecteur<T>v)
{
    T *newTab = new T[_taille + v._taille];

    for(unsigned int i=0; i<_taille; i++)
    {
        newTab[i] = tab[i];
    }

    for(unsigned int i=0; i<v.size(); i++)
    {
        newTab[i + _taille] = v[i];
    }

    delete[] tab;
    _taille = _taille + v._taille;
    tab = newTab;

    return *this;
}

unsigned int min(unsigned int a, unsigned int b)
{
    return a>b?b:a;
}


template <typename T>
T Vecteur<T>::operator*(const Vecteur<T> &v)
{
    T scalar= 0;
    for(unsigned int i=0; i<min(_taille, v.size()); i++)
    {
        scalar += tab[i] * v[i];
    }

    return scalar;
}

template <typename T>
Iterateur<T> Vecteur<T>::begin()
{
    return Iterateur{&tab[0]};
}

template <typename T>
Iterateur<T> Vecteur<T>::end()
{
    return Iterateur{&tab[_taille-1]};
}

#endif