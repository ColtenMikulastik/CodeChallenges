
#include <iostream>

int pow(int base, int pow);


int pow(int base, int pow)
{
    int result {1};
    while(pow != 0)
    {
	result = result * base;
	pow--;
    }
    return result;
}


int main() 
{
    // here for testing purposes
    std::cout << pow( 33, 5 );
    return 0;
}
