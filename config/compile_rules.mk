# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_rules.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 08:37:47 by hyeyukim          #+#    #+#              #
#    Updated: 2022/12/22 11:52:01 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile rules

$(OBJ_DIR)/$(MAN_DIR)/%.o : $(SRC_DIR)/$(MAN_DIR)/%.c $(INC_DIR)/fdf.h
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(MAN_DIR)
	@$(CC) -c $(CFLAGS) $< -I./$(INC_DIR) -I./$(LIBFT_INC_DIR) -o $@

$(OBJ_DIR)/$(BON_DIR)/%.o : $(SRC_DIR)/$(MAN_DIR)/%.c $(INC_DIR)/fdf.h
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(BON_DIR)
	@$(CC) -c $(CFLAGS) $< -I$(INC_DIR) -I$(LIBFT_INC_DIR) -o $@
