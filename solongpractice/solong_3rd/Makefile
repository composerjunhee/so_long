NAME := solong
SRCS := solong.c image.c keycode.c map.c util.c
LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a
FLAGS := -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(LIBFT)
	cc $(FLAGS) $(SRCS) $(LIBFT) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	make bonus -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re libft
