// Gardien //---------------------------------------------------------------------------------------
#ifndef _PAQUET_HPP_
#define _PAQUET_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <usine.hpp>

// Declarations types //----------------------------------------------------------------------------
using paquet_t = std::vector<std::unique_ptr<Carte>>;

// Declarations fonctions //------------------------------------------------------------------------
void remplir(paquet_t &,UsineCarte &);

std::ostream & operator<<(std::ostream &,const paquet_t &);

// Fin //-------------------------------------------------------------------------------------------
#endif
