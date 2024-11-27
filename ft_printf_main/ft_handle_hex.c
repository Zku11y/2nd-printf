/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:40:58 by mdakni            #+#    #+#             */
/*   Updated: 2024/11/27 11:08:53 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rev_str(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	while (len >= 0)
		write(1, &str[len--], 1);
}

int	ft_long_to_hex(unsigned long nbr)
{
	int		size;
	char	hex[16];
	char	str[20];

	size = 0;
	if (nbr == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_strlcpy(hex, "0123456789abcdef", sizeof(hex) + 1);
	while (nbr > 0)
	{
		str[size] = hex[nbr % 16];
		nbr = nbr / 16;
		size++;
	}
	str[size] = '\0';
	ft_putstr_fd("0x", 1);
	ft_rev_str(str);
	return (size + 2);
}

void	ft_hex_fill(char *hex, const char **content)
{
	if (**content == 'x')
		ft_strlcpy(hex, "0123456789abcdef", 17);
	else
		ft_strlcpy(hex, "0123456789ABCDEF", 17);
	*(content) = *(content) + 1;
}

int	ft_handle_x(unsigned int nbr, const char **content)
{
	int				size;
	char			hex[16];
	char			str[20];

	size = 0;
	ft_hex_fill(hex, content);
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nbr > 0)
	{
		str[size++] = hex[nbr % 16];
		nbr = nbr / 16;
	}
	str[size] = '\0';
	ft_rev_str(str);
	return (size);
}

int	ft_handle_p(va_list args, const char **content)
{
	void			*ptr;
	unsigned long	nbr;
	int				size;

	ptr = va_arg(args, void *);
	nbr = (unsigned long)ptr;
	size = ft_long_to_hex(nbr);
	*(content) = *(content) + 1;
	return (size);
}
