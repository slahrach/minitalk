/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 04:01:42 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/06 00:39:36 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	power_two(int r)
{
	int	p;

	p = 1;
	if (r == 0)
		return (1);
	else if (r == 1)
		return (2);
	while (r > 0)
	{
		p *= 2;
		r--;
	}
	return (p);
}

static void	receive_cpid(unsigned char *a, int *x, int *b)
{
	int			c_pid;
	static char	str[10];

	str[(*b) - 1] = *a;
	(*b)++;
	if (*a == '\0')
	{
		c_pid = atoi(str);
		kill(c_pid, SIGUSR1);
		usleep(300);
		*b = 0;
	}
	*x = 0;
	*a = 0;
}

static void	handler(int SIG)
{
	static unsigned char	a;
	static int				x;
	static int				b;

	if (b > 0 && x == 7)
		receive_cpid(&a, &x, &b);
	else if (x == 7)
	{
		if (a == '\n')
			b = 1;
		ft_putchar(a);
		x = 0;
		a = 0;
	}
	else
	{
		if (SIG == 30)
			a += power_two(x);
		x++;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "My Pid is : ", 12);
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
