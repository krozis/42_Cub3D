# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stelie <stelie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 03:59:05 by dcyprien          #+#    #+#              #
#    Updated: 2023/01/16 16:13:22 by stelie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#SRCSLIBFT =	libft/ft_bzero.c\
			libft/ft_memccpy.c\
			libft/ft_memcpy.c\
			libft/ft_memset.c\
			libft/ft_strlen.c\
			libft/ft_isalnum.c\
			libft/ft_isalpha.c\
			libft/ft_isdigit.c\
			libft/ft_isprint.c\
			libft/ft_memchr.c\
			libft/ft_memcmp.c\
			libft/ft_memmove.c\
			libft/ft_isascii.c\
			libft/ft_toupper.c\
			libft/ft_tolower.c\
			libft/ft_strchr.c\
			libft/ft_strrchr.c\
			libft/ft_strncmp.c\
			libft/ft_strlcpy.c\
			libft/ft_strlcat.c\
			libft/ft_strnstr.c\
			libft/ft_atoi.c\
			libft/ft_strdup.c\
			libft/ft_substr.c\
			libft/ft_calloc.c\
			libft/ft_strjoin.c\
			libft/ft_strtrim.c\
			libft/ft_split.c\
			libft/ft_itoa.c\
			libft/ft_strmapi.c\
			libft/ft_putchar_fd.c\
			libft/ft_putstr_fd.c\
			libft/ft_putendl_fd.c\
			libft/ft_putnbr_fd.c\
			libft/ft_isspace.c\
			libft/ft_cinset.c

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
#			init.c\
			colors.c\
			get_next_line.c\
			malloc_free.c\
			ft_strcmp.c\
			map.c\
			textures.c\
			utils.c\

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
