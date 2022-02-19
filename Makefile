NAME=checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC=checker.c\
       tools.c\
	   ft_split.c\
       operations2.c\
	   operations3.c\
       operations4.c\
	   ft_strjoin.c\
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