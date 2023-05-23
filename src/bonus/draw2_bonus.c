/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 19:55:01 by sraza             #+#    #+#             */
/*   Updated: 2023/05/23 17:23:34 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	cabinet(double *x, double *y, t_array *a)
{
	double	i;
	double	j;
	double	z;

	i = *x;
	j = *y;
	z = a->array[(int)j][(int)i][0];
	if (z != 0 && a->height != 0)
		z = a->height;
	rotate_z(x, y, a);
	rotate_y(x, &z, a);
	rotate_x(y, &z, a);
	i = *x;
	j = *y;
	*x = i + (-cos(0.5)) * z;
	*y = j + (sin(0.5)) * z;
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

void	pxl_in_img(char **i_adr, t_image *img, int x, int y)
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
