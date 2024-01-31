# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 16:05:19 by dcaldas-          #+#    #+#              #
#    Updated: 2024/01/31 01:22:52 by dcaldas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
SRC_MAIN = src/push_swap
SRC_BONUS = src/bonus
NAME = push_swap
BONUS = checker
MAIN = src/push_swap/main.c \

AUX = src/push_swap/algorithm.c \
		src/push_swap/algorithm_2.c \
		src/push_swap/algorithm_3.c \
		src/push_swap/algorithm_4.c \
		src/push_swap/aux_functions_2.c \
		src/push_swap/aux_functions.c \
		src/push_swap/checks_2.c \
		src/push_swap/checks.c \
		src/push_swap/libft_functions.c \
		src/push_swap/libft_functions_2.c \
		src/push_swap/list_functions.c \
		src/push_swap/operations.c \
		src/push_swap/operations_2.c \
		src/push_swap/operations_3.c \
		src/push_swap/parser.c \
		src/push_swap/algorithm_5.c \

CHECK = src/bonus/checker.c \

EXTRA = src/bonus/bonus_exits.c \
		src/bonus/bonus_functions.c \

MAIN_OUT = $(MAIN:.c=.o)
BONUS_OUT = $(BONUS.c=.o)
AUX_OUT = $(AUX:.c=.o)

.c.o:
	$(CC) -c $< -o ${<:.c=.o}

$(NAME): $(MAIN_OUT) $(AUX_OUT)
		$(CC) $(FLAGS) -o $(NAME) $(MAIN) $(AUX)

$(BONUS): $(BONUS_OUT) $(AUX_OUT)
		$(CC) $(FLAGS) -o $(BONUS) $(CHECK) $(EXTRA) $(AUX)

all: $(NAME)

clean: 
	$(RM) $(RMFLAGS) $(MAIN_OUT) $(AUX_OUT) $(ALT_OUT) $(BONUS_OUT)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) $(BONUS)

re: fclean all

bonus: all $(BONUS)

.PHONY: all clean fclean re bonus