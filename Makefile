NAME		=	so_long
CC			=	clang
SRCS		=	srcs/main.c

LIBFT		=	libft/libft.a
CFLAGS		=	-Wall -Wextra -Werror
MLXFLAGS	=	-L ./mlx/ -lmlx -framework OpenGL -framework AppKit -lz
RM			=	rm -f
OBJS		=	$(SRCS:%.c=%.o)

ifeq ($(shell uname), Linux)
MLXFLAGS	=	-L ./mlx_linux/ -lmlx -Ilmlx -lXext -lX11
endif


all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft	
			make clean -C libft
			$(CC) $(SRCS) $(LIBFT) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

%o:			%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

run:		all
			./$(NAME) maps/map_bonus.ber

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			$(RM) *.out
			make fclean -C libft/

re:			fclean all

git:
	@git add .
	@git commit -m "$m"
	@git push
	@echo "Commit sent to github"
# To call: make git m="my commit"

.PHONY:		all clean fclean re