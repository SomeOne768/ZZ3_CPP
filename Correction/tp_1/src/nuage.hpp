// Gardien //---------------------------------------------------------------------------------------
#ifndef NUAGE_HPP_e2de9d8bffa542748c65a181aaf7a778
#define NUAGE_HPP_e2de9d8bffa542748c65a181aaf7a778

// Entetes //---------------------------------------------------------------------------------------
#include <vector>
#include <cartesien.hpp>
#include <polaire.hpp>

// Declarations anticipees //-----------------------------------------------------------------------
class Nuage;

// Declarations fonctions //------------------------------------------------------------------------
Cartesien barycentre(const Nuage &);

// Classe  N u a g e //-----------------------------------------------------------------------------
class Nuage {
 //---------------------------------------------------------------------------------------------Type
 public:
  using iterator = std::vector<Point *>::iterator;
  using const_iterator = std::vector<Point *>::const_iterator;
 //----------------------------------------------------------------------------------------Attributs
 private:
  std::vector<Point *> points_;
 //---------------------------------------------------------------------------------------Accesseurs
 public:
  std::size_t size() const { return points_.size(); }

  const_iterator begin() const { return points_.begin(); }
  const_iterator end() const { return points_.end(); }

  iterator begin() { return points_.begin(); }
  iterator end() { return points_.end(); }
 //-------------------------------------------------------------------------------Methodes publiques
 public:
  void ajouter(Point * point) { points_.push_back(point); }
  void ajouter(Point & point) { points_.push_back(&point); }
};

// Classe  B a r y c e n t r e C a r t e s i e n //-------------------------------------------------
class BarycentreCartesien {
 public:
  Cartesien operator()(const Nuage & nuage) { return barycentre(nuage); }
};

// Classe  B a r y c e n t r e P o l a i r e //-----------------------------------------------------
class BarycentrePolaire {
 public:
  Polaire operator()(const Nuage & nuage) { return Polaire(barycentre(nuage)); }
};

// Fin //-------------------------------------------------------------------------------------------
#endif
