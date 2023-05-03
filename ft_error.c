/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:37:40 by sraza             #+#    #+#             */
/*   Updated: 2023/05/03 20:43:22 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

void	is_map_square(int fd, t_array *a)
{
	int		first_len;
	int		next_len;
	char	*str;

	str = get_next_line(fd);
	first_len = ft_strlen(str);
	a->y_len = 1;
	while (*str)
	{
		str = get_next_line(fd);
		if(str == NULL)
			break ;
		next_len = ft_strlen(str);
		a->y_len++;
		if(first_len != next_len)
		{
			ft_putstr_fd("Found wrong line length. Exiting.\n", 2);
			exit(1); 
		}
	}
	a->x_len = first_len;
	return ;
}

void	argc_error(int argc)
{
	if (argc == 2 || argc == 4)
		return ;
	else 
	{
		write(2, "Usage : ./fdf <filename> [ case_size z_size ]\n", 46);
		exit(1); 
	}
}

void	is_file_exit(char *path, t_array *a)
{
	int fd;
	fd = open(path, O_RDONLY);
	if (fd < 0)
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
	argc_error(argc);
	is_file_exit(argv[1], a);
	return ;
}
