# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables_definition.mk                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 08:35:23 by hyeyukim          #+#    #+#              #
#    Updated: 2022/12/25 16:17:43 by hyeyun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# commands and flags
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
AR = ar
ARFLAGS = crs
RM = rm
RMFLAGS = -rf

# library
LIB_DIR = library
### libft
LIBFT_NAME = libft.a
LIBFT_DIR = $(LIB_DIR)/libft
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)
LIBFT_INC_DIR = $(LIBFT_DIR)/includes
### minilibx
MLX_INC_DIR = $(LIB_DIR)/minilibx  
# library flags
LIBFLAGS = -lmlx -L./$(LIB_DIR)/minilibx -lft -L./$(LIBFT_DIR) -lXext -lX11 -lm -lz
# file names
MAN_FILE =	main \
			parse_input \
			show_image \
			show_map \
			show_menu \
			trans_project \
			trans_view \
			trans_world \
			utils_object \
			utils_line \
			utils_matrix \
			utils_mlx \
			utils_split \
			utils_vector
BON_FILE = 

# directory files
SRC_DIR = srcs
OBJ_DIR = objs
MAN_DIR = mandatory
BON_DIR = bonus

# header
INC_DIR = includes
INC_FILE = 	color.h \
			fdf.h \
			keycode.h \
			matrix.h \
			vector.h
INCS = $(addprefix $(INC_DIR)/, $(INC_FILE))	

# object files
MAN_OBJ = $(addprefix $(OBJ_DIR)/$(MAN_DIR)/, $(addsuffix .o, $(MAN_FILE)))
BON_OBJ = $(addprefix $(OBJ_DIR)/$(BON_DIR)/, $(addsuffix .o, $(BON_FILE)))

