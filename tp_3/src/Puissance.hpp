#pragma once

/***************** VERSION INLINE *****************/
// template <int N> double inline Puissance(double x)
// {
//     return x * Puissance<N-1>(x);
// }

// template <> double inline Puissance<0>(double x)
// {
//     (void) x;
//     return 1;
// }
/**************************************************/

/***************** VERSION STRUCT *****************/
// template <int N>
// struct Puissance
// {
//     static double valeur(double x)
//     {
//         return x * Puissance<N-1>::valeur(x);
//     }
// };

// template <>
// struct Puissance<0>
// {
//     static double valeur(double x)
//     {
//         (void) x;
//         return 1;
//     }
// };

/**************************************************/

/***************** VERSION CLASSE *****************/

template <int N>
class Puissance
{
public:
    static double valeur(double x)
    {
        return x * Puissance<N - 1>::valeur(x);
    }
};

template <>
class Puissance<0>
{
public:
    static double valeur(double x)
    {
        (void) x;
        return 1;
    }
};
/**************************************************/