/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 00:26:44 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/27 03:49:29 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	rra(t_stack **stack_a, int len)
{
	t_stack	*tmp;
	t_stack	*prev;

	tmp = *stack_a;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stack_a;
	*stack_a = tmp;
	if (len == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int len)
{
	t_stack	*tmp;
	t_stack	*prev;

	tmp = *stack_b;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stack_b;
	*stack_b = tmp;
	if (len == 0)
		write(1, "rrb\n", 4);
}

void	rotate_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*prev;

	tmp = *stack;
	prev = NULL;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int len)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	if (len == 0)
		write(1, "rrr\n", 4);
}
