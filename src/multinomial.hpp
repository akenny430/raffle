#ifndef MULTINOMIAL_HPP
#define MULTINOMIAL_HPP

#include <array>

#include "constants.hpp"

class Multinomial
{
public: 
    int m_total; 
    std::array<int, constants::n_cohort> m_array; 
    float m_density; 
    int m_entries; 
    float m_value; 
    Multinomial(int n1, int n2, int n3, int n4); 
};

// why do we still need this??? 
auto multinomial_pdf( 
    const int& n, 
    const std::array<int, constants::n_cohort>& n_array
) -> float; 

#endif 