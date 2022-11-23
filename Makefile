vector		= ./vector_main.cpp
stack		= ./stack_main.cpp

RM			= rm -rf

FLAGS		= -Wall -Wextra -Werror -g3 -std=c++98 #-fsanitize=address

NAME		= ft

STL_NAME	= std

CC			= c++

all:				$(NAME)

$(NAME):			${CC} ${FLAGS} ${vector} -o ${NAME} -D FT
					${CC} ${FLAGS} ${vector} -o ${STL_NAME} -D STL

vector:
					${CC} ${FLAGS} ${vector} -o ${NAME} -D FT
					${CC} ${FLAGS} ${vector} -o ${STL_NAME} -D STL

stack:
					${CC} ${FLAGS} ${stack} -o ${NAME} -D FT
					${CC} ${FLAGS} ${stack} -o ${STL_NAME} -D STL

test:				vector
					valgrind ./ft

clean:
					

fclean:		clean
					${RM} ${NAME}
					${RM} ${STL_NAME}

re:			fclean
			make all
					

.SILENT:

.PHONY: all clean fclean re bonus
