# ifndef CONSTANTS_HPP 
# define CONSTANTS_HPP 

namespace constants 
{
    constexpr int n_cohort = 4; 
    
    constexpr double p[n_cohort] = {
        0.15, 
        0.10, 
        0.30, 
        0.45
    };

    constexpr int c[n_cohort] = {
        5, 
        20, 
        100, 
        300
    }; 

    constexpr double v[n_cohort] = {
        2.0, 
        1.0, 
        0.4, 
        0.333
    }; 
}

#endif