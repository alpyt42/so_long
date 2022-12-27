NAME		=	so_long
SRCS		=	srcs/so_long.c
SRCS_BONUS	=	
LIBFT		=	libft/libft.a
MLX			=	mlx
MLX_LIB		=	mlx/libmlx.a
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address -g -I inc
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)
OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)


ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11 -Imlx_linux -lm -lz
MLX			=	mlx_linux
MLX_LIB		=	mlx_linux/libmlx.a
endif


all:		$(NAME)

$(NAME):	$(OBJS)
			@echo "Making LIBFT"
			@make -C libft
			@echo "Making MLX"
			@make -C ${MLX}
			$(CC) $(OBJS) $(LIBFT) ${MLX_LIB} $(MLXFLAGS) $(CFLAGS) -o $(NAME)

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