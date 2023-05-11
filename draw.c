/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:32:34 by sraza             #+#    #+#             */
/*   Updated: 2023/05/11 20:59:29 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
#include"./minilibx-linux/mlx.h"

// void draw_window(t_array *a)
// {
// 	double i;
// 	double j;

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

// void draw_window(t_array *a)
// {
// 	double i;
// 	double j;
// 	i = 0;
// 	while (i < 500)
// 	{
// 		j = 0;
// 		while (j < 500)
// 		{
// 			mlx_pixel_put(a->mlx_ptr, a->win, i, j, 0xFFFFFF);
// 			j = j + 10;
// 		}
// 		i++;
// 	}
// 	mlx_loop(a->mlx_ptr);
// 	return ;
// }


void	isometric(double *x, double *y, double *z)
{
    double i = *x;
    double j = *y;
    double k = *z;

	*x = ((1 / sqrt(2)) * i) - ((1 / sqrt(2)) * j);
	*y = ((1 / sqrt(6)) * i) + ((1 / sqrt(6)) * j) + ((2 / sqrt(6)) * k);
	*z = ((-1 / sqrt(3)) * i) - ((1 / sqrt(3)) * j) + ((1 / sqrt(3)) * k);
}

void	bresenham(double x, double y, double x1, double y1, t_array *a)
{
	double	Max;
	double	x_step;
	double	y_step;
	double	z;
	double	z1;
	
	z = a->array[(int)y][(int)x][0];
	z1 = a->array[(int)y1][(int)x1][0];
// color----------------------------
	if (z != 0)
		a->color = a->array[(int)y][(int)x][1];
	if (z1 != 0)
		a->color = a->array[(int)y1][(int)x1][1];
	else
		a->color = 0xffffff;
// zoom----------------------------
	x *= a->zoom;
	y *= a->zoom;
	x1 *= a->zoom;
	y1 *= a->zoom;
// 3D----------------------------
	// isometric(&x, &y, &z);
	// isometric(&x1, &y1, &z1);
// shift
	x += 150;
	y += 150;
	x1 += 150;
	y1 += 150;

	x_step = x1 - x;
	y_step = y1 - y;
	if (fabs(x_step)  > fabs(y_step))
		Max = x_step;
	if (fabs(x_step) < fabs(y_step))
		Max = y_step;
	x_step /= Max;
	y_step /= Max;
	while ((x - x1) || (y - y1) )
	{
		mlx_pixel_put(a->mlx_ptr, a->win, x, y, a->color);
		x += x_step;
		y += y_step;
		if (x > 900 || y > 900 || x < 0 || y < 0)
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
