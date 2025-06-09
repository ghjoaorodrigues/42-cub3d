NAME = cub3d

SRCS = main.c keyhook.c textures.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX = -L$(MLX_DIR) -lmlx -lm -L/usr/lib -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) $(OBJS) -o $(NAME) $(MLX)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all