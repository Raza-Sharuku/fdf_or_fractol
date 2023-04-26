/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 20:26:29 by sraza             #+#    #+#             */
/*   Updated: 2023/03/24 12:16:29 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_nm
{
	int			len;
}				t_nm;
size_t			ft_strlen_printf(const char *s);
ssize_t			ft_putchar_printf(char c, t_nm len);
ssize_t			ft_putstr_printf(char *s, t_nm len);
ssize_t			ft_putunbr_printf(unsigned int ln, t_nm len);
ssize_t			ft_putnbr_printf(int n, t_nm len);
ssize_t			ft_hexa(unsigned int num, char x, t_nm len);
ssize_t			ft_pointer(uintptr_t num, char x, t_nm len);
ssize_t			ft_strptr_printf(char *s, t_nm len);
int				ft_printf(const char *format, ...);
char			*ft_strchr_printf(int c);

#endif
