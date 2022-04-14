/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 23:26:37 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/06 00:16:55 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error(int a)
{
	if (a == 1)
		write(1, "the number of arguments is invalid !", 36);
	exit(0);
}

int	ft_atoi(const char *str)
{
	int		sign;
	size_t	nbr;

	sign = 1;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9' )
	{
		nbr = (nbr * 10) + (*str - '0');
		str++;
	}
	return ((sign * nbr));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_putchar(int c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	int		c;
	long	n;

	n = nb;
	c = 0;
	if (n < 0)
	{
		n *= -1;
		c += ft_putchar ('-');
	}
	if (n > 9)
	{
		c += ft_putnbr(n / 10);
		n = n % 10;
	}
	c += ft_putchar (n + '0');
	return (c);
}
