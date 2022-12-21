# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 07:41:41 by yonshin           #+#    #+#              #
#    Updated: 2022/12/22 00:59:39 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libutil.a
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
OBJS = \
	ft_calloc_guard.o \
	err_exit.o \

INCLUDE =

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $(DEBUG) $(INCLUDE) -c $*.c

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY : all clean fclean re bonus debug
