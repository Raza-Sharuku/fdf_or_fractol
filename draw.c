/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:32:34 by sraza             #+#    #+#             */
/*   Updated: 2023/05/13 14:15:59 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
#include"./minilibx-linux/mlx.h"

void	isometric(double *x, double *y, double z)
{
    double i = *x;
    double j = *y;
    // double k = *z;

	*x = ((1 / sqrt(2)) * i) - ((1 / sqrt(2)) * j);
	*y = ((1 / sqrt(6)) * i) + ((1 / sqrt(6)) * j) - ((2 / sqrt(6)) * z);	
}

double	Max_val(double a, double b)
{
	if (a < 0)
		a = -a;
	if (b < 0)
		b = -b;
	if (a > b)
		return (a);
	return (b);
}

void	bresenham(double x, double y, double x1, double y1, t_array *a)
{
	double	Max;
	double	dx;
	double	dy;
	double	z;
	double	z1;
	
	z = a->array[(int)y][(int)x][0];
	z1 = a->array[(int)y1][(int)x1][0];
// color----------------------------
	a->color = a->array[(int)y][(int)x][1];
// zoom----------------------------
	x *= a->zoom;
	y *= a->zoom;
	x1 *= a->zoom;
	y1 *= a->zoom;
// 3D----------------------------
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);

// shift--------------------------
	x += 200;
	y += 200;
	x1 += 200;
	y1 += 200;

	dx = x1 - x;
	dy = y1 - y;

	Max = Max_val(dx, dy);
	dx /= Max;
	dy /= Max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(a->mlx_ptr, a->win, x, y, a->color);
		x += dx;
		y += dy;
		if (x > 500 || y > 500 || x < 0 || y < 0)
			break;
	}
	return ;
}

void	draw_win(t_array *a)
{
	int	x;
	int	y;

	y = 0;
	while (y < a->y_len)
	{
		x = 0;
		while (x < a->x_len)
		{
			if (x < a->x_len - 1)
				bresenham(x, y, x + 1, y, a);
			if (y < a->y_len - 1)
				bresenham(x, y, x, y + 1, a);
			x++;
		}
		y++;
	}
}
