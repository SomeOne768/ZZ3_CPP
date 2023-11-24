// Entetes //---------------------------------------------------------------------------------------
#include "catch.hpp"

#include <cmath>
#include "valeur.hpp"
#include "echantillon.hpp"
#include "classe.hpp"
#include <histogramme.hpp>
//#include <comparateur.hpp>

//using Histo = Histogramme; // A utiliser pour les tests 12-13
//using Histo = Histogramme<>; // A utiliser a partir du test 14

// Tests //-----------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------ 1
TEST_CASE ( "TP5_Valeur::Constructeur" ) {
 const double a = 12.0;

 Valeur v(a);

 REQUIRE ( v.getNombre() == Approx(a) );
}

//------------------------------------------------------------------------------------------------ 2
TEST_CASE ( "TP5_Valeur::ConstructeurDefaut" ) {
 Valeur v;

 REQUIRE ( v.getNombre() == Approx(0.0) );
}

//------------------------------------------------------------------------------------------------ 3
TEST_CASE ( "TP5_Valeur::Accesseurs" ) {
 const double a = 12.0;

 Valeur v(13.0);

 v.setNombre(a);

 REQUIRE ( v.getNombre() == Approx(a) );
}

//------------------------------------------------------------------------------------------------ 4
TEST_CASE ( "TP5_Valeur::AccesseursConstants" ) {
 const Valeur v;

 REQUIRE ( v.getNombre() == Approx(0.0) );
}

//------------------------------------------------------------------------------------------------ 5
TEST_CASE ( "TP5_Echantillon::Constructeur" ) {
 Echantillon e;

 REQUIRE ( e.getTaille() == 0u );
}

//------------------------------------------------------------------------------------------------ 6
TEST_CASE ( "TP5_Echantillon::Ajout" ) {
 Echantillon e;

 double v[] = { 5.0, 10.0, 15.0, 20.0 };

 for (unsigned i = 0; i<4; ++i) e.ajouter(v[i]);

 REQUIRE ( e.getTaille() == 4u );
}

//------------------------------------------------------------------------------------------------ 7
TEST_CASE ( "TP5_Echantillon::MinMax" ) {
 Echantillon e;

 double v[] = { 5.0, 10.0, 15.0, 20.0 };
 double min = v[0];
 double max = v[0];

 for (unsigned i = 0; i<4; ++i) {
  e.ajouter(v[i]);
  if (v[i]<min) min=v[i];
  if (v[i]>max) max=v[i];
 }

 REQUIRE ( e.getMinimum().getNombre() == Approx(min) );
 REQUIRE ( e.getMaximum().getNombre() == Approx(max) );
}
#include <iostream>
//------------------------------------------------------------------------------------------------ 8
TEST_CASE ( "TP5_Echantillon::MinMaxException" ) {
 Echantillon e;

 int error = 0;

 try { e.getMinimum().getNombre(); }

 catch (const std::domain_error & e) { error=2; }
 catch (...) { error=1; }

 REQUIRE ( error == 2 );

 error=0;

 try { e.getMaximum().getNombre(); }

 catch (const std::domain_error & e) { error=2; }
 catch (...) { error=1; }

 REQUIRE ( error == 2 );
}

//------------------------------------------------------------------------------------------------ 9
TEST_CASE ( "TP5_Echantillon::Indice" ) {
 Echantillon e;

 double v[] = { 5.0, 10.0, 15.0, 20.0 };

 for (unsigned i = 0; i<4; ++i) e.ajouter(v[i]);

 int error = 0;

 try {
  for (unsigned i = 0; i<4; ++i)
   REQUIRE ( e.getValeur(i).getNombre() == Approx(v[i]) );
 }

 catch (...) { error=1; }

 REQUIRE ( error == 0 );

 try { e.getValeur(e.getTaille()); }

 catch (const std::out_of_range & e) { error=2; }
 catch (...) { error=1; }

 REQUIRE ( error == 2 );
}

//----------------------------------------------------------------------------------------------- 10
TEST_CASE ( "TP5_Classe::Constructeur" ) {
 const double a = 12.0;
 const double b = 24.0;

 Classe c(a,b);

 REQUIRE ( c.getBorneInf() == Approx(a) );
 REQUIRE ( c.getBorneSup() == Approx(b) );
 REQUIRE ( c.getQuantite() == 0u );
}

//----------------------------------------------------------------------------------------------- 11
TEST_CASE ( "TP5_Classe::Accesseurs" ) {
 const double   a = 12.0;
 const double   b = 24.0;
 const unsigned n = 7;

 Classe c(13.0,25.0);

 c.setBorneInf(a);
 c.setBorneSup(b);
 c.setQuantite(n);

 REQUIRE ( c.getBorneInf() == Approx(a) );
 REQUIRE ( c.getBorneSup() == Approx(b) );
 REQUIRE ( c.getQuantite() == n );

 c.ajouter();

 REQUIRE ( c.getQuantite() == n+1 );
}

