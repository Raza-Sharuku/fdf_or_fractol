/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 12:31:19 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/19 12:27:00 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static ssize_t	ft_per_printer(const char format, uintptr_t ap, t_nm len)
{
	if (format == 'c')
		len.len = ft_putchar_printf(ap, len);
	if (format == 'd' || format == 'i')
		len.len = ft_putnbr_printf(ap, len);
	if (format == 'u')
		len.len = ft_putunbr_printf(ap, len);
	if (format == 'X' || format == 'x')
		len.len = ft_hexa(ap, format, len);
	if (format == 'p')
	{
		len.len = ft_putstr_printf("0x", len);
		len.len = ft_pointer(ap, 'x', len);
	}
	else if (!(ft_strchr_printf(format)))
		len.len = ft_putchar_printf(format, len);
	return (len.len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_nm	len;

	len.len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != 0)
		{
			if (*(format + 1) == 's')
				len.len = ft_strptr_printf(va_arg(ap, char *), len);
			if (*(format + 1) != 's' && !ft_strchr_printf(*(format + 1)))
				len.len = ft_putchar_printf('%', len);
			else if (ft_strchr_printf(*(format + 1)))
				len.len = ft_per_printer(*(format + 1), \
				va_arg(ap, uintptr_t), len);
			format++;
		}
		else
			len.len = ft_putchar_printf(*format, len);
		format++;
	}
	va_end(ap);
	return (len.len);
}
