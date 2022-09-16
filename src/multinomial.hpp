#ifndef MULTINOMIAL_HPP
#define MULTINOMIAL_HPP

#include "constants.hpp"

auto multinomial_pdf( 
    const int& n, 
    const std::array<int, constants::n_cohort>& n_array
) -> float; 

#endif 