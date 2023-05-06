/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:05:28 by razasharuku       #+#    #+#             */
/*   Updated: 2023/05/06 20:46:32 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "fdf.h"

void	print_array(t_array *a)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->y_len)
	{
		j = 0;
		while (j < a->x_len)
		{
			if (a->array[i][j].height < 10)
			{
				printf("%i  ", a->array[i][j].height);
				if (a->array[i][j].color != 0)
					printf(",%i  ", a->array[i][j].color);
			}
			else if (a->array[i][j].height > 9)
			{
				printf("%i ", a->array[i][j].height);
				if (a->array[i][j].color != 0)
					printf(",%i", a->array[i][j].color);
			}
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n========================================     ==========================================\n");
}

int	main(int argc, char *argv[])
{
	t_array	a;

	ft_arg_error(argc, argv, &a);
	// printf("a.x_len = %d || a.y_len = %d\n", a.x_len, a.y_len);
	// printf("Nothing is wrong with arguments\n");
	a.array = make_array(argv, &a);
	print_array(&a);
	
	return (0);
}
