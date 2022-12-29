# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeyukim <hyeyukim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 11:46:51 by hyeyukim          #+#    #+#              #
#    Updated: 2022/12/30 07:39:45 by hyeyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

include config/variables_definition.mk

.PHONY : all
all : $(NAME)
$(NAME) : $(INCS) $(OBJ)
	$(RM) $(RMFLAGS) $(RM_OBJ)
	make -C $(LIBFT_DIR) printf_gnl
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFLAGS) -o $@

.PHONY : bonus
bonus :
	make WITH_BONUS=1 all

include config/compile_rules.mk

# basic rules
.PHONY : clean fclean re
clean :
	$(RM) $(RMFLAGS) $(OBJ_DIR)
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) clean
fclean : clean
	$(RM) $(RMFLAGS) $(NAME)
re :
	make fclean
	make all
