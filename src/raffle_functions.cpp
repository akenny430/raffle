#include "constants.hpp" 

namespace raffle
{
    auto entries(
        int n1, 
        int n2, 
        int n3, 
        int n4 
    ) -> int 
    {
        int n_entries = 0; 
        int n_array[constants::n_cohort] = {n1, n2, n3, n4}; 
        for (int index = 0; index < constants::n_cohort; ++index)
        {
            n_entries += constants::c[index] * n_array[index]; 
        } 
        return n_entries; 
    }

    auto raffle_value(
        int n1, 
        int n2, 
        int n3, 
        int n4 
    ) -> int 
    {
        float value = 0.0f; 
        int n_array[constants::n_cohort] = {n1, n2, n3, n4}; 
        for (int index = 0; index < constants::n_cohort; ++index)
        {
            value += constants::c[index] * constants::v[index] * n_array[index]; 
        } 
        return value; 
    }
}