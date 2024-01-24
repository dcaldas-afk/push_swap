/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 18:31:03 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/12 16:01:34 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	try_stack(t_stack *stack)
{
	if (!stack)
		return (0);
	return (1);
}

void	free_stack(t_stack **stack_x)
{
	t_stack	*tmp;

	if (!stack_x)
		return ;
	while (*stack_x)
	{
		tmp = (*stack_x)->next;
		(*stack_x)->n = 0;
		free(*stack_x);
		*stack_x = tmp;
	}
}

t_stack	*last_element(t_stack *stack_x)
{
	if (!stack_x)
		return (NULL);
	while (stack_x->next)
		stack_x = stack_x->next;
	return (stack_x);
}

void	print_stack(t_stack *stack_x)
{
	while (stack_x)
	{
		printf("%d ", stack_x->n);
		stack_x = stack_x->next;
	}
	printf("\n");
}
