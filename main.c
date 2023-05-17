/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:05:28 by razasharuku       #+#    #+#             */
/*   Updated: 2023/05/17 16:57:58 by razasharuku      ###   ########.fr       */
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

void	set_default(t_array *a, int argc, char **argv)
{
	double y;
	double x;
	double height_max;

	height_max = a->height;
	if (argc == 4)
		a->height = ft_atoi_fdf(argv[3]);
	else if (argc == 2)
		a->height = 0;
	if (a->height != 0 && a->height > height_max)
		height_max = a->height;
	x = 800 / a->x_len;
	y = 800 / a->y_len;
	if (x >= y)
		a->set.zoom = y;
	else 
		a->set.zoom = x;
	a->set.shift_x = (a->x_len * x) / 20;
	a->set.shift_y = (a->y_len * y + height_max * a->set.zoom) / 2;
	printf("x = %f ,y = %f , a->shift_x  = %i , a->shift_y = %i a->height = %f \n", x,y, a->set.shift_x, a->set.shift_y,a->height);
}

int	main(int argc, char *argv[])
{
	t_array	a;

	ft_arg_error(argc, argv, &a);
	printf("a.x_len = %f || a.y_len = %f\n", a.x_len, a.y_len);
	a.array = make_array(argv, &a);
	a.mlx_ptr = mlx_init();
	a.win = mlx_new_window(a.mlx_ptr, 1200, 1000, "raza");
	a.img_ptr = mlx_new_image(a.mlx_ptr, 1200, 1000);
	set_default(&a, argc, argv);
	draw_win(&a);
	// mlx_key_hook(a.win, keys, &a);
	mlx_loop(a.mlx_ptr);
	return (0);
}
