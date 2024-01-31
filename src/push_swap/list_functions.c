/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcaldas- <dcaldas-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:46:01 by dcaldas-          #+#    #+#             */
/*   Updated: 2024/01/25 01:03:11 by dcaldas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lib/push_swap.h"

t_stack	*create_stack(int arg)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		error_exit();
	stack->n = arg;
	stack->next = NULL;
	return (stack);
}

void	free_str(char **lst)
{
	char	*n1;

	if (!lst)
		return ;
	while (*lst)
	{
		n1 = *lst;
		lst++;
		free(n1);
	}
	*lst = NULL;
}

int	retrieve_index(t_stack *stack_x, int value)
{
	t_stack	*tmp;
	int		i;

	tmp = stack_x;
	i = 0;
	while (tmp->n != value)
	{
		i++;
		tmp = tmp->next;
	}
	tmp->index = 0;
	return (i);
}

int	index_after_pushing_to_b(t_stack *stack_b, int num)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	if (num > stack_b->n && num < last_element(stack_b)->n)
		i = 0;
	else if (num > return_largest(stack_b) || num < return_smallest(stack_b))
		i = retrieve_index(stack_b, return_largest(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->n < num || tmp->n > num)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			i++;
		}
	}
	return (i);
}

int	index_after_pushing_to_a(t_stack *stack_a, int num)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	if (num < stack_a->n && num > last_element(stack_a)->n)
		i = 0;
	else if (num > return_largest(stack_a) || num < return_smallest(stack_a))
		i = retrieve_index(stack_a, return_smallest(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->n > num || tmp->n < num)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			i++;
		}
	}
	return (i);
}
