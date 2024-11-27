SRC = ft_printf/ft_printf.c ft_printf/ft_strlen.c \
	ft_printf/ft_handle_print.c ft_printf/ft_putnbr_fd.c\
	ft_printf/ft_nbr_size.c ft_printf/ft_handle_hex.c\
	ft_printf/ft_putnbr.c ft_printf/ft_strlcpy.c \
	ft_printf/ft_putstr_fd.c ft_printf/ft_handle_dec.c \
	ft_printf/ft_strchr.c

BSRC = ft_printf_bonus/ft_printf_bonus.c ft_printf_bonus/ft_strlen.c \
	ft_printf_bonus/ft_handle_print_bonus.c ft_printf_bonus/ft_putnbr_fd.c\
	ft_printf_bonus/ft_nbr_size_bonus.c ft_printf_bonus/ft_handle_hex_bonus.c\
	ft_printf_bonus/ft_putnbr_bonus.c ft_printf_bonus/ft_strlcpy.c \
	ft_printf_bonus/ft_putstr_fd.c ft_printf_bonus/ft_handle_dec_bonus.c \
	ft_printf_bonus/ft_strchr.c

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

m:
	@cc -Wall -Wextra -Werror main.c libftprintf.a
	@./a.out

mn:
	@cc main.c libftprintf.a
	@./a.out

clean:
	rm -f $(OBJS)
	rm -f $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean
