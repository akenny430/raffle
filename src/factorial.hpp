#ifndef FACTORIAL_H 
#define FACTORIAL_H 

#include "constants.hpp"

auto factorial(
    const int& n, 
    const std::array<int, constants::n_cohort>& n_array 
    // const Multinomial& n
) -> double; 

#endif 