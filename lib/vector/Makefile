# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/08 07:41:41 by yonshin           #+#    #+#              #
#    Updated: 2022/12/17 16:23:46 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libvector.a
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
OBJS = \
	vect3.o \
	vsum3.o \
	vsub3.o \
	vrev3.o \
	vmul3.o \
	vdot3.o \
	vmag3.o \
	vnor3.o \
	vect4.o \
	vsum4.o \
	vsub4.o \
	vrev4.o \
	vmul4.o \
	vdot4.o \
	vmag4.o \
	vnor4.o \

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
