
#include <iostream>

int powerup();


double powerup(double x, int n)
{
	double product {1};
	for(int i{}; i < n; i++)
	{
		std::cout << "multiplying " << product << " by " << x << " for the " << i+1 << "th time" << std::endl;
		product = product * x;
	}
	return product;
}

int main()
{
	std::cout << powerup(3, 2);
	return 0;
}
