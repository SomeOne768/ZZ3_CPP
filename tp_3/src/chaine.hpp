#pragma once
#include <iostream>
#include <sstream>


class ExceptionChaine : public std::exception
{

    std::string message;

public:
    ExceptionChaine(const std::string &s) : std::exception(), message(s)
    {
    }

    template <typename T>
    ExceptionChaine(const T &x) : std::exception()
    {
        message = "Conversion en chaine impossible pour '" + demangle(typeid(x).name()) + "'";
    }

    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

template <typename T>
const std::string chaine(const T &x)
{
    throw ExceptionChaine(x);
}

const std::string chaine(const std::string &x)
{
    return x;
}

const std::string chaine(const int &x)
{
    std::stringstream iss{};
    iss << x;

    return iss.str();
}

const std::string chaine(const double &x)
{
    return std::to_string(x);
}

template <typename... T>
const std::string chaine(const T... x)
{
    return ((chaine(x) + " ") + ...);
}


template <typename T, size_t... I>
const std::string chaine(const T &t, std::index_sequence<I...>)
{
    return chaine(std::get<I>(t)...);
}


// /!\ Attention, si défini après (et pas de déclaration) appelera la version template normal !
template <typename... Args>
const std::string chaine(std::tuple<Args...> &t)
{
    return chaine(t, std::make_index_sequence<sizeof...(Args)>());
}
