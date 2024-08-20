
#include <iostream>
#include <cmath>

void int_to_array(int input, int *output, int size);

void int_to_array(int input, int *output, int size)
{
    for( int i{}; i <= (size - 1); i++ )
    {
	int place = pow( 10, size - 1);
	output[i] = input / place;
	input = input - place;
	size--;
    }

}

int main() 
{
    int test = 123;
    int *ptr = new int[3];
    int_to_array(test, ptr, 3);
    for( int i{}; i <= 2; i++ )
    {
	std::cout << ptr[i] << std::endl;
    }

    delete [] ptr;
    return 0;
}
