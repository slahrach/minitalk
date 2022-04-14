/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slahrach <slahrach@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 04:28:34 by slahrach          #+#    #+#             */
/*   Updated: 2022/03/06 00:23:55 by slahrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
int		ft_putchar(int c);
int		ft_putnbr(int nb);
void	send_char(char n, int pid_s);
char	*ft_itoa(int nbr);
void	error(int a);

#endif