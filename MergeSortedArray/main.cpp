
#include <iostream>

int *selection_sort(int *input, int size)
{
	for(int i{}; i < size; i++)
	{
		int min_index = i;
		for(int j = i + 1; j < size; j++)
		{
			if( input[j] < input[min_index])
			{
				min_index = j;
			}
		}
		
		if(min_index != i)
		{
			
		}

		

	}
	return input;
}

int main()
{
	int *test = new int;
	test[0] = 3;
	test[1] = 2;
	test[2] = 1;
	selection_sort(test, 3);
	delete test;

	return 0;
}
