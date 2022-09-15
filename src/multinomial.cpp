#include <cmath> 
#include <initializer_list> 

#include "constants.hpp" 
#include "factorial.hpp"

auto multinomial(
    int n1, 
    int n2, 
    int n3, 
    int n4
) -> float 
{
    float density = factorial(n1, n2, n3, n4); 
    // for (int x : {n1, n2, n3, n4}) 
    // {
    //     density *= std::pow()
    // }
    density *= std::pow(prob::p1, n1); 
    density *= std::pow(prob::p2, n2); 
    density *= std::pow(prob::p3, n3); 
    density *= std::pow(prob::p4, n4); 
    return density;  
}