//----------------------------------------------------------------------------------------------- 12
TEST_CASE ( "TP5_Histogramme::Constructeur" ) {
 Histo h(5.0,15.0,5);

 double bornesInf[] = { 5.0, 7.0,  9.0, 11.0, 13.0 };
 double bornesSup[] = { 7.0, 9.0, 11.0, 13.0, 15.0 };

 REQUIRE ( h.getClasses().size() == 5u );

 unsigned i = 0;

 for (const Classe & c : h.getClasses()) {
  REQUIRE ( c.getBorneInf() == Approx(bornesInf[i]) );
  REQUIRE ( c.getBorneSup() == Approx(bornesSup[i]) );
  REQUIRE ( c.getQuantite() == 0u );
  ++i;
 }
}

//----------------------------------------------------------------------------------------------- 13
TEST_CASE ( "TP5_Histogramme::Echantillon" ) {
 double v[] = { 7.0, 9.0, 8.0, 5.0, 10.0, 14.0, 13.0, 6.0, 5.5, 13.5 };
 double n[] = { 3, 2, 2, 0, 3 };

 Echantillon e;

 for (unsigned i = 0; i<10; ++i) e.ajouter(v[i]);

 Histo h(5.0,15.0,5);

 h.ajouter(e);

 REQUIRE ( h.getClasses().size() == 5u );

 unsigned i = 0;

 for (const Classe & c : h.getClasses()) {
  REQUIRE ( c.getQuantite() == Approx(n[i++]) );
 }
}

//----------------------------------------------------------------------------------------------- 14
TEST_CASE ( "TP5_Histogramme::Generique" ) {
 using histo_t = Histogramme<>;

 histo_t h(5.0,15.0,5);

 double bornesInf[] = { 5.0, 7.0,  9.0, 11.0, 13.0 };
 double bornesSup[] = { 7.0, 9.0, 11.0, 13.0, 15.0 };

 REQUIRE ( h.getClasses().size() == 5u );

  
 unsigned i = 0;

 for (const Classe & c : h.getClasses()) {
  REQUIRE ( c.getBorneInf() == Approx(bornesInf[i]) );
  REQUIRE ( c.getBorneSup() == Approx(bornesSup[i]) );
  REQUIRE ( c.getQuantite() == 0u );
  ++i;
 }
}

//----------------------------------------------------------------------------------------------- 15
TEST_CASE ( "TP5_Histogramme::FoncteurGreater" ) {
 using histo_t = Histogramme<std::greater<Classe>>;

 histo_t h(5.0,15.0,5);

 double bornesInf[] = { 5.0, 7.0,  9.0, 11.0, 13.0 };
 double bornesSup[] = { 7.0, 9.0, 11.0, 13.0, 15.0 };

 REQUIRE ( h.getClasses().size() == 5u );

 unsigned i = 5;

 for (const Classe & c : h.getClasses()) {
  --i;
  REQUIRE ( c.getBorneInf() == Approx(bornesInf[i]) );
  REQUIRE ( c.getBorneSup() == Approx(bornesSup[i]) );
  REQUIRE ( c.getQuantite() == 0u );
 }
}

//----------------------------------------------------------------------------------------------- 16
TEST_CASE ( "TP5_Histogramme::ComparateurQuantite" ) {
 using histo_t = Histogramme<ComparateurQuantite<Classe>>;
 double v[] = { 7.0, 9.0, 8.0, 5.0, 10.0, 14.0, 13.0, 6.0, 5.5, 13.5 };

 histo_t h(5.0,15.0,5);

 for (unsigned i = 0; i<10; ++i) h.ajouter(v[i]);

 double   bornesInf[] = { 5.0, 13.0, 7.0,  9.0, 11.0 };
 double   bornesSup[] = { 7.0, 15.0, 9.0, 11.0, 13.0 };
 unsigned quantites[] = {   3,    3,   2,    2,    0 };

 REQUIRE ( h.getClasses().size() == 5u );

 unsigned i = 0;

 for (const Classe & c : h.getClasses()) {
  REQUIRE ( c.getBorneInf() == Approx(bornesInf[i]) );
  REQUIRE ( c.getBorneSup() == Approx(bornesSup[i]) );
  REQUIRE ( c.getQuantite() == quantites[i] );
  ++i;
 }
}

//------------------------------------------------------------------------------------------------17
TEST_CASE ( "TP5_Histogramme::Conversion" ) {
 using histo1_t = Histogramme<std::greater<Classe>>;
 using histo2_t = Histogramme<ComparateurQuantite<Classe>>;

 double v[] = { 7.0, 9.0, 8.0, 5.0, 10.0, 14.0, 13.0, 6.0, 5.5, 13.5 };

 histo1_t h1(5.0,15.0,5);

 for (unsigned i = 0; i<10; ++i) h1.ajouter(v[i]);

 histo2_t h2(h1);

 double   bornesInf[] = { 5.0, 13.0, 7.0,  9.0, 11.0 };
 double   bornesSup[] = { 7.0, 15.0, 9.0, 11.0, 13.0 };
 unsigned quantites[] = {   3,    3,   2,    2,    0 };

 REQUIRE ( h1.getClasses().size() == 5u );
 REQUIRE ( h2.getClasses().size() == 5u );

 unsigned i = 0;

 for (const Classe & c : h2.getClasses()) {
  REQUIRE ( c.getBorneInf() == Approx(bornesInf[i]) );
  REQUIRE ( c.getBorneSup() == Approx(bornesSup[i]) );
  REQUIRE ( c.getQuantite() == quantites[i] );
  ++i;
 }
}

