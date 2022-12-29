# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 07:41:41 by yonshin           #+#    #+#              #
#    Updated: 2022/12/30 07:52:51 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libutil.a
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
OBJS = \
	ft_calloc_guard.o \
	err_exit.o \
	free_splited_str.o \

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
