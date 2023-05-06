/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:37:40 by sraza             #+#    #+#             */
/*   Updated: 2023/05/06 17:45:35 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	count_lens(char **str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_map_ok(int fd, t_array *a, int next_len)
{
	char	**splited;
	char	*str;

	a->y_len = 1;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		splited = ft_split(str, ' ');
		next_len = count_lens(splited);
		ft_free_fdf(splited);
		free(str);
		a->y_len++;
		if (a->x_len != next_len)
		{
			ft_putstr_fd("Found wrong line length. Exiting.\n", 2);
			exit(1);
		}
	}
	return (a->y_len);
}

void	is_map_square(int fd, t_array *a)
{
	int		next_len;
	char	*str;
	char	**splited;

	next_len = 0;
	str = get_next_line(fd);
	if (str == NULL)
	{
		ft_putstr_fd("No data found.\n", 2);
		exit(1);
	}
	splited = ft_split(str, ' ');
	a->x_len = count_lens(splited);
	ft_free_fdf(splited);
	free(str);
	a->y_len = is_map_ok(fd, a, next_len);
	return ;
}

void	is_file_exit(char *path, t_array *a)
{
	int	fd;

	errno = 0;
	fd = open(path, O_RDONLY);
	if (errno > 0)
	{
		ft_putstr_fd("No file ", 2);
		ft_putstr_fd(path, 2);
		write(2, "\n", 1);
		exit(1);
	}
	is_map_square(fd, a);
	close(fd);
	return ;
}

void	ft_arg_error(int argc, char *argv[], t_array *a)
{
	if (!(argc == 2 || argc == 4))
	{
		write(2, "Usage : ./fdf <filename> [ case_size z_size ]\n", 46);
		exit(1);
	}
	is_file_exit(argv[1], a);
	return ;
}
