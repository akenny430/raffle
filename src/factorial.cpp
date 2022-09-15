#include <initializer_list> 
#include "factorial.hpp" 

auto factorial(
    int n1, 
    int n2, 
    int n3, 
    int n4 
) -> float 
{
    int n = n1 + n2 + n3 + n4; 
    float factorial_result = 1.0f; 
    for (int x : {n1, n2, n3, n4}) 
    {
        if (x == 0) {continue;} 
        while (x > 0) 
        {
            factorial_result *= n--; 
            factorial_result /= x--; 
        }
    }
    return factorial_result; 
}