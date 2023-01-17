# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 03:59:05 by dcyprien          #+#    #+#              #
#    Updated: 2023/01/17 12:19:39 by dcyprien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Name
NAME		=	cub3D

#Colors
Y			=	"\033[33m"
R			=	"\033[31m"
G			=	"\033[32m"
B			=	"\033[34m"
X			=	"\033[0m"
UP			=	"\033[A"
CUT			=	"\033[K"

#Commands
CC			=	cc
RM			=	rm -rf
MAKE		=	make --no-print-directory
MKD			=	mkdir -p
INCLUDES	=	-I $(H_DIR)/
FLAGS		=	$(CFLAGS) $(MLX_FLAGS)
CFLAGS		=	-Wall -Wextra -Werror -g
MLX_FLAGS	=	-L mlx -lXext -lX11 -lm -lz
FSAN_FLAGS	=	-fsanitize=address

#Directories
S_DIR		=	srcs
H_DIR		=	includes
O_DIR		=	obj
L_DIR		=	lib

#Libft
LFT_DIR		=	$(L_DIR)/libft
LIBFT		=	$(L_DIR)/libft/libft.a

#MinilibX
MLX_DIR		=	$(L_DIR)/mlx-linux
MLX			=	$(L_DIR)/mlx-linux/libmlx_Linux.a

#SRC_FILES
SRCS	=	main.c\
			init.c\
			colors.c\
			get_next_line.c\
			malloc_free.c\
			map.c\
			textures.c\
			utils.c\
			utils_texture.c\
			errors.c\
			mlx_init.c\
			map_check.c\
			map_check_utils.c

#Object
OBJS	=	$(addprefix $(O_DIR)/, $(SRCS:.c=.o))

$(O_DIR)/%.o:	./*/%.c
				@echo $(Y)Compiling [$@]...$(X)
				@$(MKD) $(O_DIR)
				@$(CC) $(CFLAGS) -o $@ -c $<
				@printf $(UP) $(CUT)

$(NAME):	$(OBJS)
			@echo $(Y)Compiling [MinilibX]...$(X)
			@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1
			@printf $(UP)$(CUT)
			@echo $(G)Compiled [MinilibX]$(X)
			@$(MAKE) -C $(LFT_DIR)
			@echo $(Y)Compiling [$(NAME)]...$(X)
			@$(CC) -o $(NAME) $(FLAGS) $(OBJS) $(LIBFT) $(MLX)
			@printf $(UP)$(CUT)
			@echo $(G)Compiled [$(NAME)]$(X)

all:	$(NAME)

fsan: $(OBJS)
	@$(MAKE) -C $(LFT_DIR)
	@echo $(Y)Compiling [$(NAME)] with fsanitize=address flag...$(X)
	@$(CC) -o $(NAME) $(FLAGS) $(FSAN_FLAGS) $(OBJS) $(LIBFT) $(MLX)
	@printf $(UP)$(CUT)
	@echo $(G)Compiled [$(NAME)] with fsanitize=address flag$(X)

clean:
	@$(MAKE) clean -C $(LFT_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@printf $(UP)$(CUT)
	@$(RM) $(O_DIR)
	@echo $(R) removed $(NAME) obj files $(X)

fclean:	clean
		@$(RM) $(NAME)
		@echo $(R) removed $(NAME) executable $(X)
		@$(RM) -rf $(LIBFT)
		@echo $(R) removed libft.a $(X)

re:		fclean all
