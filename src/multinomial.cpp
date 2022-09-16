#include <array> 
#include <cmath> 
#include <random> 

#include "constants.hpp" 
#include "factorial.hpp"
#include "multinomial.hpp" 

auto multinomial_pdf(
    const int& n, 
    const std::array<int, constants::n_cohort>& n_array  
) -> float 
{
    float density = factorial(n, n_array); 
    for (int index = 0; index < constants::n_cohort; ++index)
    {
        density *= std::pow(constants::p[index], n_array[index]); 
    }
    return density;  
}


// finish later 
// auto simulate_multinomial(int n) -> std::array<int, 4>
// {
//     int n1, n2, n3, n4; 
//     int remaining = n; 
//     // int p = prob::p1; 

    
// }