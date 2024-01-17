/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:26:31 by dcaldas-          #+#    #+#             */
/*   Updated: 2023/12/20 15:13:06 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct	s_stack
{
	int n;
	int index;
	struct  s_stack  *next;
	struct  s_stack *previous;
}				t_stack;

void    ft_putstr(char *str);
bool     small_stack(char *stack);
int     stack_len(char *stack);
int    try_stack(t_stack   *stack);
t_stack *last_element(t_stack *stack_x);
t_stack *first_element(t_stack *stack_x);
void    last_equals_first(t_stack **stack_x, t_stack **stack_y);
void    foward_lst(t_stack *stack_x, int *i);
void    backwards_lst(t_stack *stack_x, int *i);
void    free_stack(t_stack **stack_x);

// Operações
void    sa(t_stack **stack_a, int len);
void    sb(t_stack **stack_b, int len);
void    ss(t_stack **stack_a, t_stack **stack_b, int len);
void    pa(t_stack **stack_a, t_stack **stack_b, int len);
void    pb(t_stack **stack_a, t_stack **stack_b, int len);
void    ra(t_stack **stack_a, int len);
void    rb(t_stack **stack_b, int len);
void    rr(t_stack **stack_a, t_stack **stack_b, int len);


#endif