#include <stdio.h>
#include <stdlib.h>

void	to_bin(unsigned char character)
{
	int	i;
	unsigned char temp_char;

	i = 8;
	temp_char = character;
	while (i-- > 0)
	{
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			printf("0");
		else
			printf("1");
	}
}

int	main(void)
{
	to_bin(42);
}
