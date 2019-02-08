NAME = push_swap

SRCS = srcs/push_swap.c srcs/cdm_reverse_rotate.c	srcs/cmd_swap_push.c \
	srcs/cmd_rotate.c srcs/ps_create_struct.c srcs/ps_atoi.c

OBJ = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror 

LIBFT = ./libft/libft.a
INC = -I ./includes
LIBLINK = -L ./libft -lft
LIBINC = -I ./libft/includes

all: $(NAME) 

%.o:%.c
	@$(CC) $(CFLAGS) $(LIBINC) $(INC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft
	@echo "OK!"

$(NAME): libft $(OBJ)
	@echo "Compiling push_swap..."
	@$(CC) $(LIBLINK) -o $(NAME) $(OBJ)
	@echo "OK!"

rmlib:
	@echo "Deleting libft object files and libft.a..."
	@make fclean -C ./libft
	@echo "OK!"

clean: rmlib
	@echo "Deleting push_swap object files..."
	@rm -rf $(OBJ)
	@echo "OK!"

fclean: clean
	@echo "Deleting push_swap..."
	@rm -rf $(NAME)
	@echo "OK!"

re: fclean all