# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables_definition.mk                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 08:35:23 by hyeyukim          #+#    #+#              #
#    Updated: 2022/12/20 19:43:30 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# commands and flags
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -rf
LIBFLAGS = -lm -lmlx -Lminilibx -framework OpenGL -framework AppKit

# library
LIB_NAME = libft.a
LIB_DIR = libft
LIB = $(LIB_DIR)/$(LIB_NAME)
LIBFT_INC_DIR = libft/includes

# file names
MAN_FILE =	fdf_split_map \
			image_utils \
			main \
			matrix \
			menu \
			process_input \
			show_image \
			show_map \
			transform_project \
			transform_view \
			transform_world \
			vector3 \
			vector4 \

BON_FILE = 

# directory files
OBJ_DIR = objcs
MAN_DIR = mandatory
BON_DIR = bonus

# header
INC_DIR = includes

# object files
MAN_OBJ = $(addprefix $(OBJ_DIR)/$(MAN_DIR)/, $(addsuffix .o, $(MAN_FILE)))
BON_OBJ = $(addprefix $(OBJ_DIR)/$(BON_DIR)/, $(addsuffix .o, $(BON_FILE)))

