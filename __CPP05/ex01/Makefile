NAME 		:= 		Bureaucrat

SRCS_DIR	:=		./

INCS_DIR	:=		.

SRCS_FILES 	:= 		main.cpp Bureaucrat.cpp Form.cpp\

SRCS		:=		$(addprefix ${SRCS_DIR},${SRCS_FILES})

INCS 		:= 		-I $(INCS_DIR)

CC 			:=		c++

CPPFLAGS 	:= 		-Wall -Wextra -Werror -std=c++98

OBJS 		:= 		${SRCS:.cpp=.o}

DEPS 		:= 		${SRCS:.cpp=.d}

RM 			:=		rm -f

SYSTEM		:=		${shell uname}


ifeq (${SYSTEM}, Darwin)
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_REV=$'\x1b[7m
_GREY=$'\x1b[30m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_CYAN=$'\x1b[36m
_WHITE=$'\x1b[37m
endif

ifeq (${SYSTEM}, Linux)
_GREY=	$'\033[30m
_RED=	$'\033[31m
_GREEN=	$'\033[32m
_YELLOW=$'\033[33m
_BLUE=	$'\033[34m
_PURPLE=$'\033[35m
_CYAN=	$'\033[36m
_WHITE=	$'\033[37m
_END= $'\033[37m
endif

all:		${NAME}

.cpp.o:
				@printf "%-10s ${_YELLOW}${_BOLD}$<${_END}...\n" "Compiling"
				@${CC} ${CPPFLAGS} ${INCS} -c -MMD -MP $< -o $@ ${INCS}

${NAME}:	${OBJS}
				@printf "%-10s ${_PURPLE}${_BOLD}${NAME}${_END}...\n" "Compiling"
				@${CC} ${CPPFLAGS} -o ${NAME} ${OBJS} ${INCS}
				@printf "\n${_GREEN}${_BOLD}Compilation done !${_END}\n"
				

clean:
				@printf "%-10s ${_RED}${_BOLD}${NAME} binary files${_END}...\n" "Deleting"
				@${RM} ${OBJS} ${DEPS}

fclean:		clean
				@printf "%-10s ${_RED}${_BOLD}${NAME}${_END}...\n" "Deleting"
				@${RM} ${NAME}
	
re:			fclean all

-include ${DEPS}

.PHONY:	all clean fclean re
