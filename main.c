/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:05:28 by razasharuku       #+#    #+#             */
/*   Updated: 2023/05/16 17:52:24 by razasharuku      ###   ########.fr       */
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

// int	close(int key, t_array *a)
// {
// 	ft_free_int2(&a);
// 	mlx_destroy_window(a->mlx_ptr, a->win);
// 	exit(0);
// }

// int	keys(int key, t_array *a)
// {

	
// }

void	set_default(t_array *a, int argc, char *argv[])
{
	double y;
	double x;
	// double z;

	if (argc == 4)
		a->height = ft_atoi_fdf(argv[3]);
	else if (argc == 2)
		a->height = 0;
	x = 400 / a->x_len;
	y = 400 / a->y_len;
	if (x > y)
		a->zoom = y;
	else 
		a->zoom = x;
	a->shift_x = 200;
	a->shift_y = 500;

}

int	main(int argc, char *argv[])
{
	t_array	a;

	ft_arg_error(argc, argv, &a);
	printf("a.x_len = %f || a.y_len = %f\n", a.x_len, a.y_len);
	a.array = make_array(argv, &a);
	a.mlx_ptr = mlx_init();
	a.win = mlx_new_window(a.mlx_ptr, 1000, 1000, "raza");
	a.img_ptr = mlx_new_image(a.mlx_ptr, 1000, 1000);
	set_default(&a, argc, &argv[3]);
	// a.zoom = 10;
	// a.shift_x = 10;
	// a.shift_y = 300;
	draw_win(&a);
	// mlx_key_hook(a.win, keys, &a);
	mlx_loop(a.mlx_ptr);
	return (0);
}
