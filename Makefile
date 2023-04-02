# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:56:15 by snemoto           #+#    #+#              #
#    Updated: 2023/03/13 18:14:49 by snemoto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GNL_SRCS	= \
			get_next_line.c \
			get_next_line_utils.c \
			main.c

# GNL_SRCS	= \
# 			get_next_line_bonus.c \
# 			get_next_line_utils_bonus.c \
# 			main.c

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
NAME	= gnl
SRCS	= ${GNL_SRCS}
OBJS	= ${SRCS:.c=.o}

$(NAME):
		@${CC} ${CFLAGS} ${SRCS} -o ${NAME}

all:	${NAME}

clean:
		@${RM} ${OBJS}

fclean:	clean
		@${RM} ${NAME}

re:		fclean all

.PHONY: all clean fclean re
