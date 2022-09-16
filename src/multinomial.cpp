#include <array> 
#include <cmath> 
#include <random> 

#include "constants.hpp" 
#include "factorial.hpp"
#include "multinomial.hpp" 

auto multinomial_pdf(
    int n1, 
    int n2, 
    int n3, 
    int n4
) -> float 
{
    int n_array[constants::n_cohort] = {n1, n2, n3, n4}; 
    float density = factorial(n1, n2, n3, n4); 
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