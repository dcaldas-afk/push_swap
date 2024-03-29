/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 01:40:36 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/25 00:30:57 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	rotate_type_ba(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*tmp;

	tmp = stack_b;
	i = rrarrb_quantity_a(stack_a, stack_b, stack_b->n);
	while (tmp)
	{
		if (i > rarb_quantity_a(stack_a, stack_b, tmp->n))
			i = rarb_quantity_a(stack_a, stack_b, tmp->n);
		if (i > rrarrb_quantity_a(stack_a, stack_b, tmp->n))
			i = rrarrb_quantity_a(stack_a, stack_b, tmp->n);
		if (i > rarrb_quantity_a(stack_a, stack_b, tmp->n))
			i = rarrb_quantity_a(stack_a, stack_b, tmp->n);
		if (i > rrarb_quantity_a(stack_a, stack_b, tmp->n))
			i = rrarb_quantity_a(stack_a, stack_b, tmp->n);
		tmp = tmp->next;
	}
	return (i);
}

int	rotate_type_ab(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	t_stack	*tmp;

	tmp = stack_a;
	i = rrarrb_quantity_b(stack_a, stack_b, stack_a->n);
	while (tmp)
	{
		if (i > rarb_quantity_b(stack_a, stack_b, tmp->n))
			i = rarb_quantity_b(stack_a, stack_b, tmp->n);
		if (i > rrarrb_quantity_b(stack_a, stack_b, tmp->n))
			i = rrarrb_quantity_b(stack_a, stack_b, tmp->n);
		if (i > rarrb_quantity_b(stack_a, stack_b, tmp->n))
			i = rarrb_quantity_b(stack_a, stack_b, tmp->n);
		if (i > rrarb_quantity_b(stack_a, stack_b, tmp->n))
			i = rrarb_quantity_b(stack_a, stack_b, tmp->n);
		tmp = tmp->next;
	}
	return (i);
}

void	sort_three(t_stack **stack_a)
{
	if (return_smallest(*stack_a) == (*stack_a)->n)
	{
		rra(stack_a, 0);
		sa(stack_a, 0);
	}
	else if (return_largest(*stack_a) == (*stack_a)->n)
	{
		ra(stack_a, 0);
		if (!is_sorted(*stack_a))
			sa(stack_a, 0);
	}
	else
	{
		if (retrieve_index(*stack_a, return_largest(*stack_a)) == 1)
			rra(stack_a, 0);
		else
			sa(stack_a, 0);
	}
}
