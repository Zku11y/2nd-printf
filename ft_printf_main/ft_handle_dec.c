/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_dec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:40:53 by mdakni            #+#    #+#             */
/*   Updated: 2024/11/27 11:10:08 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbr_u_size(unsigned int a)
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

void	ft_putnbr_u(unsigned int n)
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
		ft_putnbr_u(nbr / 10);
	chr = (nbr % 10) + '0';
	write(1, &chr, 1);
}

int	ft_handle_u(va_list args, const char **content)
{
	unsigned int	a;

	a = va_arg(args, unsigned int);
	ft_putnbr_u(a);
	*(content) = *(content) + 1;
	return (ft_nbr_u_size(a));
}

int	ft_handle_id(int nbr, const char **content)
{
	ft_putnbr(nbr);
	*(content) = *(content) + 1;
	return (ft_nbr_size(nbr));
}
