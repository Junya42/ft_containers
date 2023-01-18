vector		= ./main/vector_main.cpp
stack		= ./main/stack_main.cpp
map			= ./main/map_main.cpp
set			= ./main/set_main.cpp

vectorb		= ./benchmark_mains/vector_benchmark.cpp
stackb		= ./benchmark_mains/stack_benchmark.cpp
mapb		= ./benchmark_mains/map_benchmark.cpp
setb		= ./benchmark_mains/set_benchmark.cpp

main		= ./main/main.cpp
bench		= ./benchmark_mains/main.cpp

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

$(NAME):			
					${CC} ${FLAGS} ${vector} -o ${NAME}_vector -D FT
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

defaultmain:
					${CC} ${FLAGS} ${main} -o ${NAME}_main -D FT
					${CC} ${FLAGS} ${main} -o ${STL_NAME}_main -D STL
					@mkdir -p output
					@mkdir -p error
					valgrind ./ft_main 42 > output/ft_output_main 2> error/ft_err_main
					valgrind ./std_main 42 > output/std_output_main 2> error/std_err_main
					pr -w ${COL} -m output/ft_output_main output/std_output_main
					rm ft_main std_main

defaultbench:
					${CC} ${bench} -o ${NAME}_bench -D FT
					${CC} ${bench} -o ${STL_NAME}_bench -D STL
					@mkdir -p benchmark
					./ft_bench 42 > benchmark/ft_42
					./std_bench 42 > benchmark/std_42
					mv ft_bench benchmark/
					mv std_bench benchmark/
					pr -T -w ${COL} -m benchmark/ft_42 benchmark/std_42

vectortest:
					${CC} ${FLAGS} ${vector} -o ${NAME}_vector -D FT
					${CC} ${FLAGS} ${vector} -o ${STL_NAME}_vector -D STL

vectorbenchmark:
					${CC} ${FLAGS} ${vectorb} -o ${NAME}_vector_benchmark -D FT
					${CC} ${FLAGS} ${vectorb} -o ${STL_NAME}_vector_benchmark -D STL

stack:
					${CC} ${FLAGS} ${stack} -o ${NAME}_stack -D FT
					${CC} ${FLAGS} ${stack} -o ${STL_NAME}_stack -D STL
					@mkdir -p output
					@mkdir -p error
					valgrind ./ft_stack > output/ft_output_stack 2> error/ft_err_stack
					valgrind ./std_stack > output/std_output_stack 2> error/std_err_stack
					pr -w ${COL} -m output/ft_output_stack output/std_output_stack

stacktest:
					${CC} ${FLAGS} ${stack} -o ${NAME}_stack -D FT
					${CC} ${FLAGS} ${stack} -o ${STL_NAME}_stack -D STL

stackbenchmark:
					${CC} ${FLAGS} ${stackb} -o ${NAME}_stack_benchmark -D FT
					${CC} ${FLAGS} ${stackb} -o ${STL_NAME}_stack_benchmark -D STL

map:
					${CC} ${FLAGS} ${map} -o ${NAME}_map -D FT
					${CC} ${FLAGS} ${map} -o ${STL_NAME}_map -D STL
					@mkdir -p output
					@mkdir -p error
					valgrind ./ft_map > output/ft_output_map 2> error/ft_err_map
					valgrind ./std_map > output/std_output_map 2> error/std_err_map
					pr -w ${COL} -m output/ft_output_map output/std_output_map

maptest:
					${CC} ${FLAGS} ${map} -o ${NAME}_map -D FT
					${CC} ${FLAGS} ${map} -o ${STL_NAME}_map -D STL

mapbenchmark:
					${CC} ${FLAGS} ${mapb} -o ${NAME}_map_benchmark -D FT
					${CC} ${FLAGS} ${mapb} -o ${STL_NAME}_map_benchmark -D STL

set:
					${CC} ${FLAGS} ${set} -o ${NAME}_set -D FT
					${CC} ${FLAGS} ${set} -o ${STL_NAME}_set -D STL
					valgrind ./ft_set > output/ft_output_set 2> error/ft_err_set
					valgrind ./std_set > output/std_output_set 2> error/std_err_set
					pr -w ${COL} -m output/ft_output_set output/std_output_set

settest:
					${CC} ${FLAGS} ${set} -o ${NAME}_set -D FT
					${CC} ${FLAGS} ${set} -o ${STL_NAME}_set -D STL

setbenchmark:
					${CC} ${FLAGS} ${setb} -o ${NAME}_set_benchmark -D FT
					${CC} ${FLAGS} ${setb} -o ${STL_NAME}_set_benchmark -D STL

compile:			
					@echo "Compiling vector, stack, map, set"

test:				compile vectortest stacktest maptest settest
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

benchmark:			compile vectorbenchmark stackbenchmark mapbenchmark setbenchmark
					@echo
					@mkdir -p benchmark
					./ft_vector_benchmark > benchmark/ft_vec
					./std_vector_benchmark > benchmark/std_vec
					mv ft_vector_benchmark benchmark/
					mv std_vector_benchmark benchmark/
					pr -T -w ${COL} -m benchmark/ft_vec benchmark/std_vec
					./ft_stack_benchmark > benchmark/ft_stack
					./std_stack_benchmark > benchmark/std_stack
					mv ft_stack_benchmark benchmark/
					mv std_stack_benchmark benchmark/
					pr -T -w ${COL} -m benchmark/ft_stack benchmark/std_stack
					./ft_map_benchmark > benchmark/ft_map
					./std_map_benchmark > benchmark/std_map
					mv ft_map_benchmark benchmark/
					mv std_map_benchmark benchmark/
					pr -T -w ${COL} -m benchmark/ft_map benchmark/std_map
					./ft_set_benchmark > benchmark/ft_set
					./std_set_benchmark > benchmark/std_set
					mv ft_set_benchmark benchmark/
					mv std_set_benchmark benchmark/
					pr -T -w ${COL} -m benchmark/ft_set benchmark/std_set
					

clean:
					${RM} output			
					${RM} error
					${RM} benchmark

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
