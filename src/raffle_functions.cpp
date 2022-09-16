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
        return (
            count::c1 * n1 
            + count::c2 * n2 
            + count::c3 * n3 
            + count::c4 * n4 
        );    
    }

    auto raffle_value(
        int n1, 
        int n2, 
        int n3, 
        int n4 
    ) -> int 
    {
        return (
              count::c1 * val::v1 * n1 
            + count::c2 * val::v2 * n2 
            + count::c3 * val::v3 * n3 
            + count::c4 * val::v4 * n4 
        );    
    }
}