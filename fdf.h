/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:33:03 by sraza             #+#    #+#             */
/*   Updated: 2023/05/03 16:59:26 by razasharuku      ###   ########.fr       */
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

void				ft_arg_error(int argc, char *argv[]);
void				is_file_exit(char *path);
void				argc_error(int argc);
void				is_map_square(int fd);

#endif
