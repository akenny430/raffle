#ifndef RAFFLE_FUNCS_HPP
#define RAFFLE_FUNCS_HPP

namespace raffle
{
    auto entries(
        int n1, 
        int n2, 
        int n3, 
        int n4 
    ) -> int;

    auto raffle_value(
        int n1, 
        int n2, 
        int n3, 
        int n4 
    ) -> int;
}

#endif 