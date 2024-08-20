

int pow(int base, int pow);


int pow(int base, int pow)
{
    int result;
    while(pow != 0)
    {
	result = result * base;
	pow--;
    }
    return result;
}
