NAME	=	libftprintf.a

SRC	=	ft_printf.c \
		ft_types.c \
		libft.c

OBJ	=	$(SRC:.c=.o)

CC	=	clang
CFLAGS	=	-Wall -Wextra -Werror

all:		$(NAME)

.c.o:
		$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
		ar cr $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all, clean, fclean, re
