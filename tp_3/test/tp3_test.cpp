// Entetes //---------------------------------------------------------------------------------------
#include "catch.hpp"

#include <iostream>
#include <tuple>
#include <demangle.hpp>

//#include <chaine.hpp>
//#include <cosinus.hpp>
//#include <exponentielle.hpp>

// Tests //-----------------------------------------------------------------------------------------

template <typename T> std::string type_name(T && x) { return demangle(typeid(x).name()); }

//------------------------------------------------------------------------------------------------ 1
/*TEST_CASE ( "TP3_Chaine::Exception" ) {
 int erreur = 0;

 long i{};
 std::pair<short,long> p{};

 try { std::cout << "i = " << chaine(i) << std::endl; }

 catch (const ExceptionChaine & e) {
  std::string message1 = e.what();
  std::string message2 = "Conversion en chaine impossible pour '"+type_name(i)+"'";

  std::cout << "<null>" << std::endl;
  REQUIRE ( message1 == message2 );
  erreur=1;
 }

 REQUIRE ( erreur == 1 );

 try { std::cout << "p = " << chaine(p) << std::endl; }

 catch (const ExceptionChaine & e) {
  std::string message1 = e.what();
  std::string message2 = "Conversion en chaine impossible pour '"+type_name(p)+"'";

  std::cout << "<null>" << std::endl;
  REQUIRE ( message1 == message2 );
  erreur=2;
 }

 REQUIRE ( erreur == 2 );
}*/

//------------------------------------------------------------------------------------------------ 2
/*TEST_CASE ( "TP3_Chaine::ConversionSimple" ) {
 std::string n = "Smith";
 int i = 10;
 double d = 13.27;
 long j = 100;

 int erreur = 0;

 try { std::cout << "n = " << chaine(n) << std::endl; }
 catch (const ExceptionChaine & e) { erreur=1; }

 REQUIRE ( chaine(n) == "Smith" );
 REQUIRE ( erreur == 0 );

 try { std::cout << "i = " << chaine(i) << std::endl; }
 catch (const ExceptionChaine & e) { erreur=2; }

 REQUIRE ( chaine(i) == "10" );
 REQUIRE ( erreur == 0 );

 try { std::cout << "d = " << chaine(d) << std::endl; }
 catch (const ExceptionChaine & e) { erreur=3; }

 REQUIRE ( chaine(d) == "13.270000" );
 REQUIRE ( erreur == 0 );

 try { std::cout << "j = " << chaine(j) << std::endl; }

 catch (const ExceptionChaine & e) {
  std::string message1 = e.what();
  std::string message2 = "Conversion en chaine impossible pour '"+type_name(j)+"'";

  std::cout << "<null>" << std::endl;
  REQUIRE ( message1 == message2 );
  erreur=4;
 }

 REQUIRE ( erreur == 4 );
}*/

//------------------------------------------------------------------------------------------------ 3
/*TEST_CASE ( "TP3_Chaine::ConversionVariadic" ) {
 std::string n = "Smith";
 int i = 10;
 double d = 13.27;
 long j = 100;

 int erreur = 0;

 try { std::cout << "n,i,d = " << chaine(n,i,d) << std::endl; }
 catch (const ExceptionChaine & e) { erreur=1; }

 REQUIRE ( (chaine(n,i,d) == "Smith 10 13.270000"
            || chaine(n,i,d) == "Smith 10 13.270000 ") == true );

 REQUIRE ( erreur == 0 );

 try { std::cout << "n,i,d,j = " << chaine(n,i,d,j) << std::endl; }

 catch (const ExceptionChaine & e) {
  std::string message1 = e.what();
  std::string message2 = "Conversion en chaine impossible pour '"+type_name(j)+"'";

  std::cout << "<null>" << std::endl;
  REQUIRE ( message1 == message2 );
  erreur=2;
 }

 REQUIRE ( erreur == 2 );
}*/

//------------------------------------------------------------------------------------------------ 4
/*TEST_CASE ( "TP3_Chaine::ConversionTuple1" ) {
 std::tuple<std::string,int,double>      t1{"Smith",10,13.27};
 std::tuple<std::string,int,double,long> t2{"Smith",10,13.27,100};

 int erreur = 0;

 try { std::cout << "t1 = " << chaine(t1) << std::endl; }
 catch (const ExceptionChaine & e) { erreur=1; }

 REQUIRE ( (chaine(t1) == "Smith 10 13.270000"
            || chaine(t1) == "Smith 10 13.270000 ") == true );

 REQUIRE ( erreur == 0 );

 try { std::cout << "t2 = " << chaine(t2) << std::endl; }

 catch (const ExceptionChaine & e) {
  std::string message1 = e.what();
  std::string message2 = "Conversion en chaine impossible pour '"+type_name(std::get<3>(t2))+"'";

  std::cout << "<null>" << std::endl;
  REQUIRE ( message1 == message2 );
  erreur=2;
 }

 REQUIRE ( erreur == 2 );
}*/

