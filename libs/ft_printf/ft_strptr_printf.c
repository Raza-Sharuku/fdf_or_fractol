/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strptr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:14:48 by sraza             #+#    #+#             */
/*   Updated: 2023/03/19 12:23:24 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

ssize_t	ft_strptr_printf(char *s, t_nm len)
{
	if (s == NULL)
		len.len = ft_putstr_printf("(null)", len);
	else
		len.len = ft_putstr_printf(s, len);
	return (len.len);
}
