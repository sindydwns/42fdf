# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 19:27:45 by yonshin           #+#    #+#              #
#    Updated: 2022/12/28 00:28:17 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libdraw.a
CFLAGS = -Wall -Wextra -Werror
ARFLAGS = rc
OBJS = \
	draw_pixel.o \
	draw_line.o \
	draw_rect.o \
	draw_circle.o \
	blending.o

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
