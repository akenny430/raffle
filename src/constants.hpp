# ifndef CONSTANTS_HPP 
# define CONSTANTS_HPP 

namespace constants
{
    constexpr int n_cohort = 4; 
    
    constexpr float p[n_cohort] = {
        0.15f, 
        0.10f, 
        0.30f, 
        0.45f
    };

    constexpr int c[n_cohort] = {
        5, 
        20, 
        100, 
        300
    }; 

    constexpr float v[n_cohort] = {
        2.0f, 
        1.0f, 
        0.4f, 
        0.333f
    }; 
}

#endif