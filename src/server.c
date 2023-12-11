#include "../include/minitalk.h"

void	minitalk_header(void)
{
	//ft_printf("\033[32m _____ _     _ _       _ _    \n");
	//ft_printf(" |     |_|___|_| |_ ___| | |_ \n");
	//ft_printf(" | | | | |   | |  _| .'| | '_|\n");
	//ft_printf(" |_|_|_|_|_|_|_|_| |__,|_|_,_|\n\033[37m");
	ft_printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣯⣥⣤⣾⠟⡛⠿⠿⣭⣻⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⡟⣿⣽⡟⡏⢩⣦⡝⠋⢸⣶⠄⢲⡟⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣯⣷⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣌⡳⣜⢿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢀⡛⢌⢿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠁⠄⠙⠌⣸⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⡿⠉⠉⠉⠉⢿⣿⣿⣿⠏⠉⠉⠉⠉⠉⠆⠄⠁⠄⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⡗⠫⠿⠆⠄⠸⢿⣿⣿⠂⠒⠲⡿⠛⠛⠂⠄⠄⢠⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⡛⣧⡔⠢⠴⣃⣠⣼⣿⣧⡀⠘⢢⣀⠄⠄⠄⠄⠄⢈⠁⢿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣶⣿⠄⠄⠄⣸⠆⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⣿⣿⣿⣿⣼⢿⣿⣿⣿⣿⡀⠄⠘⡀⢠⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⡌⠿⣫⣿⣦⠬⢭⣥⣶⣬⣾⣿⢿⣿⡟⠄⢀⣿⣶⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣧⠘⣉⠛⢻⣛⣛⣛⣻⡶⠮⠙⠃⣉⠄⠄⢸⣿⣿⣿⣿⣿⣿⣿⣿\n⣿⣿⣿⣿⣿⣿⡆⠸⣿⣶⢾⣿⣯⣤⣄⣀⣾⡟⠄⠄⠄⢸⣿⣿⣿⣿⣿⣿⣿⣿\n⠟⠿⠿⠿⠿⢿⣷⠄⣿⣿⣎⣹⢻⣿⣿⡿⡿⠁⠄⠄⠄⢸⣿⣿⣿⣿⣿⣿⣿\n⠄⠄⠄⠄⠄⠄⠄⣠⠘⣿⣿⣿⣿⣿⣿⡟⠁⣀⣀⣀⠄⠘⠿⣿⣿⣿⣿⣿⣿⣿\n");
}

char binaryToChar(const char* binary) {
    int value = 0;
	int i = 0;

    while(binary[i] != '\0')
	{
        value = (value << 1) | (binary[i] - '0');
		i++;
    }
    return ((char)value);
}

void	handle_user_sig(int sig)
{
	static int				i = 0;
	static char				bits[8];
	//ft_printf("um sinal foi recebido");

	if (sig == SIGUSR1)
		bits[i++] = 1;	
	if (sig == SIGUSR2)
		bits[i++] = 0;
	if (i == 8)
	{
		ft_printf("printando bit:%c", binaryToChar(bits));
		i = 0;
	}
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
