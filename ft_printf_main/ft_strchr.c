/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skully <skully@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:23:53 by mdakni            #+#    #+#             *///<- change name to mdakni
/*   Updated: 2024/11/27 11:04:10 by skully           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		ptr = &s[i];
	return ((char *)ptr);
}
