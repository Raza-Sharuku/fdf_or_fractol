/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 13:55:13 by sraza             #+#    #+#             */
/*   Updated: 2023/05/23 19:43:01 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_zoom(int key, t_array *a)
{
	if (key == 24)
		a->set.zoom *= 1.1;
	if (key == 27)
		a->set.zoom *= 0.9;
	return (0);
}

int	handle_rotate(int key, t_array *a)
{
	if (key == 122)
		a->set.z_a += 0.1;
	if (key == 107)
		a->set.z_a -= 0.1;
	if (key == 121)
		a->set.y_a += 0.1;
	if (key == 106)
		a->set.y_a -= 0.1;
	if (key == 120)
		a->set.x_a += 0.1;
	if (key == 105)
		a->set.x_a -= 0.1;
	return (0);
}

int	handle_translate(int key, t_array *a)
{
	if (key == 65361)
		a->set.shift_x -= 10;
	if (key == 65363)
		a->set.shift_x += 10;
	if (key == 65364)
		a->set.shift_y += 10;
	if (key == 65362)
		a->set.shift_y -= 10;
	return (0);
}

int	handle_win(int key, t_array *a)
{
	if (key == 65307)
	{
		mlx_destroy_window(a->mlx_ptr, a->win);
		free(a->mlx_ptr);
		ft_free_int2(a);
		exit (0);
	}
	handle_translate(key, a);
	handle_zoom(key, a);
	handle_rotate(key, a);
	mlx_destroy_image(a->mlx_ptr, a->img_ptr);
	draw_win(a);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_array *a)
{
	if (button == 5)
		a->set.zoom *= 1.1;
	if (button == 4)
		a->set.zoom *= 0.9;
	if (x == y)
		return (0);
	mlx_destroy_image(a->mlx_ptr, a->img_ptr);
	draw_win(a);
	return (0);
}
