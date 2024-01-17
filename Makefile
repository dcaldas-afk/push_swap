# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 16:05:19 by dcaldas-          #+#    #+#              #
#    Updated: 2024/01/12 18:21:18 by dcaldas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILE = cc -Wall -Wextra -Werror
RM = rm -rf
SRC_MAIN = src/push_swap
NAME = push_swap
MAIN = src/push_swap/main.c \

AUX = src/push_swap/algorithm.c \
		src/push_swap/algorithm_2.c \
		src/push_swap/algorithm_3.c \
		src/push_swap/algorithm_4.c \
		src/push_swap/algorithm_5.c \
		src/push_swap/algorithm.c \
		src/push_swap/aux_functions_2.c \
		src/push_swap/aux_functions.c \
		src/push_swap/checks_2.c \
		src/push_swap/checks.c \
		src/push_swap/libft_functions.c \
		src/push_swap/list_functions.c \
		src/push_swap/operations_2.c \
		src/push_swap/operations.c \
		src/push_swap/parser.c \

MAIN_OUT = $(MAIN:.c=.o)
AUX_OUT = $(AUX:.c=.o)

.c.o:
	@cc -c $< -o ${<:.c=.o}

$(NAME): $(MAIN_OUT) $(AUX_OUT)
		$(COMPILE) -o $(NAME) $(MAIN) $(AUX)

all: $(NAME)

clean: 
	$(RM) $(MAIN_OUT) $(AUX_OUT)

fclean: clean
	$(RM) $(NAME) 

re: fclean all

.PHONY: all clean fclean re