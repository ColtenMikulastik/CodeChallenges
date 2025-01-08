
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

int ip_ver_check(std::string input)
{
	// check for characters
	if(has(input, ':'))
	{
		// This is likely IPv6
		return 6;
	}
	else if(has(input, '.'))
	{
		// This is likely IPv4
		return 4;
	}
	else 
	{
		// I don't know what this is
		return 0;
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
	// put the last bit in there
	output.push_back(input);
	return output;
}

bool is_valid_ipv4(std::string input)
{
	// check if this input is a valid ipv4 address
	std::vector <std::string> split_input = {};
	// call split function 
	if(ip_ver_check(input) == 4)
	{
		split_input = split(input, '.');
		if(split_input.size() == 4)
		{
			for(int i{}; i < 4; i++)
			{
				// check if a valid ipv4 address
				std::cout << split_input[i] << std::endl;
				if(!(0 <= stoi(split_input[i]) && stoi(split_input[i]) <= 255))
				{
					return false;
				}
			}
			return true;
		}
		else
		{
			return false;
		}
	}
	else if (ip_ver_check(input) == 6)
	{	
		split_input = split(input, ':');
		for(std::string split : split_input)
		{
			// check if a valid ipv4 address
			std::cout << split << std::endl;
		}
	}

	return 0;
}


int main()
{
	std::string test ={"192.168.1.1"};
	std::string test2 = {"1050:0000:0000:0000:0005:0600:300c:326b"};
	std::cout << test + " results are: ipv" << ip_ver_check(test) << std::endl;
	std::cout << test2 + " results are: ipv" << ip_ver_check(test2) << std::endl;
	
	// functional ipv4 checking
	std::string thing = "12.13.14.15";
	std::cout << is_valid_ipv4(thing) << std::endl;
	return 0;

}
