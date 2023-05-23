NAME	=	fdf
CC = cc
CFLAGS	=	-Wall -Wextra -Werror $(INC)
# -fsanitize=address -g

# ↓this for 42cluster
# MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
# ↓this for my Macbook
MLX_FLAGS	=	-L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit 

INC		=	-I./libs/libft/ -I./libs/ft_printf/ -I./minilibx-linux

SRCS	=	main.c \
			ft_error.c \
			make_array.c \
			ft_atoi_4_fdf.c \
			malloc_utils.c \
			atoi_hexa_demical.c \
			malloc_utils2.c \
			draw.c \
			draw2.c \
			set_default.c \
			handle_window.c \
			rotate_xyz.c
SRCS_PATH	= 	$(addprefix ./src/mandatory/, $(SRCS))
OBJS_PATH	=	$(SRCS_PATH:%.c=%.o)

BONUS_SRCS	=	fdf_main_bonus.c \
			ft_error_bonus.c \
			make_array_bonus.c \
			ft_atoi_4_fdf_bonus.c \
			malloc_utils_bonus.c \
			atoi_hexa_demical_bonus.c \
			malloc_utils2_bonus.c \
			draw_bonus.c \
			draw2_bonus.c \
			set_default_bonus.c \
			handle_window_bonus.c \
			rotate_xyz_bonus.c
BONUS_PATH		= 	$(addprefix ./src/bonus/, $(BONUS_SRCS))
BONUS_OBJS_PATH	=	$(BONUS_PATH:%.c=%.o)

ifdef WITH_BONUS
	OBJS_PATH = $(BONUS_OBJS_PATH)
endif

all:	$(NAME)

$(NAME):	$(OBJS_PATH)
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/ft_printf
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(OBJS_PATH) -o $(NAME)

LIBFT		=	./libs/libft/libft.a
FT_PRINTF	=	./libs/ft_printf/libftprintf.a
MINILIBX	=	./minilibx-linux/libmlx_Darwin.a ./minilibx-linux/libmlx.a

clean:
	$(MAKE) -C ./libs/libft clean
	$(MAKE) -C ./libs/ft_printf clean
	$(MAKE) -C ./minilibx-linux clean
	$(RM) $(OBJS_PATH)
	$(RM) $(BONUS_OBJS_PATH)

fclean:	clean
	$(RM) $(LIBFT)
	$(RM) $(FT_PRINTF)
	$(RM) $(NAME)

re:	fclean all

bonus:
	make WITH_BONUS=1

.PHONY:	all clean fclean re