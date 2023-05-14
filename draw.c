/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:32:34 by sraza             #+#    #+#             */
/*   Updated: 2023/05/14 20:46:51 by sraza            ###   ########.fr       */
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

void	zoom_shift(double *x, double *y, double *x1, double *y1, t_array *a)
{
	*x = *x * a->zoom + a->shift;
	*y = *y * a->zoom + a->shift;
	*x1 = *x1 * a->zoom + a->shift;
	*y1 = *y1 * a->zoom + a->shift;
	return ;
}

void put_pixel_in_img(char **img_addr,int size_line, int x, int y, int color)
{
	if (x > 0 && x < (size_line / 4) && y > 0 && y < 2000)
	{		
		(*img_addr)[x * 4 + y * size_line + 0] = color & 0xff;
		(*img_addr)[x * 4 + y * size_line + 1] = (color >> 8) & 0xff;
		(*img_addr)[x * 4 + y * size_line + 2] = (color >> 16) & 0xff;
		(*img_addr)[x * 4 + y * size_line + 3] = 0x00;
	}
}

void	bresenham(double x, double y, double x1, double y1, t_array *a)
{
	double	Max;
	double	dx;
	double	dy;
	int bit_per_pixel;
	int line_size;
	int endian;

// color----------------------------
	a->color = a->array[(int)y][(int)x][1];
// 3D----------------------------
	isometric(&x, &y, a);
	isometric(&x1, &y1, a);
// zoom_shift----------------------------
	zoom_shift(&x, &y, &x1, &y1, a);

	dx = x1 - x;
	dy = y1 - y;

	Max = Max_val(dx, dy);
	dx /= Max;
	dy /= Max;
	char *get_addr;
	get_addr = mlx_get_data_addr(a->img_ptr, &bit_per_pixel, &line_size, &endian);
	while ((int)(x - x1) || (int)(y - y1))
	{
		put_pixel_in_img(&get_addr,line_size, fabs(x), fabs(y), a->color); 
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
	printf("dx : dy\n");
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


