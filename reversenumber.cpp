
#include <iostream>
#include <cmath>


// input of function int = 12345
// output of function int = 54321


int reverse(int in)
{
	int temp {in}, out {}, decimal_places {};

	do 
	{
		decimal_places++;
		temp = temp / 10;
	}
	while (temp != 0);
	std::cout << "decimal places: " << decimal_places << std::endl;

	int real_place {};
	for(int i{decimal_places}; i >= 0; i--)
	{
		int place_val = in / pow(10, i);
		in = in - (place_val * pow(10,i));
		std::cout << "input value now: " << in << std::endl;
		std::cout << "place value found: " << place_val << std::endl;
		out = (place_val * pow(10,real_place)) + out;
		real_place++;
		std::cout << "out is : " << out << std::endl;
		std::cout << "real place is: " << real_place << std::endl;
		std::cout << "--------------"<< std::endl;
	}
	return out / 10;
}

int main()
{
	while(true)
	{
		int val;
		std::cout << "input variable to test: ";
		std::cin >> val;

		std::cout << reverse(val) << std::endl;
	}
	return 0;
}
