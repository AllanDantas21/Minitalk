#include "minitalk.h"

void	handle_user_sig(int sig)
{
	write(1, "test", 4);
}

int	main(void)
{
	int pid = getpid();
	struct sigaction sa =  {0};

	printf("%d", pid);
	sa.sa_flags = SA_RESTART;
	sa.sa_handler = &handle_user_sig;
	while(1)
		sleep(1);
	sigaction(SIGUSR1, &sa, NULL);
	return(0);
}
