/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:07:26 by sraza             #+#    #+#             */
/*   Updated: 2023/05/21 15:43:12 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

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
