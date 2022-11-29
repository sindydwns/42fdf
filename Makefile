# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 20:46:00 by yonshin           #+#    #+#              #
#    Updated: 2022/11/29 19:39:45 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAGS = -Wall -Wextra -Werror
MLXLIB = ./lib/mlx/libmlx.a
LIB = \
	./lib/draw/libdraw.a \

INCLUDE = $(addprefix -I, $(dir $(LIB))) -I$(dir $(MLXLIB))
LIBDUP = $(notdir $(LIB)) $(notdir $(MLXLIB))
OBJS = \
	fdf.o

all: $(NAME) 

bonus: $(NAME) 

$(NAME): $(OBJS) $(LIB) $(MLXLIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDUP) $(DEBUG) $(OUTPUT_OPTION) -framework OpenGL -framework AppKit 

$(LIB) $(MLXLIB):
	make -C $(@D)
	cp $@ $(@F)

%.o: %.c $(LIB)
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $(INCLUDE) $(DEBUG) -c $*.c

clean:
	rm -f $(OBJS)
	for dir in $(dir $(LIB)); do make -C $$dir clean; done
	make -C $(dir $(MLXLIB)) clean

fclean: clean
	rm -f $(NAME)
	for dir in $(dir $(LIB)); do make -C $$dir fclean; done
	rm -f $(LIBDUP)

re: 
	make fclean
	make all

run: all
	./$(NAME)

debug:
	make DEBUG='-g3 -fsanitize=address'

.PHONY : all clean fclean re bonus debug
