SRCS				= 	main.c draw_mandelbrot.c atod.c draw_julia.c zoom.c window.c
OBJS				=   ${SRCS:.c=.o}

LIBPRINTF_PATH		=	./ft_printf

MINILIBX_PATH		= 	./mlx-linux

MINILIBX			=	${MINILIBX_PATH}/libmlx.a

NAME				=	fractol

CC 					=	cc

RM					=	rm -f

CFLAGS				=	-Wall -Werror -Wextra -Iinclude -I/usr/include -g3

LDFLAGS				=	-L${MINILIBX_PATH} -L/usr/include -lmlx -lXext -lX11 -lm

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS} ${MINILIBX} 
				${CC} ${OBJS} ${MINILIBX} ${LDFLAGS} -o ${NAME}


${MINILIBX}:
			make -C ${MINILIBX_PATH}

all:			${MINILIBX}  ${NAME}

clean:
				${RM} ${OBJS} ${MINILIBX} 
					make -C ${MINILIBX_PATH} clean

fclean:			clean
				${RM} ${MINILIBX}  ${NAME}
					make -C ${MINILIBX_PATH}  clean

re:				fclean all

.PHONY:		all clean fclean re
