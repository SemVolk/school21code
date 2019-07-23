/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_solv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhomer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 21:07:52 by jhomer            #+#    #+#             */
/*   Updated: 2019/07/22 21:07:54 by jhomer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// кол-во символов в строке qs
//

#include "bsq.h"

char three_min(char a, char b, char c)
{
	if(a < b)
	{
		if(c < a)
			return c;
		else 
			return a;
	}else if(c < b)
	
		return c;
	else 
		return b;
}

void calculate(void)
{
	int		i;

	i = qs + 2;
	while (i < length_arr-1)
	{
		if (i == qs || ((i - qs) % (qs + 1) == 0))	//Пропускаем \n
		{
			i += 2;									//
			continue ;
		}

		if (arr[i] == 0)
		{							//Пропускаем символ 0
			i++;									//
			continue ;
		}
		// if (i == 25)
		// {
		// 	ft_putstr("26й = "); ft_putnbr(arr[26]);  ft_putchar('\n');
		// 	ft_putstr("upp = "); ft_putnbr(arr[IU]);  ft_putchar('\n');
		// 	ft_putstr("lef = "); ft_putnbr(arr[IL]);  ft_putchar('\n');
		// 	ft_putstr("dia = "); ft_putnbr(arr[ID]);  ft_putchar('\n');

		// }
		arr[i] = three_min(arr[IL], arr[IU], arr[ID]) + 1;
		i++;
	}



	// 		i = 0;
	// while (i < length_arr-1)
	// {
	// 	if (i == qs || ((i - qs) % (qs + 1) == 0))
	// 	{
	// 		ft_putchar('\n');
	// 	i++;
	// 	}
	// 	ft_putchar(arr[i]+'0');
	// 	i++;
	// }

}

void	ft_fill_arr(char *fname, int *m)
{
	int	fd;
	int	tmp;
	//char *buf;
	int i;
	int c;
	int f;


	i = 0;
	c = 0;
	f = 0;


	arr = (char *)malloc(sizeof(char) * qs * ql);

	length_arr = (qs+1) * (ql);
	fd = open(fname, O_RDONLY);
	tmp = read(fd, arr, m[5]);


	//tmp = (qs * ql +  m[5]) / 1000 + 1; //сколько иттераций надо сделать по 1000 байт для заполнения массива.
	
		tmp = read(fd, arr, (qs+1) * (ql));//прочитали 1000 символов

	// i = 0;
	// while (i < length_arr)
	// {
	// 	if (i == qs || ((i - qs) % (qs + 1) == 0))
	// 	{
	// 		//ft_putchar('=');
	// 	//i++;
	// 	}
	// 	ft_putchar(arr[i]);
	// 	i++;
	// }
	// 	ft_putchar('\n');


		////////перевод символов в 0 и 1/////////
		i = 0;
		while (i < length_arr)
		{
			if(arr[i] == (char) m[2])
				arr[i] = 1;
			else if (arr[i] == m[3])
				arr[i] = 0;
			i++;		
		}
		//////////////////////////////////////////
/////
	// 	ft_putchar('\n');
		

	// 		i = 0;
	// while (i < length_arr-1)
	// {
	// 	if (i == qs || ((i - qs) % (qs + 1) == 0))
	// 	{
	// 		ft_putchar('\n');
	// 	i++;
	// 	}
	// 	ft_putchar(arr[i]+'0');
	// 	i++;
	// }

	// ft_putchar('\n');
	// ft_putchar('\n');
//////


		calculate();



}



void	ft_get_map_info(char *fname)
{
	int fd;
	int i;
	int m[7];
	int start_arr;
	char buf[1025];
	int tmp;

	fd = open(fname, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("map error");
		return ;
	}

	tmp = read(fd, buf, 16);
	ql = ft_atoi(buf); // количество строк в файле
	i = 0;
	while (buf[i] >= '0' && buf[i] <= '9')
		i++;
	m[2] = (int)buf[i]; // "пустой" символ
	m[3] = (int)buf[i+1]; // символ "препятствия"
	m[4] = (int)buf[i+2]; // символ "заполнения"
	i = 0;
	while (buf[i] != '\n')   // ищем начало таблицы (после строки с параметрами)
		i++;
	m[5] = i+1; //кол-во символов в первой строкке(инфо кол-во строк + символы которые исп).
	
	ft_putstr("Длина первой строки   "); ft_putnbr(m[5]); ft_putchar('\n');

	//пытаемся узнать длину строки
	close(fd);
	fd = open(fname, O_RDONLY);
	start_arr = 0;
	m[6] = 0;
	while (start_arr == 0)
	{
		if (m[6] == 0)
			i = m[5] + 1;
		else
			i = 0;

			tmp = read(fd, buf, 1000);
			ft_putstr("Read Buf  "); ft_putnbr(tmp); ft_putchar('\n');
		
		while (buf[i] != '\n' && i <= tmp)
			i++;

		ft_putstr("i  "); ft_putnbr(i); ft_putchar('\n');

		if (i-1 != tmp)
			start_arr = 1;
		else
			m[6]++;
	}

	qs = m[6] * 100 + i - m[5]; // кол-во символов в строке

	ft_putstr("Map  "); ft_putnbr(qs); ft_putstr("  on  "); ft_putnbr(ql); ft_putchar('\n');
	ft_putstr("Empty symb - '"); ft_putchar((char)m[2]); ft_putchar('\''); ft_putchar(' ');
	ft_putstr("Rock symb  - '"); ft_putchar((char)m[3]); ft_putchar('\''); ft_putchar(' ');
	ft_putstr("Fill symb  - '"); ft_putchar((char)m[4]); ft_putchar('\'');
	ft_putchar('\n');

	close(fd);
	
	ft_fill_arr(fname, m);

}



void	ft_solver(char *fname)
{
	

	ft_get_map_info(fname);



}
