/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_hexa_demical_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 13:38:00 by razasharuku       #+#    #+#             */
/*   Updated: 2023/05/23 15:54:24 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	return_num(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else if (c >= 'a' && c <= 'f')
		return (10 + c - 'a');
	else
		return (-1);
}

int	to_demical(char *str)
{
	int	demical;
	int	num;

	demical = 0;
	str++;
	str++;
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
