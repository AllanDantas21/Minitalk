#include <signals.h>
#include <stdio.h>
#include <unistd.h>

void	handle_user_sig(int sig)
{
	write(1, "test", 4);
}

int	main(void)
{
	int pid = getpid(
}
