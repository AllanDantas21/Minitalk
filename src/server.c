/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <student@student.42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:23:49 by aldantas          #+#    #+#             */
/*   Updated: 2023/12/15 09:25:40 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minitalk.h"

void	minitalk_header(void)
{
	ft_printf ("\033[32m___  ___ _         _  _           _  _\n");
	ft_printf("|  \\/  |(_)       (_)| |         | || |       \n");
	ft_printf("| .  . | _  _ __   _ | |_   __ _ | || | __     \n");
	ft_printf("| |\\/| || || '_ \\ | || __| / _` || || |/ /   \n");
	ft_printf("| |  | || || | | || || |_ | (_| || ||   <      \n");
	ft_printf("\\_|  |_/|_||_| |_||_| \\__| \\__,_||_||_|\\_\\	\n\033[37m");
}

void	sig_to_char(int sig)
{
	static int				i = 0;
	static unsigned char	c = 0;

	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	else
		c <<= 1;
}

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 1)
		ft_printf("Erro: Formato invalido\nTente: ./server\n");
	else
	{
		minitalk_header();
		ft_printf("server iniciado!!->");
		ft_printf(" PID: %d\n", getpid());
		while (1)
		{
			signal(SIGUSR1, sig_to_char);
			signal(SIGUSR2, sig_to_char);
		}
	}
	return (0);
}
