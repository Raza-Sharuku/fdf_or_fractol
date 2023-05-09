/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:33:03 by sraza             #+#    #+#             */
/*   Updated: 2023/05/09 17:40:59 by razasharuku      ###   ########.fr       */
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

// structs use in fdf
typedef struct s_array
{
	int	***array;
	int	x_len;
	int	y_len;
	int	height;
	int expansion;
}			t_array;
// ft_error.c
void				ft_arg_error(int argc, char *argv[], t_array *a);
void				is_file_exit(char *path, t_array *a);
void				is_map_square(int fd, t_array *a);
int					count_lens(char **str);
int					is_map_ok(int fd, t_array *a, int next_len);
// make_array.c
void				*make_array(char *argv[], t_array *a);
void				make_int_list(char ***str, t_array *a);
char				***splited_map(int fd, t_array *a);
// ft_atoi_4_fdf.c
long				ft_atoi_fdf(const char *str);
// malloc_utils.c
void				*ft_free_three(char ***str);
void				*ft_free_fdf(char **result);
char				**two_malloc(char ***str2, int len, int i);
char				***three_malloc(t_array *a);
// malloc_utils2.c
char				*int_malloc(t_array *a, int i, int len);
void				ft_free_int2(t_array *a);
// atoi_hexa_demical.c
int	to_demical(char *str);

#endif
