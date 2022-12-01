# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chchin <chchin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 09:21:03 by chchin            #+#    #+#              #
#    Updated: 2022/06/10 10:31:48 by chchin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	ft_isalpha.c	\
			ft_isdigit.c	\
			ft_isalnum.c	\
			ft_isascii.c	\
			ft_isprint.c	\
			ft_strlen.c		\
			ft_memset.c		\
			ft_bzero.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_strlcpy.c	\
			ft_strlcat.c	\
			ft_toupper.c	\
			ft_tolower.c	\
			ft_strchr.c		\
			ft_strrchr.c	\
			ft_strncmp.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_strnstr.c	\
			ft_atoi.c		\
			ft_calloc.c		\
			ft_strdup.c		\
			ft_substr.c		\
			ft_strjoin.c	\
			ft_strtrim.c	\
			ft_split.c		\
			ft_itoa.c		\
			ft_strmapi.c	\
			ft_striteri.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c	\
			ft_lstnew.c		\
			ft_lstadd_front.c\
			ft_lstsize.c	\
			ft_lstlast.c	\
			ft_lstadd_back.c\
			ft_lstdelone.c	\
			ft_lstclear.c	\
			ft_lstiter.c	\
			ft_lstmap.c		\
			get_next_line.c	\
			ft_printf.c		\
			ft_printf_utils.c\

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra
OBJS	=	${SRCS:.c=.o}
AR		=	ar rcs
RM		=	rm -f

%.o: %.c
			${CC} -c ${CFLAGS} $?

all:		${NAME}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}


clean:
			${RM} ${OBJS} ${OBJSB}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re

bonus:		${OBJSB}
			${AR} ${NAME} ${OBJSB}

