
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
	while( next_index != -1 )
	{
		// create inscope variables
		std::string the_pushback = {};
		int this_index = next_index;
		next_index = input.find('.', this_index);
		// loop between the two indexs copying the data into a temp var
		for( int i{this_index}; i < next_index; i++) 
		{
			the_pushback.push_back(input[i]);
		}
		// load the temp var into the output
		output.push_back(the_pushback);
	}
	return output;
}

bool is_valid_ipv4(std::string input)
{
	// check if this input is a valid ipv4 address
	std::vector <std::string> split_input = {};
	split_input = split(input, '.');
	std::cout << split_input[0] << split_input[1] << std::endl;


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
	
	std::string thing = "12.13";
	is_valid_ipv4(thing);

	return 0;

}
