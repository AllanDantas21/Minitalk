#include "../include/minitalk.h"

void	minitalk_header(void)
{
	ft_printf("\033[32m _____ _     _ _       _ _    \n");
	ft_printf(" |     |_|___|_| |_ ___| | |_ \n");
	ft_printf(" | | | | |   | |  _| .'| | '_|\n");
	ft_printf(" |_|_|_|_|_|_|_|_| |__,|_|_,_|\n\033[37m");
}

void	handle_user_sig(int sig)
{
	//ft_printf("um sinal foi recebido");
	if(sig == SIGUSR1)
		ft_printf("1");
	if(sig == SIGUSR2)
		ft_printf("0");
}

int	main(void)
{
	minitalk_header();
	ft_printf("server iniciado!!->");
	ft_printf(" PID: %d\n", getpid());
	while(1)
	{
		signal(SIGUSR1, handle_user_sig);
		signal(SIGUSR2, handle_user_sig);
	}
	return (0);
}
