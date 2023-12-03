// Gardien //---------------------------------------------------------------------------------------
#ifndef _VALEUR_HPP_
#define _VALEUR_HPP_

// Entetes //---------------------------------------------------------------------------------------
#include <iostream>
#include <string>

// Classe  V a l e u r //---------------------------------------------------------------------------
class Valeur {
 //----------------------------------------------------------------------------------------Attributs
 private:
  // double nombre_;
  std::string etudiant_;
  double      note_;
 //---------------------------------------------------------------------------------------Accesseurs
 public:
  // double getNombre() const { return nombre_; }
  double              getNombre() const { return note_; }
  const std::string & getEtudiant() const { return etudiant_; }
  double              getNote() const     { return note_; }

  // void setNombre(double nombre) { nombre_=nombre; }
  void setNombre(double nombre) { note_=nombre; }
  void setEtudiant(const std::string & etudiant) { etudiant_=etudiant; }
  void setNote(double note) { note_=note; }
 //------------------------------------------------------------------------------------Constructeurs
 public:
  // Valeur(double nombre = 0.0) : nombre_(nombre) {}
  Valeur(double note = 0.0,const std::string & etudiant = "inconnu")
  : etudiant_(etudiant),note_(note) {}
};

// Fonctions inline //------------------------------------------------------------------------------

//---------------------------------------------------------------------------------------Operator <<
inline std::ostream & operator << (std::ostream & flux,const Valeur & valeur) {
 flux << "(" << valeur.getEtudiant() << ";" << valeur.getNote() << ")";
 return flux;
}

// Fin //-------------------------------------------------------------------------------------------
#endif
