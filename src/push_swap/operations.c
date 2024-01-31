/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:25:14 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/27 01:25:17 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	sa(t_stack **stack_a, int len)
{
	t_stack	*tmp;

	if (try_stack(*stack_a) == 0)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	if (len == 0)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int len)
{
	t_stack	*tmp;

	if (try_stack(*stack_b) == 0)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	if (len == 0)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int len)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	if (try_stack(*stack_a) == 0 || try_stack(*stack_b) == 0)
		return ;
	*stack_a = (*stack_a)->next;
	tmp_a->next = (*stack_a)->next;
	(*stack_a)->next = tmp_a;
	*stack_b = (*stack_b)->next;
	tmp_b->next = (*stack_b)->next;
	(*stack_b)->next = tmp_b;
	if (len == 0)
		write(1, "ss\n", 3);
}

void	pa(t_stack **stack_a, t_stack **stack_b, int len)
{
	t_stack	*tmp;

	if (try_stack(*stack_b) == 0)
		return ;
	tmp = *stack_a;
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_a)->next = tmp;
	if (len == 0)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int len)
{
	t_stack	*tmp;

	if (try_stack(*stack_a) == 0)
		return ;
	tmp = *stack_b;
	*stack_b = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_b)->next = tmp;
	if (len == 0)
		write(1, "pb\n", 3);
}
