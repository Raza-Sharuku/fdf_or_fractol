/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:59:58 by sraza             #+#    #+#             */
/*   Updated: 2023/03/24 12:16:36 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

ssize_t	ft_putunbr_printf(unsigned int ln, t_nm len)
{
	if (ln == 0)
		len.len = ft_putchar_printf('0', len);
	if (ln <= 9 && ln > 0)
		len.len = ft_putchar_printf(ln + 48, len);
	else if (ln > 0)
	{
		len.len = ft_putunbr_printf(ln / 10, len);
		len.len = ft_putchar_printf(ln % 10 + 48, len);
	}
	return (len.len);
}
