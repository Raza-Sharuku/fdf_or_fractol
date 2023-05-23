/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:07:26 by sraza             #+#    #+#             */
/*   Updated: 2023/05/23 15:53:40 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_free_int2(t_array *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->y_len)
	{
		j = 0;
		while (j < a->x_len)
		{
			free(a->array[i][j]);
			j++;
		}
		free(a->array[i]);
		i++;
	}
	free(a->array);
	return ;
}
