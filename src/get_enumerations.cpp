#include <iostream> 


void get_enumerations(const int n)
{
	if (n <= 0) {return;} 
	int n1, n2, n3, n4; 
	int temp1, temp2, temp3, temp4; 

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
					<< n4 << ")"
					<< "\n"; 
				} 
				--temp3; 
			}
			--temp2;
		}
		--temp1; 
	}
}


int main()
{
	get_enumerations(10); 
	return 0; 
}
