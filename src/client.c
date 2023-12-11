#include "../include/minitalk.h"

void    handle_char(int pid_number, char character)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (character & (1 << i))
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
	int	id;
	if (argc == 3)
	{
		id = atoi(argv[1]);	
		handle_char(id, *argv[2]);
	}
	else
	{
		ft_printf("Erro, os argumentos de entrada estão errados!\n");
		ft_printf("os argumentos devem ser: [./client PID mensagem]\n");
	}
	return (0);
}
