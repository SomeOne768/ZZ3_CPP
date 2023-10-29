#pragma once
#include <Puissance.hpp>
#include <Factorielle.hpp>

/***************** VERSION INLINE *****************/

// template <int N>
// double inline Sinus(double x)
// {
//     return ((N%2==0)?1:-1) * Puissance<2*N +1>::valeur(x) / Factorielle<2*N+1>::valeur
//         + Sinus<N-1>(x);
// }

// template <>
// double inline Sinus<0>(double x)
// {
//     return x;
// }

/**************************************************/

/***************** VERSION STRUCT *****************/

// template <int N>
// struct Sinus
// {
//     static double valeur(double x)
//     {
//         return ((N%2==0)?1:-1) * Puissance<2*N +1>::valeur(x) / Factorielle<2*N+1>::valeur
//         + Sinus<N-1>::valeur(x);
//     }
// };

// template <>
// struct Sinus<0>
// {
//     static double valeur(double x)
//     {
//         return x;
//     }
// };

/**************************************************/

/***************** VERSION CLASSE *****************/

template <int N>
class Sinus
{
public:
    static double valeur(double x)
    {
        return ((N % 2 == 0) ? 1 : -1) * Puissance<2 * N + 1>::valeur(x) / Factorielle<2 * N + 1>::valeur
            + Sinus<N-1>::valeur(x);
    }
};

template <>
class Sinus<0>
{
public:
    static double valeur(double x)
    {
        return x;
    }
};

/**************************************************/