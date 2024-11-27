/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:40:14 by mdakni            #+#    #+#             */
/*   Updated: 2024/11/26 12:20:24 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_perc_flags(va_list args, const char **content)
{
	*(content) = *(content) + 1;
	if(**content == ' ' || **content == '+')
		return(ft_handle_spcpls(args, content));
	else if(**content == '#')
		return(ft_handle_tag(args, content));
	else if (**content == 'c')
		return (ft_handle_c(args, content));
	else if (**content == 's')
		return (ft_handle_s(args, content));
	else if (**content == '%')
		return (ft_handle_perc(content));
	else if (**content == 'i' || **content == 'd')
		return (ft_handle_id(va_arg(args, int), content));
	else if (**content == 'u')
		return (ft_handle_u(args, content));
	else if (**content == 'x' || **content == 'X')
		return (ft_handle_x(va_arg(args, unsigned int), content));
	else if (**content == 'p')
		return (ft_handle_p(args, content));
	return (0);
}

int	ft_printf(const char *content, ...)
{
	va_list	args;
	int		size;

	size = 0;
	if (write(1, "", 0) == -1)
		return (-1);
	va_start(args, content);
	while (*content)
	{
		if (*content == '%')
			size += ft_perc_flags(args, &content);
		else
		{
			write(1, content, 1);
			content++;
			size++;
		}
	}
	va_end(args);
	return (size);
}
