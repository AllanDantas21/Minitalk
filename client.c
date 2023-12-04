#include "minitalk.h"

void    handle_char(char character, int pid_number)
{
	int	i;
	unsigned char temp_char;

	i = 8;
	temp_char = character;
	while (i-- > 0)
	{
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid_number, SIGUSR2);
		else
			kill(pid_number, SIGUSR1);
	}
}

int main(int argc, char **argv)
{
	int id = atoi(argv[1]);	

	kill(id, SIGUSR1);
	return (0);
}