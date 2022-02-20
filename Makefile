NAME=push_swap
NAME2=checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC=push_swap.c\
       tools.c\
	   operations1.c\
       operations2.c\
	   operations3.c\
       operations4.c\
	   sortfive.c\
	   a_process.c\
	   b_process.c

SRC2=checker.c\
       tools.c\
       bonus1.c\
	   bonus2.c\
       bonus3.c\
	   checker_process.c\
	   get_next_line.c\
	   get_next_line_utils.c

OBJ = $(subst .c,.o,$(SRC))
OBJ2 = $(subst .c,.o,$(SRC2))

all: $(NAME)

$(NAME): ${OBJ}
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
		${CC} -c ${CFLAGS} $< -o $@

bonus:$(NAME2)

$(NAME2): ${OBJ2}
	$(CC) $(OBJ2) -o $(NAME2)

%.o: %.c
		${CC} -c ${CFLAGS} $< -o $@

clean :
	$(RM) $(OBJ) $(OBJ2)

fclean: clean
	$(RM) $(NAME) $(NAME2)

re: fclean all