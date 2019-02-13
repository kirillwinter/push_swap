NAMEPS = push_swap
NAMEC = checker

SRCS = srcs/cdm_reverse_rotate.c srcs/cmd_swap.c  srcs/cmd_push.c \
	srcs/cmd_rotate.c srcs/ps_create_struct.c srcs/valid_out.c

SRCSPS = srcs/push_swap.c srcs/stack_a.c srcs/stack_b.c srcs/first_sort.c

SRCSC = srcs/checker.c

OBJ = $(SRCS:.c=.o)
OBJPS = $(SRCSPS:.c=.o)
OBJC = $(SRCSC:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror 

LIBFT = ./libft/libft.a
INC = -I ./includes
LIBLINK = -L ./libft -lft
LIBINC = -I ./libft/includes

all: $(NAMEPS) $(NAMEC)

%.o:%.c
	@$(CC) $(CFLAGS) $(LIBINC) $(INC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft
	@echo "OK!"

$(NAMEPS): libft $(OBJPS) $(OBJ)
	@echo "Compiling push_swap..."
	@$(CC) $(LIBLINK) -o $(NAMEPS) $(OBJPS) $(OBJ)
	@echo "OK!"

$(NAMEC): libft $(OBJC) $(OBJ)
	@echo "Compiling checker..."
	@$(CC) $(LIBLINK) -o $(NAMEC) $(OBJC) $(OBJ)
	@echo "OK!"

rmlib:
	@echo "Deleting libft object files and libft.a..."
	@make fclean -C ./libft
	@echo "OK!"

clean: rmlib
	@echo "Deleting push_swap object files..."
	@rm -rf $(OBJC) $(OBJPS) $(OBJ) 
	@echo "OK!"

fclean: clean
	@echo "Deleting push_swap..."
	@rm -rf $(NAMEPS) $(NAMEC)
	@echo "OK!"

re: fclean all