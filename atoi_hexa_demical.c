/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_hexa_demical.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:38:00 by razasharuku       #+#    #+#             */
/*   Updated: 2023/05/10 20:49:24 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	return_num(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (10 + c - '0');
	else
		return (-1);
}

int	to_demical(char *str)
{
	int	demical;
	int	num;

	demical = 0;
	str = (str + 2);
	while (str)
	{
		num = return_num(ft_tolower(*str));
		if (num < 0)
			break ;
		demical = demical * 16;
		demical = demical + num;
		str++;
	}
	return (demical);
}

// int	to_hexa(int num)
// {
// 	char	*hexa;
// 	char	x;

// 	hexa = "0123456789abcdef";
// 	if (num == 0)
// 		len.len = ft_putchar('0', len);
// 	if (num <= 15 && num > 0)
// 		len.len = ft_putchar(hexa[num], len);
// 	else if (num > 0)
// 	{
// 		len.len = ft_hexa(num / 16, x, len);
// 		len.len = ft_putchar(hexa[num % 16], len);
// 	}
// 	return (len.len);
// }