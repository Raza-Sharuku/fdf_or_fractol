/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:33:03 by sraza             #+#    #+#             */
/*   Updated: 2023/05/03 20:46:06 by sraza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include"./libs/ft_printf/ft_printf.h"
# include"./libs/libft/libft.h"

typedef struct s_array
{
	int	*array;
	int	x_len;
	int	y_len;
	int	height;
	int expansion;
}			t_array;
void				ft_arg_error(int argc, char *argv[], t_array *a);
void				is_file_exit(char *path, t_array *a);
void				argc_error(int argc);
void				is_map_square(int fd, t_array *a);
void				*make_array(char *argv[], t_array *a);


#endif
