/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_print.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:41:42 by mdakni            #+#    #+#             */
/*   Updated: 2024/11/26 14:33:13 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle_c(va_list args, const char **content)
{
	char	a;

	a = (char)va_arg(args, int);
	write(1, &a, 1);
	*(content) = *(content) + 1;
	return (1);
}

int	ft_handle_perc(const char **content)
{
	write(1, &(**content), 1);
	*(content) = *(content) + 1;
	return (1);
}

int	ft_handle_s(va_list args, const char **content)
{
	char	*str;
	int		size;

	str = va_arg(args, char *);
	*(content) = *(content) + 1;
	if (str == (char *) NULL)
	{
		write(1, &"(null)", 6);
		return (6);
	}
	size = ft_strlen(str);
	write(1, str, size);
	return (size);
}
