/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:32:34 by sraza             #+#    #+#             */
/*   Updated: 2023/05/10 21:11:32 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
#include"./minilibx-linux/mlx.h"

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
// 			mlx_pixel_put(a->mlx_ptr, a->win, i, j, 0xFFFFFF);
// 			j = j + 10;
// 		}
// 		i++;
// 	}
// 	mlx_loop(a->mlx_ptr);
// 	return ;
// }
float	ft_abs(float i)
{
	if (i < 0)
		i = i * -1;
	return (i);
}

void	bresenham(float x, float y, float x1, float y1, t_array *a)
{
	int	Max;
	float	x_step;
	float	y_step;
	int z;
	int z1;
	
	z = a->array[(int)y][(int)x][0];
	z1 = a->array[(int)y1][(int)x1][0];

	x *= a->zoom;
	x1 *= a->zoom;
	y *= a->zoom;
	y1 *= a->zoom;

	x_step = ft_abs(x1) - ft_abs(x);
	y_step = ft_abs(y1) - ft_abs(y);

	if (z != 0)
		a->color = 0x443333;
	else
		a->color = 0xffffff;

	if (x_step  > y_step)
		Max = x_step;
	else
		Max = y_step;
	x_step /= Max;
	y_step /= Max;
	while ((int)(x - x1) ||(int)(y - y1) )
	{
		mlx_pixel_put(a->mlx_ptr, a->win, x, y, a->color);
		x += x_step;
		y += y_step;
	}
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