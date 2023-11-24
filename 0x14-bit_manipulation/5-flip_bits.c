/**
 * count_set_bits - Counts the number of set bits in a number
 * @n: The input number
 *
 * Return: Number of set bits
 */
unsigned int count_set_bits(unsigned long int n)
{
	unsigned int count = 0;

	while (n)
	{
		n &= (n - 1);
		count++;
	}
	return (count);
}

/**
 * flip_bits - Counts the number of bits needed to flip to get from one 
 * number to another
 * @n: The first input number
 * @m: The second input number
 *
 * Return: Number of bits needed to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;

	return (count_set_bits(xor_result));
}
