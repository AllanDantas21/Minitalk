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

int	check_args(char *pid, char *msg_arg)
{
	if (!msg_arg)
		return (-1);
	while(*pid)
	{
		if(!ft_isdigit(*pid))
		{
			ft_printf("o pid só deve conter digitos!");
			return (-1);
		}
		pid++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int	id;
	if (argc == 3)
	{
		if(check_args(argv[1], argv[2]) == -1)
			return (0);
		id = ft_atoi(argv[1]);	
		send_msg(id, argv[2]);
	}
	else
	{
		ft_printf("Erro, os argumentos de entrada estão errados!\n");
		ft_printf("os argumentos devem ser: [./client PID mensagem]\n");
	}
	return (0);
}
