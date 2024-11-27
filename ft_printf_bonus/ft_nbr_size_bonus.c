/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_size_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:44:36 by mdakni            #+#    #+#             */
/*   Updated: 2024/11/27 11:21:22 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_nbr_size(int a)
{
	int		size;
	int		sign;
	long	nbr;

	size = 0;
	sign = 0;
	nbr = a;
	if (nbr < 0)
	{
		sign = 1;
		nbr = nbr * -1;
	}
	while (nbr / 10 > 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return ((size + 1) + sign);
}