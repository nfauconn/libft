# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nfauconn <nfauconn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 14:24:38 by nfauconn          #+#    #+#              #
#    Updated: 2024/01/23 14:13:28 by nfauconn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

NAME_BONUS = libft.a

HEADER = libft.h

SRCS = \
	${addsuffix .c, \
	ft_atoi \
	ft_bzero \
	ft_calloc \
	ft_isalnum \
	ft_isalpha \
	ft_isascii \
	ft_isdigit \
	ft_isprint \
	ft_itoa \
	ft_memchr \
	ft_memcmp \
	ft_memcpy \
	ft_memmove \
	ft_memset \
	ft_putchar_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_putstr_fd \
	ft_split \
	ft_strchr \
	ft_strdup \
	ft_striteri \
	ft_strjoin \
	ft_strlcat \
	ft_strlcpy \
	ft_strlen \
	ft_strmapi \
	ft_strncmp \
	ft_strnstr \
	ft_strrchr \
	ft_strtrim \
	ft_substr \
	ft_tolower \
	ft_toupper}
SRCS_BONUS = \
	${addsuffix _bonus.c, \
	ft_lstadd_back \
	ft_lstadd_front \
	ft_lstclear \
	ft_lstdelone \
	ft_lstiter \
	ft_lstlast \
	ft_lstmap \
	ft_lstnew \
	ft_lstsize}

OBJS := ${SRCS:.c=.o}
OBJS_BONUS := ${SRCS_BONUS:.c=.o}

CC = clang
CFLAGS = -Wall -Wextra -Werror
COMP = ${CC} ${CFLAGS}
RM = rm -f

all: ${NAME}

${NAME}: ${HEADER} ${OBJS} $(SRCS)
	ar rc ${NAME} ${OBJS}

bonus: ${OBJS} ${OBJS_BONUS}
	ar rc ${NAME} ${OBJS} ${OBJS_BONUS}

%.o: %.c
	${COMP} -c $< -o $@

clean:
	${RM} ${OBJS} ${OBJS_BONUS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus