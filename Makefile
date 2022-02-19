NAME=checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC=checker.c\
       tools.c\
	   operations1.c\
       operations2.c\
	   operations3.c\
       operations4.c\
	   sortfive.c\
	   a_process.c\
	   b_process.c\
	   checker_process.c

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