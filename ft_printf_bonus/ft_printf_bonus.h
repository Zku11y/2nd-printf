/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:40:48 by mdakni            #+#    #+#             */
/*   Updated: 2024/11/14 18:40:49 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putnbr(int n);
int		ft_nbr_size(int a);
int		ft_printf(const char *num, ...);
int		ft_handle_c(va_list args, const char **content);
int		ft_handle_s(va_list args, const char **content);
int		ft_handle_u(va_list args, const char **content);
int		ft_handle_x(unsigned int nbr, const char **content);
int		ft_handle_p(va_list args, const char **content);
int		ft_handle_perc(const char **content);
int 	ft_handle_spcpls(va_list args, const char **content);
int 	ft_handle_tag(va_list args, const char **content);
int		ft_handle_id(int nbr, const char **content);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
#endif