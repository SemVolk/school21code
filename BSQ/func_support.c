/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_support.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhomer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:50:26 by jhomer            #+#    #+#             */
/*   Updated: 2019/07/22 20:50:29 by jhomer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while(s[i])
		i++;
	return i;
}

int	ft_atoi(char *str)
{
	int	i;
	int	negativ;
	int	number;

	i = 0;
	negativ = 0;
	number = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == 45)
		negativ = 1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		number *= 10;
		number += ((int)str[i] - 48);
		i++;
	}
	if (negativ == 1)
		return (-number);
	else
		return (number);
}

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
	return ;
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		write(1, &str[i++], 1);
	return ;
}

void	ft_putnbr(int nbr)
{
	char	str[11];
	int		index;
	long	nb;

	nb = (long)nbr;
	index = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == 0)
		ft_putchar('0');
	while (nb >= 1)
	{
		str[index] = nb % 10 + '0';
		nb = nb / 10;
		index++;
	}
	str[index] = '\0';
	while (index > 0)
		ft_putchar(str[--index]);
	return ;
}
