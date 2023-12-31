/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aldantas <aldantas@student.42.rio>		    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 09:21:52 by aldantas          #+#    #+#             */
/*   Updated: 2023/12/15 10:11:04 by aldantas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minitalk.h"

static void	sig_ack(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Mensagem recebida!\n");
	else
		ft_printf("Mensagem recebida!\n");
}

void	char_to_sig(int pid, char character)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (character & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(200);
	}
}

void	send_msg(int id, char *msg)
{
	int	i;

	i = 0;
	while (msg[i])
	{
		char_to_sig(id, msg[i++]);
	}
	char_to_sig(id, '\n');
}

int	check_args(char *pid, char *msg_arg)
{
	if (!msg_arg)
		return (-1);
	while (*pid)
	{
		if (!ft_isdigit(*pid))
		{
			ft_printf("o pid só deve conter digitos!");
			return (-1);
		}
		pid++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	id;

	if (argc == 3)
	{
		if (check_args(argv[1], argv[2]) == -1)
			return (0);
		signal(SIGUSR1, sig_ack);
		signal(SIGUSR2, sig_ack);
		id = ft_atoi(argv[1]);
		send_msg(id, argv[2]);
	}
	else
	{
		ft_printf("Erro, os argumentos de entrada estão errados!\n");
		ft_printf("os argumentos devem ser: [./client PID mensagem]\n");
	}
	return (0);
}
