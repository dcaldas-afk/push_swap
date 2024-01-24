/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:01:58 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/12 16:01:31 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void    change_last_value(t_stack **stack_x, t_stack *tmp, void *value)
{
    int i;

    i = 0;
    tmp = *stack_x;
    while ((*stack_x)->next)
    {
        i++;
        *stack_x = (*stack_x)->next;
    }
    (*stack_x)->next = tmp;
    while (i > 1)
    {
        i--;
        tmp = tmp->next;
    }
    tmp->next = value;
}

int	stack_size(t_stack *stack_x)
{
	int	i;

	i = 0;
	while (stack_x)
	{
		i++;
		stack_x = stack_x->next;
	}
	return (i);
}

int	return_largest(t_stack *stack_x)
{
	int	max;

	max = stack_x->n;
	while (stack_x)
	{
		if (stack_x->n > max)
			max = stack_x->n;
		stack_x = stack_x->next;
	}
	return (max);
}

int	return_smallest(t_stack *stack_x)
{
	int	min;

	min = stack_x->n;
	while (stack_x)
	{
		if (stack_x->n < min)
			min = stack_x->n;
		stack_x = stack_x->next;
	}
	return (min);
}

void	error_exit(void)
{
	ft_putstr("Error\n");
	exit(1);
}
