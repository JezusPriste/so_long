# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dborgian <dborgian@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 11:53:07 by dborgian          #+#    #+#              #
#    Updated: 2023/04/03 13:26:07 by dborgian         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =ft_strlen.c\
ft_split.c ft_itoa.c \
ft_putstr.c ft_strlcpy.c \

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror

.c.o:
	@${CC} ${FLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	@ar rcs ${NAME} ${OBJS}

bonus:	${OBJSBONUS}
		@ar rcs ${NAME} ${OBJSBONUS}

all: ${NAME}

clean:
	@${RM} ${OBJS} ${OBJSBONUS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

