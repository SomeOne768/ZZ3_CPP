// Gardien //---------------------------------------------------------------------------------------
#ifndef _HISTOGRAMME_HPP_
#define _HISTOGRAMME_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <iostream>
#include <map>
#include <set>
#include <classe.hpp>
#include <echantillon.hpp>

// Classe  H i s t o g r a m m e //-----------------------------------------------------------------
template <typename COMPARATEUR = std::less<Classe>> class Histogramme {
 //--------------------------------------------------------------------------------------------Types
 public:
  // using classes_t = std::vector<Classe>;
  using classes_t = std::set<Classe,COMPARATEUR>;
  using valeurs_t = std::multimap<Classe,Valeur>;
 //----------------------------------------------------------------------------------------Attributs
 private:
  double    borneInf_;
  double    borneSup_;
  classes_t classes_;
  valeurs_t valeurs_;
 //---------------------------------------------------------------------------------------Accesseurs
 public:
  double getBorneInf() const { return borneInf_; }
  double getBorneSup() const { return borneSup_; }

  const classes_t & getClasses() const { return classes_; }
  const valeurs_t & getValeurs() const { return valeurs_; }

  auto getValeurs(const Classe & classe) const // auto = std::pair<valeurs_t::const_iterator,
  { return valeurs_.equal_range(classe); }     //                  valeurs_t::const_iterator>

 //------------------------------------------------------------------------------------Constructeurs
 public:
  Histogramme(double borneInf,double borneSup,unsigned nbClasse);

  template <typename COMPARATEUR2> Histogramme(const Histogramme<COMPARATEUR2> &);
 //---------------------------------------------------------------------------------Methodes privees
 private:
  void creerClasses(unsigned);
 //-------------------------------------------------------------------------------Methodes publiques
 public:
  void ajouter(const Valeur &);
  void ajouter(const Echantillon &);
};

// Implementation  H i s t o g r a m m e //---------------------------------------------------------

//--------------------------------------------------------------Constructeur(double,double,unsigned)
template <typename COMPARATEUR>
Histogramme<COMPARATEUR>::Histogramme(double borneInf,double borneSup,unsigned nbClasse)
: borneInf_(borneInf),borneSup_(borneSup) {
 creerClasses(nbClasse);
}

//-----------------------------------------------------------Constructeur(Histogramme<COMPARATEUR2>)
template <typename COMPARATEUR>
template <typename COMPARATEUR2>
Histogramme<COMPARATEUR>::Histogramme(const Histogramme<COMPARATEUR2> & histo)
: borneInf_(histo.getBorneInf()),borneSup_(histo.getBorneSup()) {
 // Boucle a l'ancienne
 // auto it = histo.getClasses().begin(); // auto = Histogramme<COMPARATEUR2>::classes_t::const_iterator
 // while (it!=histo.getClasses().end()) classes_.insert(*(it++));

 // Boucle C++ moderne
 // for (const Classe & c : histo.getClasses()) classes_.insert(c);

 // Insertion directe
 classes_.insert(histo.getClasses().begin(),histo.getClasses().end());

 valeurs_.insert(histo.getValeurs().begin(),histo.getValeurs().end());
}

//--------------------------------------------------------------------------------------CreerClasses
template <typename COMPARATEUR>
void Histogramme<COMPARATEUR>::creerClasses(unsigned nbClasse) {
 double intervalle = (borneSup_-borneInf_)/nbClasse;

 for (unsigned i = 0; i<nbClasse; ++i)
  classes_.insert(Classe(borneInf_+intervalle*i,borneInf_+intervalle*(i+1)));
}

//-----------------------------------------------------------------------------------Ajouter(Valeur)
template <typename COMPARATEUR>
void Histogramme<COMPARATEUR>::ajouter(const Valeur & valeur) {
 // Recherche avec iterateurs
 // auto it = classes_.begin(); // auto = classes_t::const_iterator
 //
 // while (it != classes_.end()) {
 //  if (valeur.getNombre() >= it->getBorneInf() && valeur.getNombre() < it->getBorneSup()) break;
 //  ++it;
 // }

 // Recherche avec "std::find_if"
 auto it = std::find_if(classes_.begin(),classes_.end(), // auto = classes_t::const_iterator
                        [&valeur] (const Classe & c) {
                         return (valeur.getNombre() >= c.getBorneInf()
 	                         && valeur.getNombre() < c.getBorneSup());
 	                }
 	               );

 if (it != classes_.end()) {
  Classe c = *it;

  c.ajouter();
  classes_.erase(it);
  classes_.insert(c);

  valeurs_.insert(std::make_pair(c,valeur));
 }

 // Solution possible pour un vecteur (concerne le debut de l'exercice uniquement)
 // for (Classe & c : classes_) {
 //  if (valeur.getNombre() >= c.getBorneInf() && valeur.getNombre() < c.getBorneSup()) {
 //   c.ajouter();
 //   break;
 //  }
 // }
}

//------------------------------------------------------------------------------Ajouter(Echantillon)
template <typename COMPARATEUR>
void Histogramme<COMPARATEUR>::ajouter(const Echantillon & echantillon) {
 for (unsigned i = 0; i<echantillon.getTaille(); ++i) ajouter(echantillon.getValeur(i));
}

// Implementation fonctions //----------------------------------------------------------------------

//--------------------------------------------------------------------------------------Operateur <<
template <typename COMPARATEUR>
std::ostream & operator<<(std::ostream & flux,const Histogramme<COMPARATEUR> & histo) {
 // Boucle a l'ancienne
 // using it_classes_t = typename Histogramme<COMPARATEUR>::classes_t::const_iterator;
 // using it_valeurs_t = typename Histogramme<COMPARATEUR>::valeurs_t::const_iterator;
 //
 // std::pair<it_valeurs_t,it_valeurs_t> interval;
 //
 // it_classes_t it = histo.getClasses().begin();
 //
 // while (it!=histo.getClasses().end()) {
 //  flux << *it << " = " << it->getQuantite() << " :";
 //  interval=histo.getValeurs(*it);
 //
 //  while (interval.first!=interval.second) {
 //   flux << " " << interval.first->second;
 //   ++(interval.first);
 //  }
 //
 //  flux << std::endl;
 //  ++it;
 // }

 // Boucle C++ moderne
 for (const Classe & c : histo.getClasses()) {
  flux << c << " = " << c.getQuantite() << " :";
  auto interval = histo.getValeurs(c); // auto = std::pair<it_valeurs_t,it_valeurs_t>

  while (interval.first!=interval.second) {
   flux << " " << interval.first->second;
   ++(interval.first);
  }

  flux << std::endl;
 }

 return flux;
}

// Fin //-------------------------------------------------------------------------------------------
#endif
