#include <array>

#include "constants.hpp" 
#include "raffle_functions.hpp"

namespace raffle
{
    auto entries(
        const std::array<int, constants::n_cohort>& n_array
    ) -> int 
    {
        int n_entries = 0; 
        // int n_array[constants::n_cohort] = {n1, n2, n3, n4}; 
        for (int index = 0; index < constants::n_cohort; ++index)
        {
            n_entries += constants::c[index] * n_array[index]; 
        } 
        return n_entries; 
    }

    auto raffle_value(
        const std::array<int, constants::n_cohort>& n_array
    ) -> int 
    {
        double value = 0.0f; 
        for (int index = 0; index < constants::n_cohort; ++index)
        {
            value += constants::c[index] * constants::v[index] * n_array[index]; 
        } 
        return 0.5 * value; 
    }
}