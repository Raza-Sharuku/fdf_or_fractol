/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:05:28 by razasharuku       #+#    #+#             */
/*   Updated: 2023/05/05 17:44:43 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minilibx-linux/mlx.h"
#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_array a;

	ft_arg_error(argc, argv, &a);
	printf("a.x_len = %d || a.y_len = %d\n", a.x_len, a.y_len);
	
	printf("Nothing is wrong with arguments\n");
	a.array = make_array(argv, &a);
	return (0);
}