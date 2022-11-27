vector		= ./main/vector_main.cpp
stack		= ./main/stack_main.cpp
map			= ./main/map_main.cpp
set			= ./main/set_main.cpp

RED			='\033[0;31m'
PURPLE		='\033[0;35m'
NC			='\033[0m'

COL			=$(shell tput cols)

RM			= rm -rf

FLAGS		= -Wall -Wextra -Werror -g3 -std=c++98 #-fsanitize=address

NAME		= ft

STL_NAME	= std

CC			= c++

all:				$(NAME)

$(NAME):			${CC} ${FLAGS} ${vector} -o ${NAME}_vector -D FT
					${CC} ${FLAGS} ${vector} -o ${STL_NAME}_vector -D STL
					@mkdir -p output
					@mkdir -p error
					valgrind ./ft_vector > output/ft_output_vector 2> error/ft_err_vector
					valgrind ./std_vector > output/std_output_vector 2> error/std_err_vector
					pr -w ${COL} -m output/ft_output_vector output/std_output_vector

vector:
					${CC} ${FLAGS} ${vector} -o ${NAME}_vector -D FT
					${CC} ${FLAGS} ${vector} -o ${STL_NAME}_vector -D STL
					@mkdir -p output
					@mkdir -p error
					valgrind ./ft_vector > output/ft_output_vector 2> error/ft_err_vector
					valgrind ./std_vector > output/std_output_vector 2> error/std_err_vector
					pr -w ${COL} -m output/ft_output_vector output/std_output_vector

stack:
					${CC} ${FLAGS} ${stack} -o ${NAME}_stack -D FT
					${CC} ${FLAGS} ${stack} -o ${STL_NAME}_stack -D STL
					@mkdir -p output
					@mkdir -p error
					valgrind ./ft_stack > output/ft_output_stack 2> error/ft_err_stack
					valgrind ./std_stack > output/std_output_stack 2> error/std_err_stack
					pr -w ${COL} -m output/ft_output_stack output/std_output_stack

map:
					${CC} ${FLAGS} ${map} -o ${NAME}_map -D FT
					${CC} ${FLAGS} ${map} -o ${STL_NAME}_map -D STL
					@mkdir -p output
					@mkdir -p error
					valgrind ./ft_map > output/ft_output_map 2> error/ft_err_map
					valgrind ./std_map > output/std_output_map 2> error/std_err_map
					pr -w ${COL} -m output/ft_output_map output/std_output_map

set:
					${CC} ${FLAGS} ${set} -o ${NAME}_set -D FT
					${CC} ${FLAGS} ${set} -o ${STL_NAME}_set -D STL
					valgrind ./ft_set > output/ft_output_set 2> error/ft_err_set
					valgrind ./std_set > output/std_output_set 2> error/std_err_set
					pr -w ${COL} -m output/ft_output_set output/std_output_set

compile:			
					@echo "Compiling vector, stack, map, set"

test:				compile vector stack map set
					@echo
					@echo "Creating log file using valgrind on each containers"
					@mkdir -p output
					@mkdir -p error
					@echo
					@echo "FT version"
					valgrind ./ft_vector > output/ft_output_vector 2> error/ft_err_vector
					valgrind ./ft_stack > output/ft_output_stack 2> error/ft_err_stack
					valgrind ./ft_map > output/ft_output_map 2> error/ft_err_map
					valgrind ./ft_set > output/ft_output_set 2> error/ft_err_set
					@echo "STL version"
					valgrind ./std_vector > output/std_output_vector 2> error/std_err_vector
					valgrind ./std_stack > output/std_output_stack 2> error/std_err_stack
					valgrind ./std_map > output/std_output_map 2> error/std_err_map
					valgrind ./std_set > output/std_output_set 2> error/std_err_set
					@echo
					@echo "${RED}DIFF OUTPUT TEST${NC}"
					@echo
					@echo "${PURPLE}diff ft_output_vector std_output_vector${NC}"
					diff output/ft_output_vector output/std_output_vector
					@echo "${PURPLE}diff ft_output_stack std_output_stack${NC}"
					diff output/ft_output_stack output/std_output_stack
					@echo "${PURPLE}diff ft_output_map std_output_map${NC}"
					diff output/ft_output_map output/std_output_map
					@echo "${PURPLE}diff ft_output_set std_output_set${NC}"
					diff output/ft_output_set output/std_output_set
					@echo
					@echo
					@echo "Valgrind errors"
					@echo
					@echo "${RED}vector${NC}"
					cat error/ft_err_vector
					@echo
					@echo "${RED}stack${NC}"
					cat error/ft_err_stack
					@echo
					@echo "${RED}map${NC}"
					cat error/ft_err_map
					@echo
					@echo "${RED}set${NC}"
					cat error/ft_err_set

clean:
					${RM} output			
					${RM} error

fclean:		clean
					${RM} ${NAME}_vector
					${RM} ${NAME}_stack
					${RM} ${NAME}_map
					${RM} ${NAME}_set
					${RM} ${STL_NAME}_vector
					${RM} ${STL_NAME}_stack
					${RM} ${STL_NAME}_map
					${RM} ${STL_NAME}_set

re:			fclean
			make all
					

.SILENT:

.PHONY: all clean fclean re bonus
