# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 07:41:41 by yonshin           #+#    #+#              #
#    Updated: 2022/12/08 08:41:20 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvector.a
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
OBJS = \
	vect.o \
	vsum.o \
	vsub.o \
	vrev.o \
	vmul.o \
	vpdt.o \
	vdot.o \
	vmag.o \
	vnor.o \

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
