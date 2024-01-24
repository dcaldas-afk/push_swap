/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:45:05 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/24 01:27:54 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	apply_rarb(t_stack **stack_a, t_stack **stack_b, int c, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->n != c && index_after_pushing_to_b(*stack_b, c) > 0)
			rr(stack_a, stack_b, 0);
		while ((*stack_a)->n != c)
			ra(stack_a, 0);
		while (index_after_pushing_to_b(*stack_b, c) > 0)
			rb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b)->n != c && index_after_pushing_to_a(*stack_a, c) > 0)
			rr(stack_a, stack_b, 0);
		while ((*stack_b)->n != c)
			rb(stack_b, 0);
		while (index_after_pushing_to_a(*stack_a, c) > 0)
			ra(stack_a, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	apply_rrarrb(t_stack **stack_a, t_stack **stack_b, int c, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->n != c && index_after_pushing_to_b(*stack_b, c) > 0)
			rrr(stack_a, stack_b, 0);
		while ((*stack_a)->n != c)
			rra(stack_a, 0);
		while (index_after_pushing_to_b(*stack_b, c) > 0)
			rrb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while ((*stack_b)->n != c && index_after_pushing_to_a(*stack_a, c) > 0)
			rrr(stack_a, stack_b, 0);
		while ((*stack_b)->n != c)
			rrb(stack_b, 0);
		while (index_after_pushing_to_a(*stack_a, c) > 0)
			rra(stack_a, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	apply_rrarb(t_stack **stack_a, t_stack **stack_b, int c, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->n != c)
			rra(stack_a, 0);
		while (index_after_pushing_to_b(*stack_b, c) > 0)
			rb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while (index_after_pushing_to_a(*stack_a, c) > 0)
			rra(stack_a, 0);
		while ((*stack_b)->n != c)
			rb(stack_b, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}

int	apply_rarrb(t_stack **stack_a, t_stack **stack_b, int c, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->n != c)
			ra(stack_a, 0);
		while (index_after_pushing_to_b(*stack_b, c) > 0)
			rrb(stack_b, 0);
		pb(stack_a, stack_b, 0);
	}
	else
	{
		while (index_after_pushing_to_a(*stack_a, c) > 0)
			ra(stack_a, 0);
		while ((*stack_b)->n != c)
			rrb(stack_b, 0);
		pa(stack_a, stack_b, 0);
	}
	return (-1);
}
