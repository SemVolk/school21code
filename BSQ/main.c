/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhomer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:49:33 by jhomer            #+#    #+#             */
/*   Updated: 2019/07/22 20:49:36 by jhomer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "time.h"
#include <stdio.h>


void	ft_read_stdin(void)
{
	int		read_i;
	char	buffer[BUFFER_SIZE + 1];

	read_i = 0;
	while ((read_i = read(0, buffer, BUFFER_SIZE)))
	{
		buffer[read_i] = '\0';
		ft_putstr(buffer);
	}
}

int main(int argc, char *argv[])
{
	clock_t start = clock();
	int		i;
	
	i = 1;
	if (argc == 1) //если нет аргументов, то поддержка стандартного ввода. (таблица с клавы или эхо)
	{
		ft_read_stdin();
	// i = 0;
	// while (read(0, &ch, 1) > 0)
	// 		i = i + write(1, &ch, 1) - 1;
	// return (i);
	}
	else if (argc > 1)// если есть аргументы проходим открываем ох в цикле и выполняем основной код.
	{
		while (i < argc)
		{

			ft_solver(argv[i]);
			i++;
		}
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	ft_putstr("\n time is ");
	printf("%f\n", seconds);
	ft_putstr("\n");
}
