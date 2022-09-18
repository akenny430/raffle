#include <iostream> 

#include "../src/constants.hpp" 
#include "../src/factorial.hpp" 
#include "../src/multinomial.hpp" 
#include "../src/raffle_functions.hpp" 


// Multinomial curr_multinomial; 

void compute_ev(const int n)
{
	if (n <= 0) {return;} 
	int n1, n2, n3, n4; 
	int temp1, temp2, temp3, temp4; 

    // four parameters split by law of total expectation  
    float ex_t0 = 0.0f; 
    float ex_t1 = 0.0f; 
    float p_w0 = 0.0f; 
    float p_w1 = 0.0f; 

	// int count = 0; 
	// float density; 
    // density = 0.0f; 
    float ratio; 
    temp1 = n; 
    while (temp1 >= 0) 
    {
        n1 = temp1; 
        temp2 = n - temp1; 
        while (temp2 >= 0) 
        {
            n2 = temp2; 
            temp3 = n - temp1 - temp2;  
            while (temp3 >= 0) 
            {
                n3 = temp3; 
                temp4 = n - temp2 - temp3; 
                while (temp4 >= 0)
                {
                    n4 = temp4; 
                    --temp4; 
                    if (n1 + n2 + n3 + n4 != n) {continue;}
                    for (int index = 0; index < constants::n_cohort; ++index) 
                    {
                        Multinomial curr_multinomial(n1, n2, n3, n4); // cant we initialize this earlier? get that to work 
                        // std::cout 
                        // << "("
                        // << curr_multinomial.m_array[0] 
                        // << ", "
                        // << curr_multinomial.m_array[1] 
                        // << ", "
                        // << curr_multinomial.m_array[2] 
                        // << ", "
                        // << curr_multinomial.m_array[3] 
                        // << "): "
                        // << curr_multinomial.m_density 
                        // << ", "
                        // << curr_multinomial.m_entries 
                        // << ", "
                        // << curr_multinomial.m_value 
                        // << "\n"; 

                        ex_t0 += - constants::v[index] * constants::c[index] * curr_multinomial.m_array[index] * curr_multinomial.m_density; 
                        ex_t1 += (- constants::v[index] * constants::c[index] + curr_multinomial.m_value) * curr_multinomial.m_array[index] * curr_multinomial.m_density; 
                        p_w1 += (ratio = constants::c[index] / curr_multinomial.m_entries) * curr_multinomial.m_array[index] * curr_multinomial.m_density;
                        p_w0 += (1 - ratio) * curr_multinomial.m_array[index] * curr_multinomial.m_density;
                    } // end index loop 
                } 
                --temp3; 
            }
            --temp2;
        }
        --temp1; 
    } // end multinomial loop 
    ex_t0 /= n; 
    ex_t1 /= n; 
    p_w0 /= n; 
    p_w1 /= n; 

    // std::cout << "n = " << n << ", E[T] = " << ex_t0 * p_w0 + ex_t1 * p_w1 << "\n"; 
    std::cout 
    << "n = " 
    << n 
    << ", E[T] = "
    << ex_t0 
    << " * " 
    << p_w0 
    << " + " 
    << ex_t1 
    << " * " 
    << p_w1 
    << " = " 
    << ex_t0 * p_w0 + ex_t1 * p_w1 
    << "\n"; 
}

// in general I feel like we should be looping through the k's inner 
// having the k's outer is initializing every multinomial again 


int main()
{
    // compute_ev(5); 
    // for (int x : {100, 200, 500, 1000, 5000, 10000000})
    for (int x : {10, 20, 50, 100})
    {
        compute_ev(x); 
    }
	return 0; 
}

// slow as fuck and doesnt work lol 