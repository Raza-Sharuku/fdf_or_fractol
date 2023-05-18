/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:32:34 by sraza             #+#    #+#             */
/*   Updated: 2023/05/18 20:52:46 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
#include"./minilibx-linux/mlx.h"

/*26-27 rotating each value to 90° -> calculate the isometric value */


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

