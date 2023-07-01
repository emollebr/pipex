# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emollebr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 14:04:01 by emollebr          #+#    #+#              #
#    Updated: 2023/06/06 14:04:03 by emollebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= pipex
CFLAGS	:= -Wall -Wextra -Werror
LIBFTFLAGS := -Imy_lib -Lmy_lib
LIBFT := ./my_lib/
LIBS := $(LIBFT)/my_lib.a
SRCS	:= pipex.c utils.c
OBJS	:= $(SRCS:.c=.o)
FILES := f1.txt f2.txt

################################################################################

${NAME}:  ${OBJS} ${LIBS} 
	 cc $^ ${LIBFTFLAGS} -o ${NAME} 

all:	libft ${NAME} touch

libft: 
	make -C ${LIBFT}

touch:
	touch f1.txt && echo Hello test >> f1.txt && touch f2.txt
	
.c.o:	${SRCS}
	cc ${CFLAGS} -I. -Imy_lib -c -o $@ $<	 

clean:
	rm -f ${OBJS} && cd ./my_lib && make clean && cd .. && rm -f ${FILES}

fclean:
	rm -f ${NAME} ./my_lib/my_lib.a

re:	clean all

.PHONY:		all clean fclean re

shelltest:	${FILES}
	< f1.txt ls -l | wc -l > f2.txt
	
test:		${FILES} ${NAME}
	./pipex f1.txt "ls -l" "wc -l" f2.txt
