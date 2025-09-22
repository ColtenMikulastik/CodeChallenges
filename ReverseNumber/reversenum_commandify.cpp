
#include <iostream>
#include <cmath>

// trying to make this an exe so I can use it in scripts and stuff lol

int main()
{
	int in{};
	std::cin >> in;
	// create variables
	int temp {in}, out {}, decimal_places {};

	// fill decimal_places variable with correct value
	do 
	{
		decimal_places++;
		temp = temp / 10;
	}
	while (temp != 0);

	// create the variable that defines output's decimal place
	int real_place {};
	for(int i{decimal_places}; i >= 0; i--)
	{
		// for each decimal place find value
		int place_val = in / pow(10, i - 1);
		// remove that value from in
		in = in - (place_val * pow(10,i - 1));
		// add the value to the output variable
		out = (place_val * pow(10,real_place)) + out;
		// iterate the inverse of the inputs decimal place
		real_place++;
	}
	// return the sum
	std::cout << out << std::endl;
	return 0;
}
