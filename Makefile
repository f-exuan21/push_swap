NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS_DIR = srcs
SRC = ${wildcard ${SRCS_DIR}/*.c}


$(NAME) :
	$(CC) $(CFLAGS) $(SRC) -L./lib -lft -o $(NAME)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re
