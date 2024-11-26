/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dec_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:40:53 by mdakni            #+#    #+#             */
/*   Updated: 2024/11/26 14:29:59 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	nbr_u_size(unsigned int a)
{
	int	size;

	size = 0;
	while (a / 10 > 0)
	{
		a = a / 10;
		size++;
	}
	return (size + 1);
}

void	putnbr_u(unsigned int n)
{
	char	chr;
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		putnbr_u(nbr / 10);
	chr = (nbr % 10) + '0';
	write(1, &chr, 1);
}

int	handle_u(va_list args, const char **content)
{
	unsigned int	a;

	a = va_arg(args, unsigned int);
	putnbr_u(a);
	*(content) = *(content) + 1;
	return (nbr_u_size(a));
}

int handle_spcpls(va_list args, const char **content)
{
	int size;
	int i;
	int flag;
	int nbr;

	i = 0;
	size = 0;
	flag = 0;
	nbr = va_arg(args, int);
	while(**content == ' ')
		*(content) = *(content) + 1;
	if((*(*content - 1) == ' ') && (**content == 'd' || **content == 'i') && (nbr > 0))
		return(write(1, " ", 1), handle_id(nbr, content) + 1);
	while(**content == '+' || **content == ' ')
	{
		*(content) = *(content) + 1;
		flag = 1;
	}
	if((flag == 1) && (**content == 'd' || **content == 'i') && (nbr > 0))
		return(write(1, "+", 1), handle_id(nbr, content) + 1);
	return (handle_id(nbr, content));
}

int	handle_id(int nbr, const char **content)
{
	putnbr(nbr);
	*(content) = *(content) + 1;
	return (nbr_size(nbr));
}
