#pragma once

/***************** VERSION INLINE *****************/
// template <int N> inline int Factorielle(void)
// {
//     return N * Factorielle<N-1>();
// }

// template <> inline int Factorielle<0>(void)
// {
//     return 1;
// }
/**************************************************/

/***************** VERSION STRUCT *****************/

// template <int N>
// struct Factorielle
// {
//     static const unsigned long valeur = N * Factorielle<N - 1>::valeur;
// };

// template <>
// struct Factorielle<0>
// {
//     static const unsigned long valeur = 1;
// };

/**************************************************/

/***************** VERSION CLASSE *****************/

template <int N>
class Factorielle
{
public:
    static const unsigned long valeur = N * Factorielle<N-1>::valeur;
};

template <>
class Factorielle<0>
{
public:
    static const unsigned long valeur = 1;
};

/**************************************************/