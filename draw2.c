/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:55:01 by sraza             #+#    #+#             */
/*   Updated: 2023/05/19 16:00:55 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
#include"./minilibx-linux/mlx.h"

void	isometric(double *x, double *y, t_array *a)
{
	double	i;
	double	j;
	int		z;

	i = *x;
	j = *y;
	z = a->array[(int)j][(int)i][0];
	if (z != 0 && a->height != 0)
		z = a->height;
	*x = i * cos(-1.5708) - j * sin(-1.5708);
	*y = i * sin(-1.5708) + j * cos(-1.5708);
	i = *x;
	j = *y;
	*x = ((1 / sqrt(2)) * i) - ((1 / sqrt(2)) * j);
	*y = ((1 / sqrt(6)) * i) + ((1 / sqrt(6)) * j) - ((2 / sqrt(6)) * z);
	return ;
}

double	max_val(double a, double b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a > b)
		return (a);
	return (b);
}

void	zoom_shift(double *x, double *y, t_array *a)
{
	*x = *x * a->set.zoom + a->set.shift_x;
	*y = *y * a->set.zoom + a->set.shift_y;
	return ;
}

void	put_pixel_in_img(char **i_adr, t_image *img, int x, int y)
{
	if (img->endian == 0 && x > 0 && x
		< (img->line_size / 4) && y > 0 && y < 1000)
	{
		(*i_adr)[x * 4 + y * img->line_size + 0] = img->color & 0xff;
		(*i_adr)[x * 4 + y * img->line_size + 1] = (img->color >> 8) & 0xff;
		(*i_adr)[x * 4 + y * img->line_size + 2] = (img->color >> 16) & 0xff;
		(*i_adr)[x * 4 + y * img->line_size + 3] = (img->color >> 24);
	}
	if (img->endian == 1 && x > 0 && x
		< (img->line_size / 4) && y > 0 && y < 1000)
	{
		(*i_adr)[x * 4 + y * img->line_size + 3] = img->color & 0xff;
		(*i_adr)[x * 4 + y * img->line_size + 2] = (img->color >> 8) & 0xff;
		(*i_adr)[x * 4 + y * img->line_size + 1] = (img->color >> 16) & 0xff;
		(*i_adr)[x * 4 + y * img->line_size + 0] = (img->color >> 24);
	}
}