
#include <iostream>
#include <string>

void print_zig_string(std::string *str, int k)
{

	for( int i{}; i <= (k-1); i++)
	{
		std::cout << str[i] << std::endl;
	}

}


int main()
{
	std::string input = "this is a test";
	int k = 3;
	std::string *test = new std::string[k];
	

	std::cout << input << std::endl;

	for(int i{}; i <= (k - 1); i++)	
		for (int j{}; j <= (input.length() / 2); j++)
			test[i].push_back(' ');

	print_zig_string(test, k);

	int ind_x {}, ind_y {};
	bool do_go_up = 0;

	for(char character : input)
	{
		print_zig_string(test, k);
		test[ind_x][ind_y] = character;
		if(ind_x == 0)
		{
			do_go_up = 0;
		}
		if(ind_x == (k - 1) || do_go_up)
		{
			ind_x--;
			ind_y++;
			do_go_up = 1;
		}
		else 
		{
			ind_x++;
		}
	}
	print_zig_string(test, k);

	delete [] test;
}
