/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:37:40 by sraza             #+#    #+#             */
/*   Updated: 2023/05/02 21:10:26 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

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


void	is_file_exit(char *path)
{
	int fd;
	fd = open(path, O_RDONLY);
	if (errno != 0)
	{
		ft_putstr_fd("No file ", 2);
		ft_putstr_fd(path, 2);
		write(2, "\n", 1);
		exit(1); 		
	}	
	close(fd);
	return ;
}

void	ft_arg_error(int argc, char *argv[])
{
	argc_error(argc);
	is_file_exit(argv[1]);
	return ;
}