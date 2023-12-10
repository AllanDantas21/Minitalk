#include "../include/minitalk.h"

void    handle_char(int pid_number, char character)
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
/*void	handle_string(int pid, char *str)
{
	int	i;

	i = -1;
	while(msg[i++])
		handle_char(pid, msg[i]);
	handle_char(pid, 0);
}*/

int main(int argc, char **argv)
{
	(void)argc;
	int id = atoi(argv[1]);	
	if (argc == 3)
	{
		handle_char(id, *argv[2]);
	}
	return (0);
}
