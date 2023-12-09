#include "../include/minitalk.h"

void	minitalk_header(void)
{
	printf("\033[32m _____ _     _ _       _ _    \n");
	printf(" |     |_|___|_| |_ ___| | |_ \n");
	printf(" | | | | |   | |  _| .'| | '_|\n");
	printf(" |_|_|_|_|_|_|_|_| |__,|_|_,_|\n\033[37m");
}

void	handle_user_sig(int sig)
{
	if(sig == 10)
		printf("1");
	else if(sig == SIGUSR2)
		printf("0");
}

int	main(void)
{
	minitalk_header();
	printf("server iniciado!!->");
	printf(" PID: %d\n", getpid());
	while(1)
	{
		signal(SIGUSR1, handle_user_sig);
		signal(SIGUSR2, handle_user_sig);
	}
	return (0);
}
