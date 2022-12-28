NAME		=	so_long
SRCS		=	srcs/so_long.c
SRCS_BONUS	=	
LIBFT		=	libft/libft.a
MLX			=	mlx
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)

CLR_RMV	= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
CYAN	= \033[1;36m
RM		= rm -f

ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
MLX			=	mlx_linux
endif

all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${CYAN}$(NAME) ${CLR_RMV}..."
			@echo "$(BLUE)MAKING LIBFT ${CLR_RMV}of ${CYAN}$(NAME) ${CLR_RMV}..."
			@make -C libft
			@echo "$(YELLOW)libft.a created[0m ✔️"
			@echo "$(BLUE)MAKING MLX ${CLR_RMV}of ${CYAN}$(NAME) ${CLR_RMV}..."
			@make -C ${MLX}
			@echo "$(YELLOW)libmlx.a created[0m ✔️"
			$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)
			@echo "$(GREEN)$(NAME) created[0m ✔️"

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

bonus: 		$(OBJS_BONUS)
			@echo "Making LIBFT"
			@make -C libft
			@echo "Making MLX"
			@make -C ${MLX}
			$(CC) $(OBJS_BONUS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)
			@make clean -C ${MLX}
			@ echo "$(RED)Clean $(CYAN)MLX$(CLR_RMV) ✔️"
			@make clean -C libft
			@ echo "$(RED)Clean $(CYAN)libft$(CLR_RMV) ✔️"
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			$(RM) $(NAME)
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
			$(RM) *.out
			@ echo "$(RED)Deleting $(CYAN)./a.out ✔️$(CLR_RMV)"
			@make fclean -C libft/
			@ echo "$(RED)Fclean $(CYAN)libft$(CLR_RMV) ✔️"

re:			fclean all

.PHONY:		all clean fclean re