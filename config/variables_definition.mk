# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables_definition.mk                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 08:35:23 by hyeyukim          #+#    #+#              #
#    Updated: 2022/12/28 19:36:22 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# commands and flags
CFLAGS = -Wall -Wextra -Werror
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
MLX_DIR = $(LIB_DIR)/minilibx
# library flags
LIBFLAGS = -lm -lmlx -L./$(LIB_DIR)/minilibx -lft -L./$(LIBFT_DIR) \
			-framework OpenGL -framework Appkit
# file names
MAN_FILE =	color \
			fdf_split \
			initialize \
			main \
			menu \
			mlx_draw \
			mlx_key_hooks \
			mlx_mouse_hooks \
			mlx_utils \
			process_input \
			transform1 \
			transform2 \
			utils_matrix \
			utils_vector3 \
			utils_vector4 \
			view
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
			key_mouse_code.h \
			matrix.h \
			vector.h
INCS = $(addprefix $(INC_DIR)/, $(INC_FILE))
INC_FLAG = -I./$(INC_DIR) -I./$(MLX_INC_DIR) -I./$(LIBFT_INC_DIR)
# object files
MAN_OBJ = $(addprefix $(OBJ_DIR)/$(MAN_DIR)/, $(addsuffix .o, $(MAN_FILE)))
BON_OBJ = $(addprefix $(OBJ_DIR)/$(BON_DIR)/, $(addsuffix .o, $(BON_FILE)))

