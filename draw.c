/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:32:34 by sraza             #+#    #+#             */
/*   Updated: 2023/05/16 21:27:37 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
#include"./minilibx-linux/mlx.h"

/*26-27 rotating each value to 90° -> calculate the isometric value */
void	isometric(double *x, double *y, t_array *a)
{
	double	i;
	double	j;
	int		z;

	i = *x;
	j = *y;
	z = a->array[(int)j][(int)i][0];
	*x= i * cos(-1.5708) - j * sin(-1.5708);
	*y= i * sin(-1.5708) + j * cos(-1.5708);
	i = *x;
	j = *y;
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
	*x = *x * a->zoom + a->shift_x;
	*y = *y * a->zoom + a->shift_y;
	*x1 = *x1 * a->zoom + a->shift_x;
	*y1 = *y1 * a->zoom + a->shift_y;
	return ;
}

void put_pixel_in_img(char **img_addr,t_image *img, int x, int y, int color)
{
	if (img->endian == 0 && x > 0 && x < (img->line_size / 4) && y > 0 && y < 1000)
	{
		(*img_addr)[x * 4 + y * img->line_size + 0] = color & 0xff;
		(*img_addr)[x * 4 + y * img->line_size + 1] = (color >> 8) & 0xff;
		(*img_addr)[x * 4 + y * img->line_size + 2] = (color >> 16) & 0xff;
		(*img_addr)[x * 4 + y * img->line_size + 3] = (color >> 24);
	}
}

void set_img_value(double x, double y, double x1, double y1, t_image *img)
{
	img->dx = x1 - x;
	img->dy = y1 - y;
	img->Max = Max_val(img->dx, img->dy);
	img->dx /= img->Max;
	img->dy /= img->Max;
	return ;
}

void	bresenham(double x, double y, double x1, double y1, t_array *a)
{
	t_image	img;

// color----------------------------
	a->color = a->array[(int)y][(int)x][1];
// 3D----------------------------
	isometric(&x, &y, a);
	isometric(&x1, &y1, a);
// zoom_shift----------------------------
	zoom_shift(&x, &y, &x1, &y1, a);

	set_img_value(x, y, x1, y1, &img);
	char *get_addr;
	get_addr = mlx_get_data_addr(a->img_ptr, &img.bit_pr_pxl, &img.line_size, &img.endian);
	while ((int)(x - x1) || (int)(y - y1))
	{
		put_pixel_in_img(&get_addr, &img, x, y, a->color);
		x += img.dx;
		y += img.dy;
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

