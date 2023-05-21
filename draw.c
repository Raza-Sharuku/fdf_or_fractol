/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:32:34 by sraza             #+#    #+#             */
/*   Updated: 2023/05/21 15:30:27 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
#include"./minilibx-linux/mlx.h"

void	set_img_value(t_map *map, t_image *img)
{
	img->dx = map->x1 - map->x;
	img->dy = map->y1 - map->y;
	img->max = max_val(img->dx, img->dy);
	img->dx /= img->max;
	img->dy /= img->max;
	return ;
}

void	bresenham(t_map *m, t_array *a)
{
	t_image	img;
	char	*get_addr;

	a->color = a->array[(int)m->y][(int)m->x][1];
	isometric(&m->x, &m->y, a);
	isometric(&m->x1, &m->y1, a);
	zoom_shift(&m->x, &m->y, a);
	zoom_shift(&m->x1, &m->y1, a);
	set_img_value(m, &img);
	get_addr = mlx_get_data_addr(a->img_ptr,
			&img.bit_pr_pxl, &img.line_size, &img.endian);
	img.color = a->color;
	while ((int)(m->x - m->x1) || (int)(m->y - m->y1))
	{
		pxl_in_img(&get_addr, &img, m->x, m->y);
		m->x += img.dx;
		m->y += img.dy;
	}
	return ;
}

void	draw_win2(int x, int y, t_array *a)
{
	t_map	map;

	map.x = x;
	map.y = y;
	map.x1 = x + 1;
	map.y1 = y;
	if (x < a->x_len - 1)
		bresenham(&map, a);
	map.x = x;
	map.y = y;
	map.x1 = x;
	map.y1 = y + 1;
	if (y < a->y_len - 1)
		bresenham(&map, a);
	return ;
}

void	draw_win(t_array *a)
{
	int	x;
	int	y;

	a->img_ptr = mlx_new_image(a->mlx_ptr, 1000, 1000);
	y = 0;
	while (y < a->y_len)
	{
		x = 0;
		while (x < a->x_len)
		{
			draw_win2(x, y, a);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(a->mlx_ptr, a->win, a->img_ptr, 0, 0);
	return ;
}
