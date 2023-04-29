/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:05:28 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/29 16:58:24 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	int		i;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "NAKANO YOUSUKE!");
	i = mlx_string_put(mlx, mlx_win, 10, 10, 0xfff, "RAZA Sharuku Youseke!");
	i = mlx_get_color_value(mlx, 0xFFFFF0);
	mlx_loop(mlx);
}