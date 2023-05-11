/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sraza <sraza@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:33:03 by sraza             #+#    #+#             */
/*   Updated: 2023/05/11 17:58:50 by sraza            ###   ########.fr       */
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
# include <math.h>

// structs use in fdf
typedef struct s_array
{
	int		***array;
	double	x_len;
	double	y_len;
	double	height;
	void	*mlx_ptr;
	void	*win;
	double 	zoom;
	double 	color;
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
// draw.c
void				draw_window(t_array *a);
void	bresenham(double x, double y, double x1, double y1, t_array *a);
void				draw_win(t_array *a);


#endif
