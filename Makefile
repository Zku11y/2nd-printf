SRC = ft_printf/ft_printf.c libft_src/ft_strlen.c \
	ft_printf/handle_print.c libft_src/ft_putnbr_fd.c ft_printf/nbr_size.c \
	ft_printf/handle_hex.c ft_printf/putnbr.c libft_src/ft_strlcpy.c \
	libft_src/ft_putstr_fd.c ft_printf/handle_dec.c \
	libft_src/ft_strchr.c

BSRC = ft_printf_bonus/ft_printf_bonus.c libft_src/ft_strlen.c \
	ft_printf_bonus/handle_print_bonus.c libft_src/ft_putnbr_fd.c\
	ft_printf_bonus/nbr_size_bonus.c ft_printf_bonus/handle_hex_bonus.c\
	ft_printf_bonus/putnbr_bonus.c libft_src/ft_strlcpy.c \
	libft_src/ft_putstr_fd.c ft_printf_bonus/handle_dec_bonus.c \
	libft_src/ft_strchr.c

NAME = libftprintf.a
HEADER = ft_printf/ft_printf.h
BHEADER = ft_printf_bonus/ft_printf_bonus.h
OBJS = $(SRC:.c=.o);
BOBJS = $(BSRC:.c=.o);
CC = cc
FLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

ft_printf/%.o: ft_printf/%.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

ft_printf_bonus/%.o: ft_printf_bonus/%.c $(BHEADER)
	$(CC) $(FLAGS) -c $< -o $@

bonus: $(BOBJS)
	ar rcs $(NAME) $(BOBJS)

clean:
	rm -f */*.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean
