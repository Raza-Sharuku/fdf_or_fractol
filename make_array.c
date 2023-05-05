/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:56:54 by sraza             #+#    #+#             */
/*   Updated: 2023/05/05 20:47:20 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

char ***splited_map(int fd, t_array *a)
{
	char	**str;
	char	***str2;
	int		i;

	i = 0;
	str = (char **)malloc(sizeof(char *) * (a->y_len) + 1);
	str2 = (char ***)malloc(sizeof(char **) * (a->y_len) + 1);
	while (i < a->y_len)
	{
		str[i] = get_next_line(fd);
		str2[i] = ft_split(str[i], ' ');
		i++;
	}
	str[i] = NULL;
	ft_free_fdf(str);
	return (str2);
}

void	make_int_list(char ***str, t_array *a)
{
	char	**color_s;
	int		i;
	int		j;

	a->array = malloc(sizeof(int *) * a->y_len);
	i = 0;
	while (i < a->y_len)
	{
		a->array[i] = malloc(sizeof(int ) * a->x_len);
		j = 0;
		while (str[i][j])
		{
			color_s = ft_split(str[i][j], ',');
			if (color_s[1] == NULL)
				a->array[i][j].height = ft_atoi_fdf(str[i][j]);
			if (color_s[1] != NULL)
			{
				a->array[i][j].height = ft_atoi_fdf(color_s[0]);
				printf("color_s[1] = %s\n", color_s[1]);
				a->array[i][j].color = ft_atoi_fdf(color_s[1]);
			}
			if (a->array[i][j].height < 10)
			{
				printf("%i  ", a->array[i][j].height);
				printf("%i  ", a->array[i][j].color);
			}
			else if (a->array[i][j].height > 9)
			{
				printf("%i ", a->array[i][j].height);
				printf("%i  ", a->array[i][j].color);
			}
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n========================================     ==========================================\n");
	return ;
}

/*
文字列ベースの情報を３次元配列として確保することできた、
次にInt型への変換として高さと色の情報も付与した状態で確保することができた、、
次にやることは文字列の３次元配列のFreeそしてここまでのリークを調べること。

*/
void *make_array(char *argv[], t_array *a)
{
	char	***str;
	int		i;
	int		fd;
	// int 	j;
	
	i = 0;
	fd = open(argv[1], O_RDONLY);
	str = splited_map(fd, a);
	close(fd);
	make_int_list(str, a);

	return (a);
}