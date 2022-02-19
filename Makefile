NAME=checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC=checker.c\
       tools.c\
       operations2.c\
	   operations3.c\
       operations4.c\
	   operations5.c\
	   checker_process.c\
	   get_next_line.c\
	   get_next_line_utils.c

OBJ = $(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME): ${OBJ}
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
		${CC} -c ${CFLAGS} $< -o $@

clean :
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all