CC = cc
NAME = $(NAME)
NAME	=	fdf
CFLAGS	=	-Wall -Wextra -Werror 
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

OBJS = ${SRCS:%.c=%.o}

all:	$(NAME)

LIBFT		=	./libs/libft/libft.a
FT_PRINTF	=	./libs/ft_printf/libftprintf.a
MINILIBX	=	./minilibx-linux/libmlx_Darwin.a ./minilibx-linux/libmlx.a

$(NAME):	$(OBJS)
	$(MAKE) -C ./libs/libft
	$(MAKE) -C ./libs/ft_printf
	$(MAKE) -C ./minilibx-linux
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(LIBFT) $(FT_PRINTF) $(MINILIBX) $(SRCS) -o $(NAME)

clean:
	$(MAKE) -C ./libs/libft clean
	$(MAKE) -C ./libs/ft_printf clean
	$(MAKE) -C ./minilibx-linux clean
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(LIBFT)
	$(RM) $(FT_PRINTF)
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re