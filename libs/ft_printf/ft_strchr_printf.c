/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 20:23:03 by razasharuku       #+#    #+#             */
/*   Updated: 2023/03/19 12:22:25 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

char	*ft_strchr_printf(int c)
{
	char		cc;
	const char	*s;

	s = "cdiuxXp";
	cc = (char)(c);
	while (*s != '\0')
	{
		if (*s == cc)
			return ((char *)s);
		s++;
	}
	if (cc == '\0' && *s == cc)
		return ((char *)s);
	return (NULL);
}
