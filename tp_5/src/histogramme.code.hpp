#include "histogramme.hpp"
#include <algorithm>

template <class T>
Histogramme<T>::Histogramme(double borneInf, double borneSup, unsigned int nbClasses)
{
    double delta = borneSup - borneInf;
    delta /= nbClasses;

    for (unsigned int i = 0; i < nbClasses; i++)
        addClasse({borneInf + i * delta, borneInf + (i + 1) * delta});
}

template <class T>
const T &Histogramme<T>::getClasses() const
{
    return classes;
}

template <class T>
void Histogramme<T>::ajouter(const Echantillon& e)
{
    for(unsigned i=0; i<e.getTaille(); i++)
    {
        const Valeur &v = e.getValeur(i);
        
        auto it = std::find_if(classes.begin(), classes.end(), [&v](const Classe &c){
            return c.getBorneInf() <= v.getNombre() && v.getNombre() < c.getBorneSup();
        });
        
        if(it != classes.end())
            it->ajouter();
    }
}
template<>
void Histogramme<std::vector<Classe>>::addClasse(const Classe &c) 
{
    classes.push_back(c);
}

template<class T>
void Histogramme<T>::addClasse(const Classe &c) 
{
    classes.insert(c);
}