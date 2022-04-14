/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 04:01:27 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/06 01:07:28 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char n, int pid_s)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (n & (0x01))
			kill(pid_s, SIGUSR1);
		else
			kill(pid_s, SIGUSR2);
		i++;
		n >>= 1;
		usleep(300);
	}
}

void	func(int sig)
{
	if (sig == SIGUSR1)
	{
		write (1, "Signal received\n", 17);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int		l;
	int		j;
	char	*pid_c;
	int		pid_s;

	if (argc != 3)
		error(1);
	signal (SIGUSR1, func);
	j = 0;
	pid_s = ft_atoi(argv[1]);
	l = ft_strlen(argv[2]);
	while (j <= l)
		send_char(argv[2][j++], pid_s);
	send_char(10, pid_s);
	pid_c = ft_itoa(getpid());
	l = ft_strlen(pid_c);
	j = 0;
	while (j <= l)
		send_char(pid_c[j++], pid_s);
	pause();
	return (0);
}
