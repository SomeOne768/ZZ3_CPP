#pragma once
#include "carte.hpp"
#include <iostream>
#include <memory>

class UsineCarte
{
    unsigned int number = 0;
    unsigned int max;

public:
    UsineCarte();
    UsineCarte(unsigned int);
    ~UsineCarte() = default;
    UsineCarte(const UsineCarte&) = delete;
    auto operator=(const UsineCarte&) = delete;

    bool end() const;

    std::unique_ptr<Carte> getCarte();
};