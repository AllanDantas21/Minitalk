#include "../include/minitalk.h"

void    handle_char(int pid, char character)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (character & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
	}
}

void	send_msg(int id, char *msg)
{
	int	i;

	i = 0;
	while(msg[i])
	{
		handle_char(id, msg[i++]);
	}
	handle_char(id, '\n');
}

int main(int argc, char **argv)
{
	int	id;
	if (argc == 3)
	{
		id = atoi(argv[1]);	
		send_msg(id, argv[2]);
	}
	else
	{
		ft_printf("Erro, os argumentos de entrada estão errados!\n");
		ft_printf("os argumentos devem ser: [./client PID mensagem]\n");
	}
	return (0);
}
