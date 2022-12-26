# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    compile_rules.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 08:37:47 by hyeyukim          #+#    #+#              #
#    Updated: 2022/12/26 11:48:20 by hyeyun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile rules

$(OBJ_DIR)/$(MAN_DIR)/%.o : $(SRC_DIR)/$(MAN_DIR)/%.c $(INCS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(MAN_DIR)
	@$(CC) -c $(CFLAGS) $< $(INC_FLAG) -o $@

$(OBJ_DIR)/$(BON_DIR)/%.o : $(SRC_DIR)/$(MAN_DIR)/%.c $(INCS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(BON_DIR)
	@$(CC) -c $(CFLAGS) $< $(INC_FLAG) -o $@
