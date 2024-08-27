
#include <iostream>

int main()
{
	int *test = new int;
	test[0] = 3;
	test[1] = 2;
	test[2] = 1;
	delete test;

	return 0;
}
