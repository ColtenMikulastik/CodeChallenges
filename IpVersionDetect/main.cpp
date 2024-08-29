
#include <iostream>
#include <string>
#include <vector>


bool has(std::string input, char lookfor)
{
	// loop through each element to searhc for character
	for(int i{}; i < input.size(); i++)
	{
		if(input[i] == lookfor)
		{
			// return true if found
			return 1;
		}
	}
	// return false if not
	return 0;
}

void ip_ver_check(std::string input)
{
	// check for characters
	if(has(input, ':'))
	{
		std::cout << "This is likely IPv6" << std::endl;
	}
	else if(has(input, '.'))
	{
		std::cout << "This is likely IPv4" << std::endl;
	}
	else 
	{
		std::cout << "I don't know what this is" << std::endl;
	}
}


bool is_valid_ipv4(std::string input)
{
	// check if this input is a valid ipv4 address

	return 0;
}

std::vector <int> split(std::string input, char delim)
{
	std::vector <int> output = {};

	output.push_back();
	return output;
}


int main()
{
	std::string test ={"192.168.1.1"};
	std::string test2 = {"1050:0000:0000:0000:0005:0600:300c:326b"};
	std::cout << test + " results are: ";
	ip_ver_check(test);
	std::cout << test2 + " results are: ";
	ip_ver_check(test2);


	return 0;

}
