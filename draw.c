/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 09:33:56 by razasharuku       #+#    #+#             */
/*   Updated: 2023/05/10 11:33:30 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
#include"./minilibx-linux/mlx.h"
#include"./minilibx-linux/mlx_int.h"

// void draw_window(t_array *a)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	while (i < 500)
// 	{
// 		j = 0;
// 		while (j < 500)
// 		{
// 			mlx_pixel_put(a->mlx_ptr, a->win, i, j, 0x4433FF);
// 			j = j + 10;
// 		}
// 		i = i + 1;
// 	}
// 	i = 0;
// 	while (i < 500)
// 	{
// 		j = 0;
// 		while (j < 500)
// 		{
// 			mlx_pixel_put(a->mlx_ptr, a->win, i, j, 0xFF33FF);
// 			j = j + 1;
// 		}
// 		i = i + 10;
// 	}
// 	mlx_loop(a->mlx_ptr);
// 	return ;
// }

void draw_window(t_array *a)
{
	int i;
	int j;

	i = 0;
	while (i < 500)
	{
		j = 0;
		while (j < 500)
		{
			mlx_pixel_put(a->mlx_ptr, a->win, i, j, 0x4433FF);
			j = j + 10;
		}
		i = i + 1;
	}
	mlx_loop(a->mlx_ptr);
	return ;
}