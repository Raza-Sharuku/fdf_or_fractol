/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:41:50 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/19 12:23:51 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

ssize_t	ft_putnbr_printf(int n, t_nm len)
{
	unsigned int	ln;

	if (n < 0)
	{
		len.len = ft_putchar_printf('-', len);
		ln = -n;
	}
	else
		ln = n;
	len.len = ft_putunbr_printf(ln, len);
	return (len.len);
}
