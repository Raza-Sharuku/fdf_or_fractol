/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:43:37 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/19 12:27:45 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

ssize_t	ft_hexa(unsigned int num, char x, t_nm len)
{
	char	*hexa;

	if (x == 'X')
		hexa = "0123456789ABCDEF";
	if (x == 'x')
		hexa = "0123456789abcdef";
	if (num == 0)
		len.len = ft_putchar_printf('0', len);
	if (num <= 15 && num > 0)
		len.len = ft_putchar_printf(hexa[num], len);
	else if (num > 0)
	{
		len.len = ft_hexa(num / 16, x, len);
		len.len = ft_putchar_printf(hexa[num % 16], len);
	}
	return (len.len);
}
