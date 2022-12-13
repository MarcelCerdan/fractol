.PHONY:	all clean fclean re

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	fractol

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	= 	srcs/

# ---- Files ---- #

HEAD		=	fractol.h

SRCS		=	fractol.c		manage_win.c \
				manage_color.c

OBJS		=	${SRCS:%.c=${DIR_OBJS}%.o}

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
LMLX	= 	-lmlx -framework OpenGL -framework Appkit

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p
AR		=	ar rc

# ********* RULES ******** #

all			:	${NAME}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} Makefile ${HEAD}
					${CC} ${CFLAGS} -I . -L . ${LMLX} ${OBJS} -o ${NAME}

# ---- Compiled Rules ---- #

${OBJS}			:	| ${DIR_OBJS}

${DIR_OBJS}%.o	:	%.c ${HEAD} Makefile
					${CC} ${CFLAGS} -I . -c $< -o $@

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}

# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					${RM} ${NAME}

re				:	fclean all
