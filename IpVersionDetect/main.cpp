
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

std::vector <std::string> split(std::string input, char delim)
{
	// create some out of scope variables
	std::vector <std::string> output = {};
	int next_index {};
	while(next_index < input.size())
	{
		// assign to first apperance of deliminator
		next_index = input.find(delim);
		// push back the ouput vector adding the substring from input
		output.push_back(input.substr(0, next_index));
		// remove that data from input string
		input.erase(0, (next_index + 1));
	}
	return output;
}

bool is_valid_ipv4(std::string input)
{
	// check if this input is a valid ipv4 address
	std::vector <std::string> split_input = {};
	split_input = split(input, '.');
	std::cout << split_input[0] << '\n' << split_input[1] << std::endl;


	return 0;
}


int main()
{
	std::string test ={"192.168.1.1"};
	std::string test2 = {"1050:0000:0000:0000:0005:0600:300c:326b"};
	std::cout << test + " results are: ";
	ip_ver_check(test);
	std::cout << test2 + " results are: ";
	ip_ver_check(test2);
	
	std::string thing = "12.13.14.15";
	is_valid_ipv4(thing);

	return 0;

}
