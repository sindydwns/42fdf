# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonshin <yonshin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/25 20:46:00 by yonshin           #+#    #+#              #
#    Updated: 2022/12/30 02:19:50 by yonshin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAGS = -Wall -Wextra -Werror
MLXLIB = ./lib/mlx/libmlx.a
LIB = \
	./lib/draw/libdraw.a \
	./lib/vector/libvector.a \
	./lib/libft/libft.a \
	./lib/myutil/libutil.a \

INCLUDE = $(addprefix -I, $(dir $(LIB))) -I$(dir $(MLXLIB))
LIBDUP = $(notdir $(LIB)) $(notdir $(MLXLIB))
OBJS = \
	fdf.o \
	fdf_create_map.o \
	fdf_destroy_map.o \
	fdf_events.o \
	fdf_transform_matrix.o \

BONUS_OBJS = \
	fdf_bonus.o \
	fdf_create_map_bonus.o \
	fdf_create_sphere_bonus.o \
	fdf_destroy_map_bonus.o \
	fdf_events_bonus.o \
	fdf_transform_matrix_bonus.o \
	fdf_keyset_bonus.o \

ifdef WITH_BONUS
	OBJS = $(BONUS_OBJS)
endif

all: $(NAME) 

bonus:
	make WITH_BONUS=1 all

$(NAME): $(OBJS) $(LIB) $(MLXLIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBDUP) $(DEBUG) $(OUTPUT_OPTION) -framework OpenGL -framework AppKit 

$(LIB) $(MLXLIB):
	make -C $(@D)
	cp $@ $(@F)

%.o: %.c $(LIB)
	$(CC) $(CFLAGS) $(OUTPUT_OPTION) $(INCLUDE) $(DEBUG) -c $*.c

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)
	for dir in $(dir $(LIB)); do make -C $$dir clean; done
	make -C $(dir $(MLXLIB)) clean

fclean: clean
	rm -f $(NAME)
	for dir in $(dir $(LIB)); do make -C $$dir fclean; done
	rm -f $(LIBDUP)

re: 
	make fclean
	make all

dev:
	if [ -e $(NAME) ]; then make fclean; fi
	make all
	./$(NAME)

debug:
	make DEBUG='-g3 -fsanitize=address'

.PHONY : all clean fclean re bonus debug dev
