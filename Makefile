CC = cc
NAME = $(NAME)
NAME	=	myfdf
CFLAGS	=	-Wall -Wextra -Werror 

# ↓this for 42cluster
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
# ↓this for my Macbook
# MLX_FLAGS	=	-L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit 

INC		=	-I./libs/libft/ -I./libs/ft_printf/ -I./minilibx-linux

SRCS	=	main.c

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