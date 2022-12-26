# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyun <hyeyun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 11:46:51 by hyeyukim          #+#    #+#              #
#    Updated: 2022/12/26 11:59:35 by hyeyun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

include config/variables_definition.mk

.PHONY : all
all : $(NAME)
$(NAME) : $(INCS) $(MAN_OBJ)
	make -C $(LIBFT_DIR) printf_gnl
	$(CC) $(CFLAGS) $(MAN_OBJ) $(LIB) $(LIBFLAGS) -o $@

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