//------------------------------------------------------------------------------------------------ 5
using Identite = std::tuple<std::string,std::string>; // {nom,prenom}
using Date = std::tuple<int,int,int>; // {jour,mois,annee}
using Coordonnees = std::tuple<double,double>; // {x,y}

/*TEST_CASE ( "TP3_Chaine::ConversionTuple2" ) {
 Identite    i = { "Smith", "John" };
 Date        d = { 13, 07, 2003 };
 Coordonnees c = { 1.234, 6.789 };

 int erreur = 0;

 try {
  std::cout << "i = " << chaine(i) << std::endl;
  std::cout << "d = " << chaine(d) << std::endl;
  std::cout << "c = " << chaine(c) << std::endl;
 }
 catch (const ExceptionChaine & e) { erreur=1; }

 REQUIRE ( (chaine(i) == "Smith John"
            || chaine(i) == "Smith John ") == true );

 REQUIRE ( (chaine(d) == "13 7 2003"
            || chaine(d) == "13 7 2003 ") == true );

 REQUIRE ( (chaine(c) == "1.234000 6.789000"
            || chaine(c) == "1.234000 6.789000 ") == true );

 REQUIRE ( erreur == 0 );
}*/

//------------------------------------------------------------------------------------------------ 6
using Personne = std::tuple<Identite,Date>;

/*TEST_CASE ( "TP3_Chaine::ConversionCompositionTuples" ) {
 Identite i = { "Smith", "John" };
 Date     d = { 13, 07, 2003 };
 Personne p = { i,d };

 int erreur = 0;

 try { std::cout << "p = " << chaine(p) << std::endl; }
 catch (const ExceptionChaine & e) { erreur=1; }

 REQUIRE ( (chaine(p) == "Smith John 13 7 2003"
            || chaine(p) == "Smith John  13 7 2003  ") == true );

 REQUIRE ( erreur == 0 );
}*/

//------------------------------------------------------------------------------------------------ 7
/*TEST_CASE ( "TP3_Metaprog::Factorielle" ) {
 unsigned long f1 = Factorielle<1>::valeur;
 unsigned long f5 = Factorielle<5>::valeur;

 REQUIRE ( f1 == 1u );
 REQUIRE ( f5 == 5u*4u*3u*2u );
}*/

//------------------------------------------------------------------------------------------------ 8
/*TEST_CASE ( "TP3_Metaprog::Puissance" ) {
 REQUIRE ( Puissance<0>::valeur(3.0) == Approx(1.0) );
 REQUIRE ( Puissance<1>::valeur(3.0) == Approx(3.0) );
 REQUIRE ( Puissance<4>::valeur(3.0) == Approx(3.0*3.0*3.0*3.0) );
}*/

//------------------------------------------------------------------------------------------------ 9
/*TEST_CASE ( "TP3_Metaprog::Exponentielle" ) {
 REQUIRE ( Exponentielle<4>::valeur(0.0) == Approx(std::exp(0.0)).epsilon(1e-3) );
 REQUIRE ( Exponentielle<12>::valeur(-2.5) == Approx(std::exp(-2.5)).epsilon(1e-3) );
 REQUIRE ( Exponentielle<7>::valeur(1.4) == Approx(std::exp(1.4)).epsilon(1e-3) );
}*/

//----------------------------------------------------------------------------------------------- 10
/*TEST_CASE ( "TP3_Metaprog::Cosinus" ) {
 REQUIRE ( Cosinus<1>::valeur(0.0) == Approx(std::cos(0.0)).epsilon(1e-3) );
 REQUIRE ( Cosinus<4>::valeur(-2.0) == Approx(std::cos(-2.0)).epsilon(1e-3) );
 REQUIRE ( Cosinus<3>::valeur(1.0) == Approx(std::cos(1.0)).epsilon(1e-3) );
}*/

//----------------------------------------------------------------------------------------------- 11
/*TEST_CASE ( "TP3_Metaprog::Sinus" ) {
 REQUIRE ( Sinus<3>::valeur(0.0) == Approx(std::sin(0.0)).epsilon(1e-3) );
 REQUIRE ( Sinus<5>::valeur(-2.0) == Approx(std::sin(-2.0)).epsilon(1e-3) );
 REQUIRE ( Sinus<4>::valeur(1.0) == Approx(std::sin(1.0)).epsilon(1e-3) );
}*/

// Fin //-------------------------------------------------------------------------------------------
