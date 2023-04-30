/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:05:28 by razasharuku       #+#    #+#             */
/*   Updated: 2023/04/30 14:56:16 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "fdf.h"

int	main(int argc, char *argv[])
{
	char *s;
	int i;
	if (argc != 2 && argc != 4)
	{
		s = strerror(2);
		ft_printf("%s\n", s);
	}
	i = ft_printf("%s\n", argv[1]);
	if (i != 0)
		return (0);

	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "NAKANO YOUSUKE!");
	i = mlx_string_put(mlx, mlx_win, 10, 10, 0xFFFFFF, "RAZA Sharuku Youseke!");
	i = mlx_get_color_value(mlx, 0xFFFFF0);
	mlx_loop(mlx);
}