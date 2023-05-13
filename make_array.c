/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:56:54 by sraza             #+#    #+#             */
/*   Updated: 2023/05/13 17:05:26 by razasharuku      ###   ########.fr       */
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

void	make_int_list(char ***str, t_array *a)
{
	char	**color_s;
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
			color_s = ft_split(str[i][j], ',');
			a->array[i][j][0] = ft_atoi_fdf(str[i][j]);
			if (color_s[1] == NULL)
				a->array[i][j][1] = to_demical("0xffffff");
			if (color_s[1] != NULL)
				a->array[i][j][1] = to_demical(color_s[1]);
			ft_free_fdf(color_s);
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
