# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/27 00:30:11 by motaz             #+#    #+#              #
#    Updated: 2025/10/18 02:17:19 by moodeh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#program name
NAME = push_swap
CC = cc 
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
INC = -I includes -I libft
LINK = -L ./libft -lft 
SRC_DIR = src

SRC = src/main.c \
   src/helper/normalization.c \
   src/algos/radixsort.c \
   src/algos/sortstack.c \
   src/input/vald_input.c \
   src/error/error_handle.c \
   src/stack/stack_utils.c \
   src/stack/stack_utils2.c \
   src/oparation/ops_a.c \
   src/oparation/ops_b.c \
   src/oparation/ops_both.c

OBJ = $(SRC:.c=.o)

all : $(NAME)
$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LINK) -o $(NAME)

$(LIBFT) :
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
#inc to see what header the .c in 
clean :
	@$(RM) $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR) clean
fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)
re : fclean all

.PHONY:all clean fclean re 