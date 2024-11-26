CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr.c ft_putptr.c ft_putstr.c ft_putunbr.c
HEAD = ft_printf.h
OBJ = $(SRC:%.c=%.o)
RM = rm -f
AR = ar rc
NAME = libftprintf.a

all: $(NAME)

%.o: %.c $(HEAD)
	$(CC) $(CFLAGS) -c $< -o $@
	$(AR) $(NAME) $@	

$(NAME): $(OBJ)

clean:
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	$(RM) $(OBJ) $(NAME)

re: fclean all