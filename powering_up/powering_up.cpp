
#include <iostream>

class Solution
{
public:
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

	Solution(){}
	~Solution(){}
};


int main()
{
	int power {};
	Solution test;
	double base {};
	std::cout << "give base number: ";
	std::cin >> base;
	std::cout << "give a power: ";
	std::cin >> power;
	std::cout << test.powerup(base, power) << std::endl;
	return 0;
}
