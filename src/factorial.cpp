#include <array> 
#include <initializer_list> 
#include "constants.hpp"
#include "factorial.hpp" 

auto factorial(
    const int& n, 
    const std::array<int, constants::n_cohort>& n_array 
) -> float 
{
    int total = n; 
    float factorial_result = 1.0f; 
    for (int x : n_array) 
    // for () 
    {
        if (x == 0) {continue;} 
        while (x > 0) 
        {
            factorial_result *= total--; 
            factorial_result /= x--; 
        }
    }
    return factorial_result; 
}