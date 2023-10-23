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
std::string type_name(T &&x) { return demangle(typeid(x).name()); }

template <typename T>
std::string chaine(T &x)
{
    // std::string s = "Conversion en chaine impossible pour '" + type_name(x) + "'";
    // throw ExceptionChaine(s);
    throw ExceptionChaine(x);
}


std::string chaine(std::string &x)
{
 return x;   
}


std::string chaine(int &x)
{
    std::stringstream iss{};
    iss << x;

    return iss.str();
}

std::string chaine(double &x)
{
    return std::to_string(x);
}

template <typename... T>
std::string chaine(T... x)
{
    return ( (chaine(x) + " ") + ...);
}