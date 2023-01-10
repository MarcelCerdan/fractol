.PHONY:	all clean fclean re

# ******** VARIABLES ******** #

# ---- Final Executable --- #

NAME		=	fractol

# ---- Directories ---- #

DIR_OBJS	=	.objs/

DIR_SRCS	= 	srcs/

DIR_HEAD 	=	incl/

DIR_LIBFT	=	libft

# ---- Files ---- #

HEAD_LST	=	fractol.h mlx.h libft.h

SRCS_LST 	= 	fractol.c 			init.c  	\
				manage_color.c		hooks.c 	\
				utils.c				print_msg.c	\
				mandelbrot.c		julia.c		\
				colors.c
					
OBJS_LST	=	${SRCS_LST:%.c=%.o}

HEAD 		= 	$(addprefix $(DIR_HEAD), $(HEAD_LST))

SRCS 		= 	$(addprefix $(DIR_SRCS), $(SRCS_LST))

OBJS 		= 	$(addprefix $(DIR_OBJS), $(OBJS_LST))

# ---- Compilation ---- #

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -O3
LMLX	= 	-lmlx -framework OpenGL -framework Appkit

# ---- Commands ---- #

RM		=	rm -rf
MKDIR	=	mkdir -p
AR		=	ar rc

# ********* RULES ******** #

all			:	libft.a ${NAME}

libft.a		:
				make -C ${DIR_LIBFT}

# ---- Variables Rules ---- #

${NAME}			:	${OBJS} Makefile ${HEAD}
					${CC} ${CFLAGS} -I $(DIR_HEAD) -L libft/ -lft -L . ${LMLX} ${OBJS} -o ${NAME}

# ---- Compiled Rules ---- #


$(DIR_OBJS)%.o	:	$(DIR_SRCS)%.c ${HEAD} Makefile | $(DIR_OBJS)
					${CC} ${CFLAGS} -I $(DIR_HEAD) -c $< -o $@ 

${DIR_OBJS}		:
					${MKDIR} ${DIR_OBJS}


# ---- Usual Commands ---- #

clean			:
					${RM} ${DIR_OBJS}

fclean			:	clean
					make fclean -C ${DIR_LIBFT}
					${RM} ${NAME}

re				:	fclean
					$(MAKE) all
