
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

std::vector <std::string> format_ipv6(std::string input)
{
	std::vector<std::string> output = {};
	// split based on ipv6
	output = split(input, ':');
	// add our zero's to format the :: better if there is one
	if(output.size() < 8)
	{
		// loop through the vector
		for(int i{}; i <= 7; i++)
		{
			// find the empty string
			if(output[i] == "")
			{
				// add "0000" until the vector has 8 elements
				while(output.size() != 8)
				{
					output.insert(output.begin() + i, "0000");
				}
				// break the loop here incase of duplicates
				break;
			}
		}
	}
	// check for un-buffered zeros

	return output;
}

bool is_valid_ip(std::string input)
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
		// format the string to something easier to programatically search through
		std::vector <std::string> formatted_string = format_ipv6(input);
		for(std::string string : formatted_string)
		{
			std::cout << string << std::endl;
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
	std::string thing = "1050::0005:0600:300c:326b";
	std::cout << is_valid_ip(thing) << std::endl;
	return 0;

}
