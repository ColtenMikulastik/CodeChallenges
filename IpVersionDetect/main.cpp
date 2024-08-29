
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

std::vector <int> split(std::string input, char delim)
{
	std::vector <int> output = {};
	int next_index {};
	while( next_index != -1 )
	{
		std::string the_pushback = {};
		int this_index = next_index;
		next_index = input.find('.', this_index);
		
		for( int i{this_index}; i < next_index; i++) 
		{
			the_pushback.push_back(input[i]);
		}
		output.push_back(std::stoi(the_pushback));
	}
	return output;
}

bool is_valid_ipv4(std::string input)
{
	// check if this input is a valid ipv4 address
	std::vector <int> split_input = {};
	split_input = split(input, '.');


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


	return 0;

}
