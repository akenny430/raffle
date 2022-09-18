#include <array> 
#include <cmath> 
#include <random> 

#include "constants.hpp" 
#include "factorial.hpp"
#include "multinomial.hpp" 
#include "raffle_functions.hpp"

Multinomial::Multinomial(int n1, int n2, int n3, int n4)
    : m_total { n1 + n2 + n3 + n4 }, 
    m_array { {n1, n2, n3, n4} }
{
    // this->m_density = multinomial_pdf(this->m_total, this->m_array); 
    // this->m_entries = raffle::entries(this->m_array); 
    // this->m_value = raffle::raffle_value(this->m_array); 
    this->m_density = multinomial_pdf(m_total, m_array); 
    this->m_entries = raffle::entries(m_array); 
    this->m_value = raffle::raffle_value(m_array); 
    // float m_density = multinomial_pdf(m_total, m_array); 
    // int m_entries = raffle::entries(m_array); 
    // float m_value = raffle::raffle_value(m_array); 
}

auto multinomial_pdf(
    const int& n, 
    const std::array<int, constants::n_cohort>& n_array  
) -> double 
{
    double density = factorial(n, n_array); 
    for (int index = 0; index < constants::n_cohort; ++index)
    {
        density *= std::pow(constants::p[index], n_array[index]); 
    }
    return density;  
}


// finish later 
// auto simulate_multinomial(int n) -> std::array<int, 4>
// {
//     int n1, n2, n3, n4; 
//     int remaining = n; 
//     // int p = prob::p1; 

    
// }