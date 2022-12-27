NAME		= so_long
CC			= cc
FLAGS		= -Wall -Wextra -Werror -g -I inc
SRCS		= srcs/so_long.c
OBJS		= $(SRCS:.c=.o)

.c.o:
	${CC} ${FLAGS} -Imlx -c $< -o ${<:.c=.o}

CLR_RMV	= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN	= \033[1;36m
RM		= rm -f

UNAME	=	$(shell uname)

ifeq ($(UNAME), Darwin)
$(NAME): ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@echo "$(BLUE)MAKING MLX ${CLR_RMV}of ${CYAN}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C mlx all >/dev/null 2>&1
			@ cp ./mlx/libmlx.a .
			@echo "$(RED)libmlx.a created[0m ✔️"
			@echo "$(BLUE)MAKING LIBFT ${CLR_RMV}of ${CYAN}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C libft
			@echo "$(RED)libft.a created[0m ✔️"
			$(CC) $(CFLAGS) $(LIBFT) -Imlx $(OBJS) -Lmlx -lmlx -lm -framework OpenGL -framework AppKit -o $(NAME)
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

ifeq ($(UNAME), Linux)
$(NAME): ${OBJS}
			@echo "$(GREEN)Linux compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@echo "$(BLUE)MAKING MLX_LINUX ${CLR_RMV}of ${CYAN}$(NAME) ${CLR_RMV}..."
			@chmod 777 mlx_linux/configure
			@ $(MAKE) -C mlx_linux all
			@echo "$(RED)libmlx.a created[0m ✔️"
			@echo "$(BLUE)MAKING LIBFT ${CLR_RMV}of ${CYAN}$(NAME) ${CLR_RMV}..."
			@ $(MAKE) -C libft
			@echo "$(RED)libft.a created[0m ✔️"
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -Imlx_linux -Lmlx_linux -lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -g3 -o $(NAME)
			@echo "$(GREEN)$(NAME) created[0m ✔️"
endif

all:		${NAME}

ifeq ($(UNAME), Darwin)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif

ifeq ($(UNAME), Linux)
clean:
			@ ${RM} *.o */*.o */*/*.o
			@ rm -rf $(NAME).dSYM >/dev/null 2>&1
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
endif


ifeq ($(UNAME), Linux)
fclean:		clean
			@ ${RM} ${NAME}
			@ $(MAKE) -C mlx_linux clean 
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

ifeq ($(UNAME), Darwin)
fclean:		clean
			@ ${RM} ${NAME}
			@ rm libmlx.a
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
endif

re:			fclean all

.PHONY:		all clean fclean re