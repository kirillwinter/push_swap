NAMEPS = push_swap
NAMEC = checker

SRCS = srcs/cmd_reverse_rotate.c srcs/cmd_swap.c  srcs/cmd_push.c \
	srcs/cmd_rotate.c srcs/ps_create_struct.c srcs/valid_out.c  srcs/ps_draw.c\
	srcs/call_cmd.c srcs/ps_visual_line.c

SRCSPS = srcs/push_swap.c srcs/stack_a.c srcs/stack_b.c srcs/first_sort.c

SRCSC = srcs/checker.c

OBJ = $(SRCS:.c=.o)
OBJPS = $(SRCSPS:.c=.o)
OBJC = $(SRCSC:.c=.o)

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror 
MLXFLAGS =  -framework OpenGL -framework AppKit

INC = -I ./includes

LIBFT = ./libft/libft.a
LIBMLX = ./minilibx_macos/libmlx.a
# MLXINC = -I ./minilibx_macos/
# LIBLINK = -L ./libft -lft
#LIBINC = -I ./libft/includes 
LIBINCS = -I ./libft/includes -I ./minilibx_macos/
LIBS = -L ./libft -lft -L ./minilibx_macos -lmlx

all: $(NAMEPS) $(NAMEC)

%.o:%.c
	@$(CC) $(CFLAGS) $(LIBINCS) $(INC) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	@echo "Compiling libft..."
	@make -C ./libft
	@echo "OK!"

$(LIBMLX):
	@echo "Compiling minilibx..."
	@make -C ./minilibx_macos
	@echo "OK!"

$(NAMEPS): libft $(LIBMLX) $(OBJPS) $(OBJ)
	@echo "Compiling push_swap..."
	@$(CC) $(LIBS) $(MLXFLAGS) -o $(NAMEPS) $(OBJPS) $(OBJ)
	@echo "OK!"

$(NAMEC): libft $(LIBMLX) $(OBJC) $(OBJ)
	@echo "Compiling checker..."
	@$(CC) $(LIBS) $(MLXFLAGS) -o $(NAMEC) $(OBJC) $(OBJ)
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