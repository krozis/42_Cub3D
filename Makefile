# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcyprien <dcyprien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/14 03:59:05 by dcyprien          #+#    #+#              #
#    Updated: 2023/01/16 12:49:06 by dcyprien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./srcs/main.c\
			./srcs/init.c\
			./srcs/colors.c\
			./srcs/get_next_line.c\
			./srcs/malloc_free.c\
			./srcs/ft_strcmp.c\
			./srcs/map.c\
			./srcs/textures.c\
			./srcs/utils.c\

SRCSLIBFT =	./srcs/libft/ft_bzero.c\
			./srcs/libft/ft_memccpy.c\
			./srcs/libft/ft_memcpy.c\
			./srcs/libft/ft_memset.c\
			./srcs/libft/ft_strlen.c\
			./srcs/libft/ft_isalnum.c\
			./srcs/libft/ft_isalpha.c\
			./srcs/libft/ft_isdigit.c\
			./srcs/libft/ft_isprint.c\
			./srcs/libft/ft_memchr.c\
			./srcs/libft/ft_memcmp.c\
			./srcs/libft/ft_memmove.c\
			./srcs/libft/ft_isascii.c\
			./srcs/libft/ft_toupper.c\
			./srcs/libft/ft_tolower.c\
			./srcs/libft/ft_strchr.c\
			./srcs/libft/ft_strrchr.c\
			./srcs/libft/ft_strncmp.c\
			./srcs/libft/ft_strlcpy.c\
			./srcs/libft/ft_strlcat.c\
			./srcs/libft/ft_strnstr.c\
			./srcs/libft/ft_atoi.c\
			./srcs/libft/ft_strdup.c\
			./srcs/libft/ft_substr.c\
			./srcs/libft/ft_calloc.c\
			./srcs/libft/ft_strjoin.c\
			./srcs/libft/ft_strtrim.c\
			./srcs/libft/ft_split.c\
			./srcs/libft/ft_itoa.c\
			./srcs/libft/ft_strmapi.c\
			./srcs/libft/ft_putchar_fd.c\
			./srcs/libft/ft_putstr_fd.c\
			./srcs/libft/ft_putendl_fd.c\
			./srcs/libft/ft_putnbr_fd.c\
			./srcs/libft/ft_isspace.c\
			./srcs/libft/ft_cinset.c

NAME	=	cub3d

CC		=	cc

CCLIB	=	ar rc

CFLAGS	=	-Wall -Wextra -Werror -g

OBJS	=	${SRCS:.c=.o}

OBJSLIB =	$(SRCSLIBFT:.c=.o)

RM		=	rm -f

srcs/%.o: 	srcs/%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_Linux -c $< -o $@

srcs/%.o: srcs/libft/%.c
	$(CCLIB) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(OBJSLIB)
	$(CCLIB) libft.a $(OBJSLIB)
	$(CC) $(CFLAGS) $(OBJS) -L./mlx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lz libft.a -o $(NAME)

all:		${NAME}

clean:		
	${RM} ${OBJS}
	${RM} libft.a
	$(RM) $(OBJSLIB)

fclean:		clean
	${RM} ${NAME}

re:			fclean all

.PHONY = all clean fclean re