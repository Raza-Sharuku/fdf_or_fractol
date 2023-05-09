/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:05:28 by razasharuku       #+#    #+#             */
/*   Updated: 2023/05/09 17:44:11 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "fdf.h"

void	print_array(t_array *a)
{
	int	i;
	int	j;

	i = 0;
	printf("\n========================================     ==========================================\n\n");
	while (i < a->y_len)
	{
		j = 0;
		while (j < a->x_len)
		{
			if (a->array[i][j][0] < 10)
			{
				printf("%i  ", a->array[i][j][0]);
				if (a->array[i][j][1] != 0)
					printf(",%i  ", a->array[i][j][1]);
			}
			else if (a->array[i][j][0] > 9)
			{
				printf("%i ", a->array[i][j][0]);
				if (a->array[i][j][1] != 0)
					printf(",%i  ", a->array[i][j][1]);
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
	printf("a.x_len = %d || a.y_len = %d\n", a.x_len, a.y_len);
	a.array = make_array(argv, &a);
	print_array(&a);
	ft_free_int2(&a);
	return (0);
}

// __attribute__((destructor))
// void    destructor(void)
// {
// 	system("leaks -q myfdf");

// }
