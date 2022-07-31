# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgrulois <bgrulois@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 15:32:18 by bgrulois          #+#    #+#              #
#    Updated: 2022/06/30 15:06:49 by bgrulois         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long	

NAME_B 	=	so_long++

SRCS	=	gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		libft/ft_strjoin.c \
		libft/ft_itoa.c \
		libft/ft_split.c \
		struct_init.c \
		ft_parsing_utils.c \
		ft_parsing.c \
		so_long_utils.c \
		so_long_events.c \
		so_long_rules.c \
		so_long.c \
		so_long_mem_tools.c \
		so_long_free_tools.c \
		main.c

SRCS_BONUS =	gnl/get_next_line_utils.c \
		gnl/get_next_line.c \
		libft/ft_strjoin.c \
		libft/ft_itoa.c \
		libft/ft_split.c \
		ft_parsing_utils.c \
		ft_parsing.c \
		struct_init.c \
		so_long_utils.c \
		so_long_events.c \
		so_long_rules.c \
		so_long.c \
		so_long_mem_tools.c \
		so_long_free_tools.c \
		bonus/bonus.c \
		bonus/bonus_utils.c \
		bonus/ft_respawn.c \
		bonus/main_b.c

CC	=	gcc	

CFLAGS	=	-Wall -Wextra -Werror -g3

OBJS	=	${SRCS:%.c=%.o}

OBJS_B	=	${SRCS_BONUS:%.c=%.o}

%.o:		%.c
		$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -c $< -o $@

${NAME}: 	$(OBJS)
		${CC} ${CFLAGS} $(OBJS) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -o $(NAME)

${NAME_B}: 	$(OBJS_B)
		${CC} ${CFLAGS} $(OBJS_B) -Lmlx_linux -lmlx -L/usr/lib -Imlx_linux -lXext -lX11 -lm -o $(NAME_B)

all:		${NAME}

bonus:		${NAME_B}

clean:		
		rm -rf ${OBJS}

clean_b:		
		rm -rf ${OBJS_B}

fclean:		clean
		rm -rf ${NAME}

re:		fclean all

.PHONY:		all clean fclean re bonus
