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


ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
MLX			=	mlx_linux
endif


all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "Making LIBFT"
			@make -C libft
			@echo "Making MLX"
			@make -C ${MLX}
			$(CC) $(OBJS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

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
			@make clean -C libft

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
			@make fclean -C libft/

re:			fclean all

git:
	@git add .
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"
# make git m="commit"

.PHONY:		all clean fclean re