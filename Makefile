NAME		=	so_long
SRC			=	checker.c error_msg.c free_game.c game_init.c game_put_img.c game_update.c so_long.c
OBJS		=	${SRC:.c=.o}
LIBFT		=	libft.a
LIBFT_DIR	=	./libft
CFLAGS		=	-Wall -Wextra -Werror #-g3 -fsanitize=address
LINKMLX 	=	-lmlx -framework OpenGL -framework AppKit
CC			=	gcc
RM			=	rm -rf

all:	$(NAME)

.c.o:	${CC} ${CFLAGS} ${LINKMLX} -Idir -c  $< -o ${<:.c=.o}

$(NAME): ${OBJS}
		make -C $(LIBFT_DIR)
		$(CC) $(CFLAGS) ${LINKMLX} -Idir -o $@ $^ -L$(LIBFT_DIR) -lft

clean:
		$(RM) ${OBJS}
		make -C $(LIBFT_DIR) $@

fclean:	clean
		${RM} ${NAME}
		make -C $(LIBFT_DIR) $@

re:		fclean all

.PHONY:	all clean fclean re
