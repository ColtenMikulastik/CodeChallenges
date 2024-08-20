
#include <cmath>

void int_to_array(int input, int *output, int size);

void int_to_array(int input, int *output, int size)
{
    int inverse_place = size;
    for( int i{}; i <= (size - 1); i++ )
    {
	int place = pow( 10, inverse_place - 1);
	output[i] = input / place;
	input = input - (place * output[i]);
	inverse_place--;
    }

}
