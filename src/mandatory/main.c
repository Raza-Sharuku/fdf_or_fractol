/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:05:28 by razasharuku       #+#    #+#             */
/*   Updated: 2023/05/23 15:42:53 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minilibx-linux/mlx.h"
#include "fdf.h"

int	destory(t_array *a)
{
	mlx_destroy_window(a->mlx_ptr, a->win);
	free(a->mlx_ptr);
	ft_free_int2(a);
	exit (0);
}

int	main(int argc, char *argv[])
{
	t_array	a;

	ft_arg_error(argc, argv, &a);
	a.array = make_array(argv, &a);
	a.mlx_ptr = mlx_init();
	a.win = mlx_new_window(a.mlx_ptr, 1000, 1000, "fdf");
	set_default(&a, argc, argv);
	draw_win(&a);
	mlx_hook(a.win, 2, 1L << 0, &handle_win, &a);
	mlx_hook(a.win, 4, 1L << 2, &handle_mouse, &a);
	mlx_hook(a.win, 17, 0, &destory, &a);
	mlx_loop(a.mlx_ptr);
	return (0);
}
