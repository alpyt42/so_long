NAME = so_long

HEADERS = so_long.h

SOURCES = 

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror -Imlx

all :    $(NAME)

$(NAME) : $(OBJECTS)
	${CC} ${CFLAG} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $@ $^

%.o : %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJECTS)

fclean : clean
	$(RM) $(NAME)

re : fclean
	$(MAKE) all

.PHONY: all clean fclean re