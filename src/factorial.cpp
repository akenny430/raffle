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
    // int max_n = 0; 
    float factorial_result = 1.0f; 
    for (int x : {n1, n2, n3, n4}) 
    {
        // n += x; 
        // max_n = x > max_n ? x : max_n; 
        if (x == 0) 
        {
            factorial_result *= n--; 
            continue; 
        }
        while (x > 0) 
        {
            factorial_result *= n--; 
            factorial_result /= x--; 
        }
    }
    return factorial_result; 
    // int total_mult = n - max_n; 
}