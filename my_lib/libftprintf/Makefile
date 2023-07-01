# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emollebr <emollebr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 14:30:33 by emollebr          #+#    #+#              #
#    Updated: 2023/01/17 17:55:52 by emollebr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libftprintf.a

SRCS			= ft_printf.c ft_putptr.c ft_printnum.c ft_putchar_int.c ft_putstr_int.c ft_puthex.c ft_putunsigned.c ft_itoa_printf.c ft_printnum.c ft_isalnum.c ft_isprint.c ft_memcmp.c ft_strlcat.c ft_strncmp.c \
ft_substr.c ft_atoi.c ft_isalpha.c ft_memcpy.c ft_strchr.c  ft_strlcpy.c ft_strnstr.c \
ft_tolower.c ft_bzero.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strlen.c ft_strrchr.c \
ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c ft_strjoin.c ft_strtrim.c \
ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c \
ft_lstnew.c ft_lstadd_back.c ft_lstadd_front.c ft_lstlast.c ft_lstsize.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \

OBJS			= $(SRCS:.c=.o)

CC			= cc
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror
IFLAGS			= -I

all:			$(NAME)
	$(CC) $(CFLGS) -o $@ $< $(IFLGS)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

bonus:			$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
