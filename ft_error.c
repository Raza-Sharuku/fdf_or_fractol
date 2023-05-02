/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 12:37:40 by sraza             #+#    #+#             */
/*   Updated: 2023/05/02 11:07:57 by razasharuku      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fdf.h"

int	argc_error(int argc)
{
	if (argc == 2 || argc == 4)
		return (0);
	else 
	{
		write(2, "Usage : ./fdf <filename> [ case_size z_size ]\n", 46);
		exit(0); 
	}
}

// int	argv_error(char *argv[])
// {
// 	int	i;

// 	i = 1;
// 	while (argv[i])
// 	{

// 	}
// }

// void	ft_arg_error(int argc, char *argv[])
void	ft_arg_error(int argc)
{
	argc_error(argc);
	// argv_error(argv);
}