#include <iostream> 


void get_enumerations(const int n)
{
	if (n <= 0) {return;} 
	int n1, n2, n3, n4; 
	int temp1, temp2, temp3, temp4; 
	int count = 0; 

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
					// std::cout << "(" 
					// << n1 << ", "
					// << n2 << ", "
					// << n3 << ", "
					// << n4 << ")"
					// << "\n"; 
					++count; 
				} 
				--temp3; 
			}
			--temp2;
		}
		--temp1; 
	}
	std::cout << "# of enumerations for " << n << ": " << count << "\n"; 
}


int main()
{
	for (int x : {5, 10, 15, 20, 30}) {get_enumerations(x);}
	// get_enumerations(20); 
	return 0; 
}
