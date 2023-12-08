#include "minitalk.h"

void	handle_user_sig(int sig)
{
	write(1, "test", 4);
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
