NAME = minishell
INCLUDES = -I$(HEADERS_DIRECTORY)

# Header files
HEADERS_DIRECTORY = ./includes/
HEADERS_LIST = minishell.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

LIBFT = ./libft/libft.a
LIB = ar -rcs $(NAME)

SRC = sources/main.c sources/enviroment.c sources/utils.c sources/execute.c \
	sources/bin_commands.c sources/pwd.c sources/parse.c
OBJ = $(SRC:.c=.o)


CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -I ~/.brew/opt/readline/include
CC = gcc

%.o: %.c
		$(CC) $(CFLAGS) -c  $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS) Makefile
		$(MAKE) -C ./libft
		$(CC) $(OBJ) -o $(NAME) -lreadline -L ~/.brew/opt/readline/lib $(LIBFT)

clean:
		$(MAKE) clean -C ./libft
		rm -rf $(OBJ)

fclean: clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re: fclean all

.PHONY:	all clean fclean re
