/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:41:27 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/26 23:40:33 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	ra(t_stack **stack_a, int len)
{
	t_stack	*tmp;

	tmp = *stack_a;
	*stack_a = last_element(*stack_a);
	(*stack_a)->next = tmp;
	*stack_a = tmp->next;
	tmp->next = NULL;
	if (len == 0)
		write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b, int len)
{
	t_stack	*tmp;

	tmp = *stack_b;
	*stack_b = last_element(*stack_b);
	(*stack_b)->next = tmp;
	*stack_b = tmp->next;
	tmp->next = NULL;
	if (len == 0)
		write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b, int len)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	*stack_a = last_element(*stack_a);
	(*stack_a)->next = tmp_a;
	*stack_a = tmp_a->next;
	tmp_a->next = NULL;
	*stack_b = last_element(*stack_b);
	(*stack_b)->next = tmp_b;
	*stack_b = tmp_b->next;
	tmp_b->next = NULL;
	if (len == 0)
		write(1, "rr\n", 3);
}
