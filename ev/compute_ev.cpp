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

    float ex_t0, ex_t1, p_w0, p_w1; // four parameters split by law of total expectation  

	// int count = 0; 
	float density; 
    for (int index = 0; index < constants::n_cohort; ++index) 
    {
        density = 0.0f; 
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
                        // do something here to return the values 
                        std::cout << "(" 
                        << n1 << ", "
                        << n2 << ", "
                        << n3 << ", "
                        << n4 << "): "; 
                        // ++count; 
                        // density += multinomial_pdf(n1, n2, n3, n4); 
                        Multinomial curr_multinomial(n1, n2, n3, n4); 
                        std::cout << curr_multinomial.m_total << ", "
                        << curr_multinomial.m_density << ", " 
                        << curr_multinomial.m_entries << ", " 
                        << curr_multinomial.m_value   << ", " 
                        << "\n"; 
                        density += curr_multinomial.m_density; 
                    } 
                    --temp3; 
                }
                --temp2;
            }
            --temp1; 
        }
        std::cout << 100 * density << "%\n"; 
    } // end index loop 
}


int main()
{
    compute_ev(5); 
	return 0; 
}
