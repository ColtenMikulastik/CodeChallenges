

#include <iostream>


bool background(int height, int width)
{
	// prints the boarder
	// print top boarder
	for(int i{1}; i <= (width + 2); i++)
	{
		std::cout << "X";
	}
	std::cout << std::endl;
	
	// start the rest of the boarder
	for(int y{1}; y <= height; y++)
	{
		std::cout << "X";
		// print space inbetween
		for(int x{1}; x <= width; x++)
		{
			std::cout << " ";
		}
		std::cout << "X" << std::endl;
	}
	// print bottom boarder
	for(int i{1}; i <= (width + 2); i++)
	{
		std::cout << "X";
	}
	// send the return
	std::cout << std::endl;
	return 1;
}


int main()
{
	background(40, 40);
}
