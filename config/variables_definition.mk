# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variables_definition.mk                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 08:35:23 by hyeyukim          #+#    #+#              #
#    Updated: 2022/12/30 07:58:18 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# commands and flags
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
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

# directory files
SRC_DIR = srcs
OBJ_DIR = objs
MAN_DIR = mandatory
BON_DIR = bonus

# header
INC_DIR = includes
MAN_INC_DIR = $(INC_DIR)/$(MAN_DIR)
BON_INC_DIR = $(INC_DIR)/$(BON_DIR)
MAN_INC_FILE = 	color.h \
				fdf.h \
				key_mouse_code.h \
				matrix.h \
				vector.h
BON_INC_FILE = color_bonus.h \
				fdf_bonus.h \
				key_mouse_code_bonus.h \
				matrix_bonus.h \
				vector_bonus.h

MAN_INC = $(addprefix $(INC_DIR)/$(MAN_DIR)/, $(MAN_INC_FILE))
BON_INC = $(addprefix $(INC_DIR)/$(BON_DIR)/, $(BON_INC_FILE))
MAN_INC_FLAG = -I./$(MAN_INC_DIR) -I./$(MLX_INC_DIR) -I./$(LIBFT_INC_DIR)
BON_INC_FLAG = -I./$(BON_INC_DIR) -I./$(MLX_INC_DIR) -I./$(LIBFT_INC_DIR)

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
			utils_vector4_1 \
			utils_vector4_2 \
			view
BON_FILE = color_bonus \
			fdf_split_bonus \
			initialize_bonus \
			main_bonus \
			menu_bonus \
			mlx_draw_bonus \
			mlx_key_hooks_bonus \
			mlx_mouse_hooks_bonus \
			mlx_utils_bonus \
			process_input_bonus \
			transform1_bonus \
			transform2_bonus \
			utils_matrix_bonus \
			utils_vector3_bonus \
			utils_vector4_1_bonus \
			utils_vector4_2_bonus \
			view_bonus


# object files
MAN_OBJ = $(addprefix $(OBJ_DIR)/$(MAN_DIR)/, $(addsuffix .o, $(MAN_FILE)))
BON_OBJ = $(addprefix $(OBJ_DIR)/$(BON_DIR)/, $(addsuffix .o, $(BON_FILE)))

# bonus
ifdef   WITH_BONUS
    RM_OBJ = $(MAN_OBJ)
    OBJ = $(BON_OBJ)
	INC = $(MAN_INC)
	INC_FLAG = $(MAN_INC_FLAG)
else
    RM_OBJ = $(BON_OBJ)
    OBJ = $(MAN_OBJ)
	INC = $(BON_INC)
	INC_FLAG = $(BON_INC_FLAG)
endif