//----------------------------------------------------------------------------------------------- 18
TEST_CASE ( "TP5_Etudiant::Constructeur" ) {
 const double a = 12.0;
 const char * n = "Machin";

 Valeur v(a,n);

 REQUIRE ( v.getNombre() == Approx(a) );
 REQUIRE ( v.getNote() == Approx(a) );
 REQUIRE ( v.getEtudiant().c_str() != 0);
 REQUIRE ( v.getEtudiant() == n );
}

//----------------------------------------------------------------------------------------------- 19
TEST_CASE ( "TP5_Etudiant::ConstructeurDefaut" ) {
 Valeur v;

 REQUIRE ( v.getNombre() == Approx(0.0) );
 REQUIRE ( v.getNote() == Approx(0.0) );
 REQUIRE ( v.getEtudiant() == "inconnu" );
}

//----------------------------------------------------------------------------------------------- 20
TEST_CASE ( "TP5_Etudiant::Accesseurs" ) {
 const double a = 12.0;
 const char * n = "Machin";

 Valeur v(13.0,"Truc");

 v.setNote(a);
 v.setEtudiant(n);

 REQUIRE ( v.getNombre() == Approx(a) );
 REQUIRE ( v.getNote() == Approx(a) );
 REQUIRE ( v.getEtudiant() == n );
}

//----------------------------------------------------------------------------------------------- 21
TEST_CASE ( "TP5_Etudiant::AccesseursConstants" ) {
 const Valeur v;

 REQUIRE ( v.getNombre() == Approx(0.0) );
 REQUIRE ( v.getNote() == Approx(0.0) );
 REQUIRE ( v.getEtudiant() == "inconnu" );
}

//----------------------------------------------------------------------------------------------- 22
TEST_CASE ( "TP5_Valeurs::Association" ) {
 using histo_t = Histogramme<>;

 double v[] = { 7.0, 9.0, 8.0, 5.0, 10.0, 14.0, 13.0, 6.0, 5.5, 13.5 };

 histo_t h(5.0,15.0,5);

 for (unsigned i = 0; i<10; ++i) h.ajouter(v[i]);

 double bornesInf[] = {5.0, 5.0, 5.0, 7.0, 7.0,  9.0,  9.0, 13.0, 13.0, 13.0 };
 double bornesSup[] = {7.0, 7.0, 7.0, 9.0, 9.0, 11.0, 11.0, 15.0, 15.0, 15.0 };
 double notes[]     = {5.0, 6.0, 5.5, 7.0, 8.0,  9.0, 10.0, 14.0, 13.0, 13.5 };

 REQUIRE ( h.getClasses().size() == 5u );
 REQUIRE ( h.getValeurs().size() == 10u );

 unsigned i = 0;

 for (const std::pair<const Classe,Valeur> & p : h.getValeurs()) {
  REQUIRE ( p.first.getBorneInf() == Approx(bornesInf[i]) );
  REQUIRE ( p.first.getBorneSup() == Approx(bornesSup[i]) );
  REQUIRE ( p.second.getNote() == Approx(notes[i]) );
  ++i;
 }
}

//----------------------------------------------------------------------------------------------- 23
TEST_CASE ( "TP5_Valeurs::Intervalle" ) {
 using histo_t = Histogramme<>;

 double v[] = { 7.0, 9.0, 8.0, 5.0, 10.0, 14.0, 13.0, 6.0, 5.5, 13.5 };

 histo_t h(5.0,15.0,5);

 for (unsigned i = 0; i<10; ++i) h.ajouter(v[i]);

 std::vector<double> notes[] = { { 5.0, 6.0, 5.5 },
                                 { 7.0, 8.0 },
                                 { 9.0, 10.0 },
                                 {},
                                 { 14.0, 13.0, 13.5 } };

 unsigned i = 0;

 REQUIRE ( h.getClasses().size() == 5u );
 REQUIRE ( h.getValeurs().size() == 10u );

 for (const Classe & c : h.getClasses()) {
  auto interval = h.getValeurs(c);
  unsigned j = 0;

  while (interval.first != interval.second) {
   REQUIRE ( (interval.first)->second.getNote() == Approx(notes[i][j]) );

   ++(interval.first);
   ++j;
  }

  REQUIRE ( j == notes[i].size() );

  ++i;
 }
}

// Fin //-------------------------------------------------------------------------------------------
