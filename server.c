#include "minitalk.h"

void	handle_user_sig(int sig)
{
	write(1, "test", 4);
}

int	main(void)
{	
	printf("_____ _     _ _       _ _    \n");
	printf("|     |_|___|_| |_ ___| | |_ \n");
	printf("| | | | |   | |  _| .'| | '_|\n");
	printf("|_|_|_|_|_|_|_|_| |__,|_|_,_|\n");
	printf("server iniciado!!->");
	printf("PID: %d\n", getpid());
	while(1)
	{
		signal(SIGUSR1, handle_user_sig);
		signal(SIGUSR2, handle_user_sig);
	}
	return (0);
}
