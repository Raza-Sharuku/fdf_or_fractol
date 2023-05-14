/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:32:34 by sraza             #+#    #+#             */
/*   Updated: 2023/05/14 17:30:15 by razasharuku      ###   ########.fr       */
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
	z = z = a->array[(int)y][(int)x][0];
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

void	zoom_shift(double x, double y, double x1, double y1, t_array *a)
{
	x = x * a->zoom + a->shift;
	y = y * a->zoom + a->shift;
	x1 = x1 * a->zoom + a->shift;
	y1 = y1 * a->zoom + a->shift;
	return ;
}
void	bresenham(double x, double y, double x1, double y1, t_array *a)
{
	double	Max;
	double	dx;
	double	dy;
	int *pos;

// color----------------------------
	a->color = a->array[(int)y][(int)x][1];
// 3D----------------------------
	isometric(&x, &y, a);
	isometric(&x1, &y1, a);
// zoom_shift----------------------------
	zoom_shift(x, y, x1, y1, a);

	dx = x1 - x;
	dy = y1 - y;

	Max = Max_val(dx, dy);
	dx /= Max;
	dy /= Max;
	char *get_addr;
	while ((int)(x - x1) || (int)(y - y1))
	{
		get_addr = mlx_get_data_addr(a->img_ptr, a->array[(int)y][(int)x][1], );
		// a->color += (dx + dy);
		x += dx;
		y += dy;
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
	mlx_put_image_to_window(a->mlx_ptr, a->win, a->img_ptr, 0, 0);
	return ;
}


