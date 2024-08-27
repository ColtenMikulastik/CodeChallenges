
#include <iostream>
#include <string>

bool has(std::string input, char lookfor)
{
	for(int i{}; i < input.size(); i++)
	{
		if(input[i] == lookfor)
		{
			return 1;
		}
	}
	return 0;
}


int main()
{
	std::string test ={"192.168.1.1"};
	std::cout << has(test, ':') << std::endl;
	std::cout << test << std::endl;
	return 0;

}
