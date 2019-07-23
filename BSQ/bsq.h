/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhomer <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 20:44:54 by jhomer            #+#    #+#             */
/*   Updated: 2019/07/22 20:44:57 by jhomer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 100
#define IL i - 1
#define IU i - qs - 1
#define ID i - qs - 2


char		*arr;
int		qs;//кол-во символов
int		ql;//кол-во строк
int		length_arr;
int		ft_strlen(char *s);
int		ft_atoi(char *str);
void	ft_putchar(char ch);
void	ft_putstr(char *str);
void	ft_putnbr(int nbr);




void	ft_solver(char *fname);
void	ft_fill_arr(char *fname, int *m);

#endif
