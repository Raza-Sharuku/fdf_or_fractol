/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:07:26 by sraza             #+#    #+#             */
/*   Updated: 2023/05/08 20:56:05 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

/*ここではあらゆるMallocをしてNullじゃない場合の値を返す*/

void	*ft_free_int(t_info **b, t_array *a)
{
	int	j;

	j = 0;
	while (j < a->x_len)
	{
		// printf("a->x_len = %i\n", a->x_len);
		printf(" b[j(%i)]->height = \n", j);
		free(b[j]);
		b[j]= NULL;
		j++;
	}
	free(b);
	return (b);
}

void	*ft_free_int2(t_array *a)
{
	int	i;

	i = 0;
	while (i < a->y_len)
	{
		ft_free_int(&a->array[i], a);
		a->array[i] = NULL;
		i++;
	}
	free(a->array);
	return (NULL);
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
