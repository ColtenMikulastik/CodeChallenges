
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
	bool final_char = 0;
	// loop while next_index is not the final index of the string
	while( next_index != (input.size() - 1) )
	{
		// create inscope variables
		std::string str_temp = {};
		int this_index = next_index;
		// if this is the last occurance next_index needs to be the final index
		next_index = input.find('.', this_index);
		if( next_index == this_index )
		{
			// assign next_index to the final index of the string
			next_index = (input.size() - 1);
			// lazy mode
			final_char = 1;
		}
		// loop between the two indexs copying the data into a temp var
		for( int i{this_index + 1}; i < next_index; i++) 
		{
			str_temp.push_back(input[i]);
		}
		// lazy mode to grab last character
		if( final_char )
		{
			// lazy mode
			str_temp.push_back(input[next_index]);
		}

		// load the temp var into the output
		output.push_back(str_temp);
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
