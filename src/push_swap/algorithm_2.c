/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:54:47 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/25 00:30:49 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

int	rarb_quantity_a(t_stack *stack_a, t_stack *stack_b, int n)
{
	int	i;

	i = index_after_pushing_to_a(stack_a, n);
	if (i < retrieve_index(stack_b, n))
		i = retrieve_index(stack_b, n);
	return (i);
}

int	rrarrb_quantity_a(t_stack *stack_a, t_stack *stack_b, int n)
{
	int	i;
	int	a;

	i = 0;
	a = stack_size(stack_b) - retrieve_index(stack_b, n);
	if (index_after_pushing_to_a(stack_a, n))
		i = stack_size(stack_a) - index_after_pushing_to_a(stack_a, n);
	if ((i < a) && retrieve_index(stack_b, n))
		i = stack_size(stack_b) - retrieve_index(stack_b, n);
	return (i);
}

int	rarrb_quantity_a(t_stack *stack_a, t_stack *stack_b, int n)
{
	int	i;

	i = 0;
	if (retrieve_index(stack_b, n))
		i = stack_size(stack_b) - retrieve_index(stack_b, n);
	i = index_after_pushing_to_a(stack_a, n) + i;
	return (i);
}

int	rrarb_quantity_a(t_stack *stack_a, t_stack *stack_b, int n)
{
	int	i;

	i = 0;
	if (index_after_pushing_to_a(stack_a, n))
		i = stack_size(stack_a) - index_after_pushing_to_a(stack_a, n);
	i = retrieve_index(stack_b, n) + i;
	return (i);
}
