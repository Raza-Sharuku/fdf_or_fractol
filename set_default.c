/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:35:16 by razasharuku       #+#    #+#             */
/*   Updated: 2023/05/18 17:52:27 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "fdf.h"

void	set_zoom(t_array *a, int height_max)
{
	double	up_right;
	double	up_left;
	double	left_height;

	up_left = ((1 / sqrt(6)) * (a->x_len - 1)) + ((1 / sqrt(6)) * 0) - ((2 / sqrt(6)) * height_max);
	up_right = ((1 / sqrt(6)) * (a->x_len - 1)) + ((1 / sqrt(6)) * a->y_len - 1) - ((2 / sqrt(6)) * height_max);
	left_height = up_left;
	if (up_left < up_right)
		left_height = up_right;
	a->set.zoom = 400 / (left_height);
	if (left_height < 0)
		a->set.zoom = (left_height) / 400;
	if ((a->x_len > 100  && a->x_len <= 220) || (a->y_len > 100  && a->y_len <= 220))
	{
		a->set.zoom = 4.5;
		a->set.shift_x = 0;
	}
	if ((a->x_len > 220) || (a->y_len > 220))
	{
		a->set.zoom = 1.5;
		a->set.shift_x = 0;
	}
	if (left_height < 0)
		a->set.zoom = 20;
	printf("left_height = %f || a.set.zoom = %f ||  height_max = %d || up_left = %f || up_right= %f\n", left_height, a->set.zoom, height_max,up_left, up_right);
	return ;
}

void	set_default(t_array *a, int argc, char **argv)
{
	double height_max;

	height_max = a->height;
	if (argc == 4)
		a->height = ft_atoi_fdf(argv[3]);
	else if (argc == 2)
		a->height = 0;
	if (a->height != 0 && a->height > height_max && a->height * a->y_len < 800)
		height_max = a->height;
	a->set.shift_x = 100;
	a->set.shift_y = 500;
	set_zoom(a, height_max);
	return ;
}