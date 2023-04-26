/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:26:17 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/19 12:23:31 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

ssize_t	ft_putstr_printf(char *s, t_nm len)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		len.len = ft_putchar_printf(s[i], len);
		i++;
	}
	return (len.len);
}
