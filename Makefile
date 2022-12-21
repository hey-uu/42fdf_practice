# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 11:46:51 by hyeyukim          #+#    #+#              #
#    Updated: 2022/12/20 19:41:34 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

include config/variables_definition.mk

.PHONY : all
all : $(NAME)
$(NAME) : $(MAN_OBJ)
	make -C $(LIB_DIR) printf_gnl
	$(CC) $(CFLAGS) $^ $(LIB) $(LIBFLAGS) -o $@

include config/compile_rules.mk

# basic rules
.PHONY : clean fclean re
clean :
	$(RM) $(RMFLAGS) $(OBJ_DIR)
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
re : 
	make fclean
	make all

