/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:32:34 by sraza             #+#    #+#             */
/*   Updated: 2023/05/09 21:07:09 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
#include"./minilibx-linux/mlx.h"
// #include"./minilibx-linux/mlx_int.h"

int	main(void)
{
	void *mlx_ptr;
	void *win;

	void *mlx_init();
	mlx_ptr = mlx_init();
	win = mlx_new_window(mlx_ptr, 100, 200, "raza sharuku");
	return(0);
}