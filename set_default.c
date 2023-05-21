/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:35:16 by razasharuku       #+#    #+#             */
/*   Updated: 2023/05/21 15:38:06 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "fdf.h"

void	set_zoom(t_array *a, int height_max, double up_right)
{
	double	up_left;
	double	left_height;

	up_left = ((1 / sqrt(6)) * (a->x_len - 1)) + ((1 / sqrt(6)) * 0)
		- ((2 / sqrt(6)) * height_max);
	up_right = ((1 / sqrt(6)) * (a->x_len - 1))
		+ ((1 / sqrt(6)) * a->y_len - 1) - ((2 / sqrt(6)) * height_max);
	left_height = up_left;
	if (fabs(up_left) < fabs(up_right))
		left_height = up_right;
	a->set.zoom = 400 / (left_height);
	if (left_height < 0)
		a->set.zoom = (-left_height) / 400;
	if (left_height < 0)
		a->set.zoom = 10;
	if (a->set.zoom > 50)
		a->set.zoom = 30;
	if ((a->x_len > 100 && a->x_len < 200)
		|| (a->y_len > 100 && a->y_len < 200))
		a->set.zoom = 4.5;
	if ((a->x_len >= 200) || (a->y_len >= 200))
		a->set.zoom = 1.5;
	if (a->set.zoom < 5)
		a->set.shift_x = 0;
	return ;
}

void	set_default(t_array *a, int argc, char **argv)
{
	double	height_max;

	height_max = a->height;
	if (argc == 2)
		a->height = 0;
	if (a->height != 0 && a->height > height_max && a->height * a->y_len < 800)
		height_max = a->height;
	a->set.shift_x = 100;
	set_zoom(a, height_max, 0);
	if (argc == 4)
	{
		a->set.zoom = ft_atoi_fdf(argv[2]);
		a->height = ft_atoi_fdf(argv[3]);
	}
	a->set.angel = -1.5708;
	a->set.shift_y = 500;
	return ;
}
