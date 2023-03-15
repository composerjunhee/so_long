# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junheeki <junheeki@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/22 11:55:04 by junheeki          #+#    #+#              #
#    Updated: 2023/02/27 14:56:10 by junheeki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = \
ft_isalpha.c	ft_isdigit.c	ft_isalnum.c	ft_isascii.c	ft_isprint.c	ft_strlen.c		\
ft_memset.c		ft_bzero.c		ft_memcpy.c		ft_memmove.c	ft_strlcpy.c	ft_strlcat.c	\
ft_toupper.c	ft_tolower.c	ft_strchr.c		ft_strrchr.c	ft_strncmp.c	ft_memchr.c		\
ft_memcmp.c		ft_strnstr.c	ft_atoi.c		ft_calloc.c		ft_strdup.c		ft_substr.c		\
ft_strjoin.c	ft_strtrim.c	ft_split.c		ft_itoa.c		ft_strmapi.c	ft_striteri.c	\
ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	\
get_next_line.c	\
ft_print_hex.c	ft_print_ptr.c	ft_print_unsigned.c	ft_printf_utils.c	ft_printf.c \
ft_printnbr.c	ft_printpercent.c	ft_printstr.c \


SRCS_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c\
ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
OBJ = $(SRC:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	cc -Wall -Wextra -Werror -c $(SRC)
	ar rcs $(NAME) $(OBJ)

bonus: $(SRCS_BONUS:.c=.o)

$(SRCS_BONUS:.c=.o): $(SRCS_BONUS)
	cc -Wall -Wextra -Werror -c $(SRCS_BONUS)
	ar rus $(NAME) $(OBJS_BONUS)

clean:
	rm -f $(OBJ) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
