#pragma once
#include <vector>
#include "carte.hpp"
#include <memory>
#include <iostream>
#include "usine.hpp"

using paquet_t = std::vector<std::unique_ptr<Carte>>;


void remplir(paquet_t &, UsineCarte &);
std::ostream& operator<<(std::ostream&, const paquet_t&);