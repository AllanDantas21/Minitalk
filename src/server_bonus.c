#include "../include/minitalk.h"

void	minitalk_header(void)
{
	ft_printf ("\033[32m___  ___ _         _  _           _  _\n");
	ft_printf("|  \\/  |(_)       (_)| |         | || |       \n");
	ft_printf("| .  . | _  _ __   _ | |_   __ _ | || | __     \n");
	ft_printf("| |\\/| || || '_ \\ | || __| / _` || || |/ /   \n");
	ft_printf("| |  | || || | | || || |_ | (_| || ||   <      \n");
	ft_printf("\\_|  |_/|_||_| |_||_| \\__| \\__,_||_||_|\\_\\\n\033[37m");
}

void	sig_to_char(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static unsigned char	c = 0;

	(void)context;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
		kill(info->si_pid, SIGUSR2);
	}
	else
		c <<= 1;
}

int	main(int argc, char **argv)
{
	struct sigaction	sig;

	(void)argv;
	if (argc != 1)
		ft_printf("Erro: Formato invalido\nTente: ./server\n");
	else
	{
		minitalk_header();
		ft_printf("server iniciado!!->");
		ft_printf(" PID: %d\n", getpid());
		sig.sa_sigaction = sig_to_char;
		sigemptyset(&sig.sa_mask);
		sig.sa_flags = SA_SIGINFO;
		while (1)
		{
			sigaction(SIGUSR1, &sig, NULL);
			sigaction(SIGUSR2, &sig, NULL);
		}
	}
	return (0);
}
