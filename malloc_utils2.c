/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:07:26 by sraza             #+#    #+#             */
/*   Updated: 2023/05/09 17:43:53 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/*ここではあらゆるMallocをしてNullじゃない場合の値を返す*/
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

// char	*int_malloc(t_array *a, int i, int len)
// {
// 	int	b_array;

// 	errno = 0;
// 	b_array = malloc(sizeof(int *) * len);
// 	if (errno != 0)
// 	{
// 		if (i != 0)

// 		ft_printf("%s\n", strerror(errno));
// 		exit(1);
// 	}
// 	return (b_array);
// }
