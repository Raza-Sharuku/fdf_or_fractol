/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 19:56:54 by sraza             #+#    #+#             */
/*   Updated: 2023/05/05 20:04:17 by sraza            ###   ########.fr       */
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

int **make_int_list(char ***str, t_array *a)
{
	int	**map;
	int	i;
	int	j;

	map = (int **)malloc(sizeof(int *) * a->y_len);
	i = 0;
	while (i < a->y_len)
	{
		map[i] = (int *)malloc(sizeof(int ) * a->x_len);
		j = 0;
		while (str[i][j])
		{
			// printf("ft_atoi_fdf(str[i][j] = %i",ft_atoi(str[i][j]));
			map[i][j] = ft_atoi_fdf(str[i][j]);
			if (map[i][j] < 10)
				printf("%i  ", map[i][j]);
			else if (map[i][j] > 9)
				printf("%i ", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n========================================     ==========================================\n");
	return (map);
}

void *make_array(char *argv[], t_array *a)
{
	char	***str;
	int		**map;
	int		i;
	int		fd;
	// int 	j;
	
	i = 0;
	fd = open(argv[1], O_RDONLY);
	str = splited_map(fd, a);
	close(fd);
	map = make_int_list(str, a);
	// while (i < a->y_len)
	// {
	// 	j = 0;
	// 	while (str[i][j])
	// 	{
	// 		if (ft_strlen(str[i][j]) == 1)
	// 			printf("@%s  ", str[i][j]);
	// 		if (ft_strlen(str[i][j]) == 2)
	// 			printf("@%s ", str[i][j]);
	// 		j++;
	// 	}
	// 	write(1,"\n",1);
	// 	i++;
	// }
	return (a);
}