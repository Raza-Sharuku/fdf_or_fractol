/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_xyz.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 10:55:03 by razasharuku       #+#    #+#             */
/*   Updated: 2023/05/23 10:56:33 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"
#include"./minilibx-linux/mlx.h"

void	rotate_x(double *y, double *z, t_array *a)
{
	double	j;
	double	k;

	j = *y;
	k = *z;
	*y = j * cos(a->set.x_a) - k * sin(a->set.x_a);
	*z = j * sin(a->set.x_a) + k * cos(a->set.x_a);
}

void	rotate_y(double *x, double *z, t_array *a)
{
	double	i;
	double	k;

	i = *x;
	k = *z;
	*x = i * cos(a->set.y_a) + k * sin(a->set.y_a);
	*z = -i * sin(a->set.y_a) + k * cos(a->set.y_a);
}

void	rotate_z(double *x, double *y, t_array *a)
{
	double	i;
	double	j;

	i = *x;
	j = *y;
	*x = i * cos(a->set.z_a) - j * sin(a->set.z_a);
	*y = i * sin(a->set.z_a) + j * cos(a->set.z_a);
}
