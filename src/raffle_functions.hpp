#ifndef RAFFLE_FUNCS_HPP
#define RAFFLE_FUNCS_HPP

#include "constants.hpp" 

namespace raffle
{
    auto entries(
        const std::array<int, constants::n_cohort>& n_array
    ) -> int;

    auto raffle_value(
        const std::array<int, constants::n_cohort>& n_array 
    ) -> int;
}

#endif 