/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:56:54 by sraza             #+#    #+#             */
/*   Updated: 2023/05/18 20:41:25 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

char	***splited_map(int fd, t_array *a)
{
	char	**str;
	char	***str2;
	int		i;

	i = 0;
	str2 = three_malloc(a);
	str = two_malloc(str2, a->y_len, i);
	while (i < a->y_len)
	{
		str[i] = get_next_line(fd);
		str2[i] = ft_split(str[i], ' ');
		i++;
	}
	str[i] = NULL;
	str2[i] = NULL;
	ft_free_fdf(str);
	return (str2);
}

void	set_height_color(t_array *a, int i, int j, char *str)
{
	char	**color;
	double	height_max;

	height_max = 0;
	color = ft_split(str, ',');
	a->array[i][j][0] = ft_atoi_fdf(str);
	if (a->height < a->array[i][j][0])
		a->height = a->array[i][j][0];
	if (color[1] == NULL)
		a->array[i][j][1] = to_demical("0xffffff");
	if (color[1] != NULL)
		a->array[i][j][1] = to_demical(color[1]);
	ft_free_fdf(color);
	return ;
}

void	make_int_list(char ***str, t_array *a)
{
	int		i;
	int		j;

	a->array = (int ***)malloc(sizeof(int **) * a->y_len);
	i = 0;
	while (i < (int)a->y_len)
	{
		a->array[i] = (int **)malloc(sizeof(int *) * a->x_len);
		j = 0;
		while (j < (int)a->x_len)
		{
			a->array[i][j] = (int *)malloc(sizeof(int) * 2);
			set_height_color(a, i, j, str[i][j]);
			j++;
		}
		i++;
	}
	return ;
}

void	*make_array(char *argv[], t_array *a)
{
	char	***str;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	str = splited_map(fd, a);
	close(fd);
	make_int_list(str, a);
	str = ft_free_three(str);
	return (a->array);
}
