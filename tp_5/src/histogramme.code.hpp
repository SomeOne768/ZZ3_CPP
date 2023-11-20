#include "histogramme.hpp"
#include <algorithm>

template <typename Foncteur>
Histogramme<Foncteur>::Histogramme(double borneInf, double borneSup, unsigned int nbClasses)
{
    double delta = borneSup - borneInf;
    delta /= nbClasses;

    for (unsigned int i = 0; i < nbClasses; i++)
        addClasse({borneInf + i * delta, borneInf + (i + 1) * delta});
}

template <typename Foncteur>
const std::set<Classe, Foncteur> &Histogramme<Foncteur>::getClasses() const
{
    return classes;
}

template <typename Foncteur>
void Histogramme<Foncteur>::addClasse(const Classe &c)
{
    classes.insert(c);
}

template <typename Foncteur>
void Histogramme<Foncteur>::ajouter(const Echantillon &e)
{
    for (unsigned int i = 0; i < e.getTaille(); i++)
    {
        const Valeur &v = e.getValeur(i);
        std::set<Classe, std::less<Classe>>::iterator it = std::find_if(classes.begin(), classes.end(),
                                                                        [&v](const Classe &c)
                                                                        {
                                                                            return c.getBorneInf() <= v.getNombre() && v.getNombre() < c.getBorneSup();
                                                                        });

        if (it != classes.end())
        {
            Classe c{*it};
            c.ajouter();
            classes.erase(it);
            addClasse(c);
        }
    }
}