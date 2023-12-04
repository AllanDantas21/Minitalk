#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdio.h>

int x = 0;

void handle_sigusr1(int signal) {
	if (x == 0)
		printf ("(HINT) Remember that multiplication is repetitive addiction\n");
}

int	main(int argc, char* argv[])
{
	int pid = fork();
	if (pid == -1){
		return (1);	
	}
	if (pid == 0)
	{
		sleep (5);
		kill(getpid(), SIGUSR1);
	} else 
	{
		struct sigaction sa = { 0 };
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL); 
		printf("qual o resultado de 3 x 5:");
		scanf("%d", &x);
		if (x == 15)
			printf("certo!");
		else
			printf("errado!");
	}
	wait(NULL);
}
