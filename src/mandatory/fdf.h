/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: razasharuku <razasharuku@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 13:33:03 by sraza             #+#    #+#             */
/*   Updated: 2023/05/23 15:43:12 by razasharuku      ###   ########.fr       */
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
# include"../../libs/ft_printf/ft_printf.h"
# include"../../libs/libft/libft.h"
#include "../../minilibx-linux/mlx.h"
# include <math.h>

// structs use in fdf
typedef struct s_map
{
	double	x;	
	double	x1;	
	double	y;
	double	y1;
}		t_map;
typedef struct s_balance
{
	double	zoom;
	int		shift_y;
	int		shift_x;
	double	x_a;
	double	y_a;
	double	z_a;
}		t_balance;
typedef struct s_array
{
	int					***array;
	double				x_len;
	double				y_len;
	double				height;
	void				*mlx_ptr;
	void				*win;
	void				*img_ptr;
	int					color;
	struct s_balance	set;
}			t_array;
typedef struct s_image
{
	int		color;
	double	max;
	double	dx;
	double	dy;
	int		bit_pr_pxl;
	int		line_size;
	int		endian;
}			t_image;
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
int					to_demical(char *str);
// draw.c
void				draw_win(t_array *a);
void				pxl_in_img(char **i_adr, t_image *img, int x, int y);
void				zoom_shift(double *x, double *y, t_array *a);
double				max_val(double a, double b);
void				isometric(double *x, double *y, t_array *a);
// set_default.c
void				set_default(t_array *a, int argc, char **argv);
// handle_window.c
int					handle_win(int key, t_array *a);
int					handle_mouse(int button, int x, int y, t_array *a);
// rotate_xyz.c
void	rotate_z(double *x, double *y, t_array *a);
void	rotate_y(double *x, double *z, t_array *a);
void	rotate_x(double *y, double *z, t_array *a);


#endif
